// Auhor : Prazwal Chhabra

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <sys/utsname.h>
#include <fcntl.h>
#include <pwd.h>
#include "HeaderFile.h"

/*
strkok syscall:
A sequence of calls to strtok() that operate on the same string maintains a pointer 
to determine the point from  which  to  start searching  for the next token.  

The first call to strtok() sets this pointer to point to the first byte of the string.  
The start of the next token is determined by scanning forward for the next nondelimiter byte in str.  
If such a byte is found, it is taken as the start of the  next  token.  
If no such byte is found, then there are no more tokens, and strtok() returns NULL.
Usage :- On  the  first  call to strtok_r(), str should point to the string to be parsed,
and the value of saveptr is ignored.  In subsequent calls, str should be NULL, 
and saveptr should be unchanged since the previous call.
*/

char* readLine()
{
    //////////////////////// Implement CTRL-D////////////////////////////////
    
	char *line = NULL;
    const char delim[] = ";";
    ssize_t bufsize = 1024; // have getline allocate a buffer for us this is jus an initialisation

    //CTRL-D if getline encounters EOF on which it returns -1
    // getline sets the buffer size for us and we get ';' separaed strings

    if(getline(&line, &bufsize, stdin)==-1){
        printf("\n");
        exit(0);
    }

    /////////////////// Input other than CTRL+D ///////////////////////////

	return line;
}


char** splitLine(char* line){
    int buffer_size = TOKEN_BUFFER_SIZE;
	int pos = 0;
	char **token_storage = malloc( buffer_size * sizeof(char*));
	char *token;
	char *saveptr1;

	if (token_storage == NULL) {
		fprintf(stderr, "Memory Allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok_r(line,TOKEN_DELIM,&saveptr1);
	
	for (pos=0;token != NULL;pos++) 
	{
		token_storage[pos] = token;

		if (pos >= buffer_size) 
		{
			buffer_size += TOKEN_BUFFER_SIZE;
			token_storage = realloc(token_storage,  buffer_size * sizeof(char*));
			if (token_storage == NULL) {
				fprintf(stderr, "Memory Allocation error\n");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok_r(NULL, TOKEN_DELIM, &saveptr1);
	}

	token_storage[pos] = NULL;
	return token_storage;
}


// Used to separate commands
char** splitCommand(char* line)
{
	int buffer_size = TOKEN_BUFFER_SIZE;
	char** token_storage = malloc( buffer_size * sizeof(char*));
	int pos=0;
	char* token;
	char* saveptr1;

	if (token_storage == NULL) {
		fprintf(stderr, "Memory Allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok_r(line,CMD_DELIM,&saveptr1);

	for (pos=0;token != NULL;pos++) 
	{
		token_storage[pos] = token;

		if (pos >= buffer_size) 
		{
			buffer_size += TOKEN_BUFFER_SIZE;
			token_storage = realloc(token_storage,  buffer_size * sizeof(char*));
			if (token_storage == NULL) {
				fprintf(stderr, "Memory Allocation error\n");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok_r(NULL, CMD_DELIM, &saveptr1);
	}

	token_storage[pos] = NULL;
	return token_storage;
}