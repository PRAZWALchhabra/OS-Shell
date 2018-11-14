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


void cd(char** args)
{
 if (args[1] == NULL || strcmp(args[1],"~")==0){
     chdir(home);
  } 
  else if (chdir(args[1]) != 0){
      perror("cd");
  }
  return;
}