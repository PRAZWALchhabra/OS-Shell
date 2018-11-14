// Auhor : Prazwal Chhabra

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <sys/utsname.h>
#include <string.h>
#include <fcntl.h>
#include <pwd.h>
#include "HeaderFile.h"

int freqbg=0;
int sigpid;
char cntt[100];

// All commands built in this project
char* commands[] = { "cd","pwd","echo","ls","pinfo","remindme","clock","setenv","unsetenv","kjob","jobs","fg","overkill","bg"};
char* nonForkCommands[] = { "cd","pinfo" };


//It’s an array of FUNCTION POINTERS 
void (*command[]) (char **) = {
	&cd,&pwd,&echo,&ls,&pinfo,&remindme,&clockt,&setvar,&unsetvar,&kjob_cmd,&jobs_cmd,&fg_cmd,&killAllBG,&bg_cmd
};


// return Number of IMPLEMENTED functions
int num_builtins() {
	return sizeof(commands) / sizeof(char *);
}


// return Number of non Forkfunctions
int numNonFork() {
	return sizeof(nonForkCommands) / sizeof(char *);
}

void  SIGINT_handler(int signal_num)
{
	if(sigpid){
		if(kill(sigpid,SIGINT)!=0)
		{			
			fprintf(stderr,"Error:Can't kill the process");
		}
	}
	else{
		signal(signal_num, SIG_IGN); // The signal is ignored.
		printf("\n");
		print_prompt(home,sizeof(home));
		fflush(stdout); // Flushes the output
		signal(signal_num, SIGINT_handler); //Again it checks for signal
	}
}

void SIGTSTP_handler(int signal_num)
{
	if (sigpid==0){
		signal(signal_num, SIG_IGN); // The signal is ignored.
		printf("\n");
		print_prompt(home,sizeof(home));
		fflush(stdout); // Flushes the output
		signal(signal_num, SIGTSTP_handler); //Again it checks for signal
	}
	else{
		if(kill(sigpid,SIGTSTP)==0)
		{
			bg_process[freqbg].pid = sigpid;
			bg_process[freqbg].command = cntt;
			bg_process[freqbg].jobid = freqbg;
			bg_process[freqbg].flag=-2;
			printf("\n[%d] Stopped %s [%d]\n",freqbg,cntt,sigpid);
			freqbg++;
			sigpid=0;
			signal(signal_num, SIG_IGN); // The signal is ignored.
		 	start_shell();
			// fflush(stdout); // Flushes the output
		}
	}
}


// This function adds a new background process with flag 0
void back_process(int pid,char * cmd,int flag)
{
	// Check whether all processes have been killed or not
	int allKilled=1;
	for (int i=0;i<freqbg;i++){
		if (bg_process[i].flag!=-3){
			allKilled=0;
		}
	}

	if (allKilled){
		freqbg=0;
	}

	// Append the background process
	bg_process[freqbg].pid = pid;
	bg_process[freqbg].command = cmd;
	bg_process[freqbg].jobid = freqbg;
	bg_process[freqbg].flag=flag;
	printf("Process %s with pid %d started in background\n",cmd,pid);
	printf("[%d] %d\n",bg_process[freqbg].jobid,pid);
	freqbg++;
}

// Checks if any of the background process has been terminated ? If yes then prints the message
void background_fxn()
{
	pid_t wpid;
	int status, i;
	char pidnumber[1000];

	while((wpid = waitpid(-1, &status, WNOHANG)) > 0)  
	{
		if(WIFEXITED(status) == 0 || WIFSIGNALED(status) == 0)
		{
			for(i = 0; i <freqbg; i++)
			{
				// Checks for the child processes which have changed there status.
				if(bg_process[i].pid == wpid && bg_process[i].flag==0)
				{
					printf("[%d]+	Done\t\t\t%s with pid %d\n",bg_process[i].jobid,  bg_process[i].command, wpid);
					bg_process[i].flag=-3;
					// print_prompt();
				}
				else if(bg_process[i].pid == wpid && bg_process[i].flag)
				{
					printf("\n\033[0;31mReminder:\033[0m %s\n",bg_process[i].command);
					bg_process[i].flag=-3;
					// print_prompt();
				}
			}
		}
	}

	return;

}

