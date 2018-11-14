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

void pinfo(char ** args)
{
	char* str = (char *)malloc(1111 * sizeof(char));
	char exec_path[1111];
	char ** args1, ** args2;
	int pid;
	// Set the PID of the PROCESS
    if(args[1]!=NULL)
    {
        // ASCII TO INTEGER
		pid = atoi(args[1]);

        // kill with signal=0 performs error checking
        
		if(pid==0 || kill(pid,0))
		{
			perror("Invalid PID");
			return;
		}
	}
	else
    {
		pid = getpid();
    }

	printf("pid -- %d\n", pid);
	sprintf(str ,"/proc/%d/status",pid);
    FILE* file = fopen(str, "r");
    char line[256];
    int l = 0;
    while (fgets(line, sizeof(line), file)) {
        l++;
        if(l == 3 )
        {
            // Process Status
            printf("Process %s",line);
        }
        else if (l==18)
        {
        // because we hace to output virtual memory assigned at the start of the process            
            printf("%s",line);
            break;
        }
    }

    fclose(file);

    // executable path
	sprintf(str ,"/proc/%d/exe",pid);
	readlink(str , exec_path , sizeof(exec_path));
	printf("Executable Path -- %s\n", exec_path);
}