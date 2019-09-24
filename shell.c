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


void start_shell(){

    // Get pathname of home directory and length of tha path , home here is a global variable
    getcwd(home, sizeof(home));
    int PATH_LEN_HOME=strlen(home);


    while(1)
	{
		keeprunning=1;
        print_prompt(home,PATH_LEN_HOME);

        // Read line from STDIN 
        char* tmp=readLine();

        if (feof(stdin)) 
		{
			printf("Ctrl+ D\n");
			fflush(stdout);
			fflush(stderr);
			exit(0);
		}
        
		char **args = splitCommand(tmp);

        // Now Split commands from line read

		for (int i=0,j=0;args[i]!=NULL;i++)
		{
			char **args1 = splitLine(args[i]);
			j=executeFunc(args1);
			if(j==-100){
				exit(0);
			}
		}
		background_fxn();
	}
}

int main(){
    if (signal(SIGINT, SIGINT_handler) == SIG_ERR)
	{
		printf("SIGINT install error\n");
		exit(1);
	}

	signal(SIGTSTP,SIGTSTP_handler);
    // Start The Shell
    start_shell();
    return 0;
}
