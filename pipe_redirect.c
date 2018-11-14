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
#include <limits.h>
#include "HeaderFile.h"

char **redirect (char ** args){

	int fd1, fd2, fd3;
	char in[101],out[101],outdir[101];
	int flag1=0,flag2=0,flag3=0;

	//Find whether there is a string for input and output

	char * q = args[0];
	int c=0;

	while(q!=NULL){


		if(strncmp(q,">>",2)==0){
			strcpy(outdir,args[c+1]);
			flag3=1;
			args[c]=NULL;
		}

		if (strncmp(q,"<",1)==0){
			args[c]=NULL;
			flag1=1;
			strcpy(in,args[c+1]);
		}

		if((strncmp(q,">",1)==0)){
			args[c]=NULL;
			flag2=1;
			strcpy(out,args[c+1]);
		}
		c++;
		q = args[c];
	}


	if(flag1==0 && flag2==0 && flag3==0)
		return args;
	//If < was found in string inputted by user

	if(flag1){

		fd1 = open(in, O_RDONLY,0);

		//if error
		if(fd1 < 0){
			perror("Could not open the input file");
			exit(0);
		}

		dup2(fd1,0);
		close(fd1);
	}

	if(flag2){
		fd2 = open (out, O_WRONLY | O_CREAT, 0666);
		if(fd2<0){
			perror("Could not open the output file");
			exit(0);
		}

		dup2(fd2,1);
		close(fd2);
	}

	if(flag3){
		fd3 = open (outdir, O_WRONLY | O_CREAT | O_APPEND , 0666);
		dup2(fd3,1);
		close(fd3);
	}

	return args;
}


void redirect_cmd(char** args){

	char inptfile[100],outfile[100];
	int inp=0,outp=0,appendredir=0;
	char *com[100];
	int hasredir=0,redirind=0;

	// Check which type of redirection is there in this Command
	for (int i=0;args[i]!=NULL;i++){
		if (strcmp(args[i],"<")==0){
			inp=1;
		}
		else if (strcmp(args[i],">")==0){
			outp=1;
		}
		else if (strcmp(args[i],">>")==0){
			appendredir=1;
		}
	}

	for(int i=0;args[i]!=NULL;i++)
	{
		if(strcmp(args[i],">")==0 || strcmp(args[i],">>")==0)
		{
			hasredir=i+1;
			if(args[i+1]!=NULL){
				strcpy(outfile,args[i+1]);
				// break;
			}
		}
		else if(strcmp(args[i],"<")==0)
		{
			hasredir=i+1;
			if(args[i+1]!=NULL){
				strcpy(inptfile,args[i+1]);
				// break;
			}
		}
		if(!hasredir)
			com[redirind++]=args[i];
	}

	if(hasredir!=0 && args[hasredir]==NULL){
		printf("Invalid Command\n");
		return;
	}

	com[redirind]=NULL;

	if(inp==1)
	{
		int red=dup(0);
		int input = open(inptfile,O_RDONLY);
		if (input==-1){
			printf("Error : File Doesn't Exists!!\n");
			return;
		}

		dup2(input,0);
		close(input);

		int redo,output;
		redo=dup(1);

		if (outp){
				output = open(outfile,O_WRONLY | O_CREAT | O_TRUNC, 0666);
				dup2(output,1);
				close(output);
		}
		

		if(appendredir){
			output = open(outfile,O_WRONLY | O_CREAT | O_APPEND, 0666);
			dup2(output,1);
			close(output);
		}

		int status,pid = fork();
		if (pid<0){
			printf ("Error Forking");
			return;
		}

		pid_t wpid;
		if(pid){
			do {
				wpid = waitpid(pid, &status, WUNTRACED);
			} while (!WIFEXITED(status) && !WIFSIGNALED(status));

		}
		else
		{
			execvp(com[0],com);
		}

		if (hasredir)
		{
			dup2(red,0);
			close(red);
			dup2(redo,1);
			close(redo);
		}
	}
	else
	{
		int ot,o=dup(1);

		if(!outp){
			ot = open(outfile,O_WRONLY | O_CREAT | O_APPEND, 0666);
		}
		else{
			ot = open(outfile,O_WRONLY | O_CREAT | O_TRUNC, 0666);
		}

		dup2(ot,1);
		close(ot);

		int pid = fork();
		if (pid<0){
			printf ("Error Forking");
			return;
		}

		int status;
		pid_t wpid;
		if(pid){
			do {
				wpid = waitpid(pid, &status, WUNTRACED);
			} while (!WIFEXITED(status) && !WIFSIGNALED(status));
			dup2(o,1);
			close(o);
		}
		else
		{
			execvp(com[0],com);
			dup2(o,1);
			close(o);
		}
	}
}

void pipe_cmd(char ** args)
{

	int status;
	int p[2];

	//pipe(p);
	int q[2];

	int i=0;
	int j =0;
	int k =0;
	int flag1;
	int end=0;
	int fd1, fd2, fd3;
	char *sym[100];

	int m = 0;
	int count = 0;

	char * r = args[0];
	pid_t pid;
	//Count the no. of command line arguments in piping
	while(r!=NULL){
		if (strncmp(args[m],"|",1)==0){
			count++;
		}
		m++;
		r = args[m];
	}
	count++;

	int last =count -1 ;
	//  printf("%d\n",count );

	//The main loop for piping
	while(args[j]!=NULL &&  end!=1){

		k = 0;

		char * d = args[j];

		while((strncmp(d,"|",1)!=0)){
			//if(strncmp(d,"|",1)!=0)
			sym[k]=d;
			//printf("%s\n",sym[k] );
			j++;
			d = args[j];

			if(d == NULL){
				end = 1;
				k++;
				break;
			}
			k++;
		}

		sym[k] = NULL;
		j++;

		//char ** sym1;
		//sym1 = redirect(sym);

		if (i%2 == 0)
			pipe(q);
		else
			pipe(p);

		pid = fork();

		//Error on being unable to fork the process
		if(pid < 0)
			perror("Unable to fork the process");


		//In the child process
		if (pid == 0){

			char ** sym1;
			sym1 = redirect(sym);


			if (i==0){
				dup2(q[1],1);
				//  close(q[0]);
			}
			else if (i==last){
				if(count%2==0){
					dup2(q[0],0);
					//close(q[1]);
				}
				else{
					dup2(p[0],0);
					//close(p[1]);
				}
			}

			else{
				if(i%2==0){
					dup2(p[0],0);
					dup2(q[1],1);
				}
				else{
					dup2(q[0],0);
					dup2(p[1],1);
				}
			}
			if (execvp(sym1[0],sym1)==-1){
				kill(getpid(),SIGTERM);
			}
		}

		//In the parent process to close all file descriptors;


		if(i==0){
			close(q[1]);
		}

		else if(i==last){
			if(i%2==0){
				close(q[0]);
			}
			else{
				close(p[0]);
			}
		}

		else{
			if(i%2==0){
				close(p[0]);
				close(q[1]);
			}
			else{
				close(q[0]);
				close(p[1]);
			}
		}

		waitpid(pid,NULL,0);
		i++;


	}

}
