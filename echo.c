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

void echo(char **args)
{
	if(args[1] == NULL)
	{
		printf("\n");
		return;
	}
	int i=1;
	if(args[i][0] == '\"' || args[i][0] == '\'') 
	{
		int x = strlen(args[i]); 
		if(args[i][x-1] == '\"' || args[i][x-1] == '\'')
			for(int j=1;j<x-1;j++)
				printf("%c",args[i][j]);
		else
			for(int j=1;j<x;j++)
				printf("%c",args[i][j]);
		printf(" "); // space 

		i++;

		while(args[i]!=NULL)
		{
			int x = strlen(args[i]);
			if(args[i][x-1] == '\"' || args[i][x-1] == '\'')
				for(int j=0;j<x-1;j++)
					printf("%c",args[i][j]);
			else
				printf("%s ",args[i]);
			i++;
		}
	}
	
	else
	{
		while(args[i]!=NULL)
		{
			if(args[i][0]=='$') 
			{
				const char* str=getenv(args[i]+1);
				if(str != NULL)
					printf("%s",str);
				else
					printf(" ");
			}
			else 
				printf("%s ",args[i]);
			i++;
		}
	}
	printf("\n");
	return;
}
