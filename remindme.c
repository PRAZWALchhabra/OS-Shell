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

char* remindmeComm[]={"sleep","20"};

void remindme(char **args)
{
	pid_t pid,wpid;
	pid=fork();
	int status;

	if(pid<0)
	{
		printf("\033[0;32mCannot Create Child Process\033[0m\n");
	}

	else if(pid==0)
	{
		strcpy(remindmeComm[1],args[1]);
		if(execvp(remindmeComm[0],remindmeComm)==-1)
		{
			printf("%s: \033[0;31mcommand not found\033[0m\n",args[0]);
		}
	}

	else
	{
		int j=3;
		char message[10000];
		strcpy(message,args[2]);
		while(args[j]!=NULL)
		{
			strcat(message,args[j++]);
		}
		back_process(pid,message,1);
	}
	return;
}
