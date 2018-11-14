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

void setvar(char ** args){
	if(args[1] == NULL){
        printf ("Error : Enter A Variable and Value To Set\n");
	}
    else if (args[3] != NULL){
        printf ("Error : Set 1 varibale at a time\n");
    }

    if (args[2] != NULL)
    {
        setenv(args[1],args[2],1);
    }
    else
    {
        setenv(args[1],"",1);
    }
}