void sysCommand(char** args)
{
	pid_t pid1, pid2;
	int status;
	int BG_FLAG=0;

	for(int i=0;args[i]!=NULL;i++)
	{
		if(strcmp(args[i],"&") == 0)
		{	
			args[i] = NULL;
			BG_FLAG = 1;
			break;
		}
	}

	pid1 = fork();
	if (pid1 < 0)
	{
		perror("Error Forking\n");
	}
	else if (pid1 == 0) // Child process
	{
		if (execvp(args[0], args) == -1)
		{
			perror("Command not Found");
		}
		else{
			exit(EXIT_SUCCESS);
		}
	}
	else // Parent process
	{
		if(BG_FLAG == 1)
		{
			back_process(pid1,args[0],0);
		}
		else
		{
			sigpid = pid1;
			strcpy(cntt,args[0]);
			do {
				pid2 = waitpid(pid1, &status, WUNTRACED);
			} while (!WIFEXITED(status) && !WIFSIGNALED(status));
			sigpid = 0;
		}
	}
}

int executeFunc(char **args)
{
	if (args[0] == NULL) {
        return 1;
    }
	
	int redir=0,pipe=0,a;

	for (a=0;args[a] != NULL;a++){
		if (strcmp(args[a],"|")==0){
			pipe=1;
		}
		if((strcmp(args[a],">") == 0) || (strcmp(args[a],"<") == 0) || (strcmp(args[a],">>") == 0) ){
			redir=1;
		}
	}

	if (pipe){
		pipe_cmd(args);
		return 1;
	}
	
	if (redir){
		redirect_cmd(args);
		return 1;
	}


	for (int i = 0; i < num_builtins(); i++) 
	{
		if (strcmp(args[0], commands[i])==0) 
		{
            //If command has been implemented

			(*command[i])(args);
			return 1;
		}
		else if(strcmp(args[0], "quit")==0)
		{
			exit(EXIT_SUCCESS);
		}
	}
			sysCommand(args);
			return 1;
}


void jobs_cmd(char **args)
{
  for (int i=0;i<freqbg;i++){
	  if (bg_process[i].flag==-2){
		printf("[%d] ", i );
		printf("Stopped %s[%d]", (bg_process[i]).command,bg_process[i].pid);
		printf("\n");
	  }
	  else if (bg_process[i].flag==0){
		printf("[%d] ", i );
		printf("Running %s[%d]", (bg_process[i]).command,bg_process[i].pid);
		printf("\n");
	  }
  }
  return;
}

void fg_cmd(char **args)
{
	if(args[1]==NULL){
		printf("Error : Invalid Command\n");
		return;
	}
	
	pid_t wpid;
	int status;
	int procno =atoi(args[1]);

	if(procno >= freqbg || bg_process[procno].flag==-3){
		printf("ERROR: NO Background Process\n");
		return;
	}

	// signal 18 resumes a background process
	if (kill((bg_process[procno].pid),SIGCONT)==-1){
		printf("Error!!\n");
		return;
	}

	bg_process[procno].flag=-3;

	do
	{
		wpid=waitpid(bg_process[procno].pid,&status,WUNTRACED);
	}while(!WIFEXITED(status) && !WIFSIGNALED(status) && !WIFSTOPPED(status));
	
	return;
}

void kjob_cmd(char **args)
{
	// Error Handling
	if (args[1]==NULL || args[2]==NULL){
	printf("Error : Invalid Command\n");
	}

	int signo = atoi (args[2]);
	int procno =atoi  (args[1]);

	//Fix segmentation fault
	if(procno > freqbg || bg_process[procno].flag==-3){
		printf("Error : No Such Process.\n" );
		return;
	}

	// Main Code
	int pid = (bg_process[procno]).pid;
	bg_process[procno].flag=-3;

	if(kill(pid, signo)!=0)
	{
		printf("Error: Invalid Command!");
	}
	
	return;
}

void killAllBG(char **args)
{
  for(int i=0;i<freqbg;i++)
  {
    if(bg_process[i].flag!=-3)
    {
      kill((bg_process[i]).pid,9);
      bg_process[i].flag=-3;
    }
  }
}

void bg_cmd(char **args)
{
	if(args[1]==NULL){
		printf("Invalid Command\n");
		return;
	}

	int jbid=atoi(args[1]);
	
	if(bg_process[jbid].flag != 0){
		if(kill(bg_process[jbid].pid,18)==0){
			bg_process[jbid].flag = 0;
		}
	}
	else{
		printf("Error: \n");
	}
}