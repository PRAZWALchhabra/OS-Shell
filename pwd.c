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

void pwd(){
	char cwd[FILENAME_MAX];
	getcwd(cwd,sizeof(cwd));
	printf("%s\n",cwd);
    return;
}