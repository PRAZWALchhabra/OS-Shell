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

void unsetvar(char** args)
{
	if(args[1] == NULL){
		printf ("Error : Enter Variable To Unset\n");
	}
    else if (args[2] != NULL){
        printf ("Error : Unset 1 varibale at a time\n");
    }

	if (unsetenv(args[1])!=0){
		perror("Error:");
    }
}