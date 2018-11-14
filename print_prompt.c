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

void print_prompt(char* home,int PATH_LEN_HOME){
    
    // Get Name Of the Logged In user
    char username[LOGIN_NAME_MAX];
    getlogin_r(username, LOGIN_NAME_MAX);
    printf(COLOR_CYAN "<%s"  COLOR_RESET,username);
	printf(COLOR_YELLOW "@"  COLOR_RESET);

    // Get Machine Name
    char hostname[HOST_NAME_MAX];
    gethostname(hostname, HOST_NAME_MAX);
    printf(COLOR_CYAN "%s:" COLOR_RESET,hostname);

    // Get present working directory
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    int PATH_LEN_CWD=strlen(cwd);

    int flag=0,i=0;

	// DEFINE RELATIVE PATH
    if (PATH_LEN_CWD>=PATH_LEN_HOME){
		if (strncmp(home,cwd,PATH_LEN_HOME)==0){
				while(cwd[i+PATH_LEN_HOME] != '\0')
			{
				cwd[i] = cwd[i+PATH_LEN_HOME];
				i++;
			}
			cwd[i] = '\0';
		}
		else{
			flag=1;
		}
		printf(COLOR_CYAN "~%s> " COLOR_RESET,cwd);
    }
	else if (flag || PATH_LEN_CWD<PATH_LEN_HOME){
		printf(COLOR_CYAN "%s> " COLOR_RESET,cwd);
	}

}