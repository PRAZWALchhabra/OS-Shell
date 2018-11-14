// Auhor : Prazwal Chhabra

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include<sys/stat.h>
#include <unistd.h>
#include <signal.h>
#include <sys/utsname.h>
#include <string.h>
#include <fcntl.h>
#include <pwd.h>
#include <grp.h>
#include <limits.h>
#include <dirent.h>
#include<time.h>
#include "HeaderFile.h"

/// Check whether argument passed is a file or a directory ///

int isDirectory(const char *path)
{
    struct stat stats;
    stat(path, &stats);
    // Check for directory existence
    if (S_ISDIR(stats.st_mode))
        return 1;
    return 0;
}

int isFile(const char *path)
{
    struct stat stats;
    stat(path, &stats);
    // Check for file existence
    if (S_ISREG(stats.st_mode))
        return 1;
    return 0;
}
//////////////////////////////// Useful with -l flag ////////////////////////////////////
void infoFile(char* file)
{
    struct stat fileStat;
    if(stat(file,&fileStat) < 0)  
    {
        // printf("\n1\n");
        return;
    }
    printf( (S_ISDIR(fileStat.st_mode)) ? "d" : "-");
    printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
    printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
    printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXOTH) ? "x" : "-");

    printf(" ");

    // printf("Number of Links: \t%d\n",fileStat.st_nlink);
    // printf("File inode: \t\t%d\n",fileStat.st_ino);

    // Owner and Group of file/directory
    struct passwd *pw = getpwuid(fileStat.st_uid);
    struct group  *gr = getgrgid(fileStat.st_gid);
    // Name of file/directory owner or creator
    printf( pw->pw_name ? "%s" : "-",pw->pw_name);
    printf(" ");
    // Name of file/directory group
    printf( gr->gr_name ? "%s" : "-",gr->gr_name);


    // Size of file or directory
    printf(" %10ld ",fileStat.st_size);


    char date[10];
    strftime(date, 20, "%d-%m-%y", localtime(&(fileStat.st_ctime)));
    printf(" %s ",date);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
int exflag=0;
void lsal(char** args)
{
    char buf[1001];
    
    for(int i=2+exflag;args[i]!=NULL;i++)
    {
        if ( isDirectory(args[i]) && (isFile(args[i]))==0 )
        {
            DIR* p;
            struct dirent *d;
            p=opendir(args[i]);
            while(d=readdir(p))
            {
                // concatenation done to get full name earlier was giving error
                sprintf(buf, "%s/%s", args[i], d->d_name);
                infoFile(buf);
                printf("%s\n",d->d_name);
            }
        }
        else if (isFile(args[i]))
        {
            infoFile(args[i]);
            printf("%s ",args[i]);
        }
    }

    // When only ls -al is given

    if (args[2+exflag]==NULL){
        int i=0;
        char cwd[FILENAME_MAX];
        getcwd(cwd,sizeof(cwd));
        if ( isDirectory(cwd) )
        {
            DIR* p;
            struct dirent *d;
            p=opendir(cwd);
            while(d=readdir(p))
            {
                // concatenation done to get full name earlier was giving error
                sprintf(buf, "%s/%s", cwd, d->d_name);
                infoFile(buf);
                printf("%s\n",d->d_name);
            }
        }
    }
    exflag=0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////

void lsl(char** args)
{
   char buf[1001];

//    if (strcmp(args[2],"-a")==0)
//    {
//        exflag=1;
//        lsal(args);
//        return;
//    }
   
   for(int i=2;args[i]!=NULL;i++)
    {
        if ( isDirectory(args[i]) )
        {
            DIR* p;
            struct dirent *d;
            p=opendir(args[i]);
            while(d=readdir(p))
            {
                if (d->d_name[0]=='.')
                {continue;}
                // concatenation done to get full name earlier was giving error
                sprintf(buf, "%s/%s", args[i], d->d_name);
                infoFile(buf);
                printf("%s ",d->d_name);
            }
        }
        else if (isFile(args[i]))
        {
            infoFile(args[i]);
            printf("%s ",args[i]);
        }
    }

    // when only ls -l is he command
    if (args[2]==NULL)
    {
        int i=0;
        char cwd[FILENAME_MAX];
        getcwd(cwd,sizeof(cwd));
        if ( isDirectory(cwd) )
        {
            DIR* p;
            struct dirent *d;
            p=opendir(cwd);
            while(d=readdir(p))
            {
                // if hidden , then don't display
                if (d->d_name[0]=='.')
                {continue;}

                // concatenation done to get full name earlier was giving error
                sprintf(buf, "%s/%s", cwd, d->d_name);
                infoFile(buf);
                printf("%s\n",d->d_name);
            }
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////

void lsa(char** args)
{
    char buf[1001];
//     if (strcmp(args[2],"-l")==0)
//    {
//        exflag=1;
//        lsal(args);
//        return;
//    }


    for(int i=2;args[i]!=NULL;i++)
    {
        if ( isDirectory(args[i]) && (isFile(args[i]))==0 )
        {
            DIR* p;
            struct dirent *d;
            p=opendir(args[i]);
            while(d=readdir(p))
            {
                // concatenation done to get full name earlier was giving error
                sprintf(buf, "%s/%s", args[i], d->d_name);

                if(isDirectory(buf)){
                    printf(COLOR_BLUE "%s "  COLOR_RESET,d->d_name);
                }
                else{
                    printf("%s ",d->d_name);
                }
            }
        }
        else if (isFile(args[i]))
        {
            printf("%s ",args[i]);
        }
    }

    // when only ls -a is he command
    if (args[2]==NULL)
    {
        int i=0;
        char cwd[FILENAME_MAX];
        getcwd(cwd,sizeof(cwd));
        if ( isDirectory(cwd) )
        {
            DIR* p;
            struct dirent *d;
            p=opendir(cwd);
            while(d=readdir(p))
            {
                // concatenation done to get full name earlier was giving error
                sprintf(buf, "%s/%s", cwd, d->d_name);
                if(isDirectory(buf)){
                    printf(COLOR_BLUE "%s "  COLOR_RESET,d->d_name);
                }
                else{
                    printf("%s ",d->d_name);
                }
            }
        }
        printf("\n");
    }
}

//////////////////////////////////////////  FLAGS AND FUNCTION POINTERS /////////////////////////////////////

char* flags[] = { "-a","-l","-al","-la" };

// It’s an array of  FUNCTION POINTERS 
void (*flag[]) (char **) = {
	&lsa,&lsl,&lsal,&lsal
};


// return Number of functions
int numflagfunc() {
	return sizeof(flags) / sizeof(char *);
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ls(char** args){

    char buf[1001];

    for (int i=0;i<numflagfunc() && args[1]!=NULL;i++){
        if (strcmp(args[1],flags[i])==0){
            (*flag[i])(args);
            return;
        }
    }
    // when only ls is the command
    if (args[1]==NULL)
    {
        int i=0;
        char cwd[FILENAME_MAX];
        getcwd(cwd,sizeof(cwd));
        if ( isDirectory(cwd) )
        {
            DIR* p;
            struct dirent *d;
            p=opendir(cwd);
            while(d=readdir(p))
            {
                // if hidden , then don't display
                if (d->d_name[0]=='.')
                {continue;}
                // concatenation done to get full name earlier was giving error
                sprintf(buf, "%s/%s", cwd, d->d_name);
                if(isDirectory(buf)){
                    printf(COLOR_BLUE "%s "  COLOR_RESET,d->d_name);
                }
                else{
                    printf("%s ",d->d_name);
                }
            }
        }
    }



    for(int i=1;args[i]!=NULL;i++)
    {
        if ( isDirectory(args[i]) && (isFile(args[i]))==0 )
        {
            DIR* p;
            struct dirent *d;
            p=opendir(args[i]);
            char buf[1001];
            while(d=readdir(p))
            {
                // if hidden , then don't display
                if (d->d_name[0]=='.')
                {continue;}
                
                sprintf(buf, "%s/%s", args[i], d->d_name);
                if(isDirectory(buf)){
                    printf(COLOR_BLUE "%s "  COLOR_RESET,d->d_name);
                }
                else{
                    printf("%s ",d->d_name);
                }
            }
        }
        else if (isFile(args[i]))
        {
            printf("%s ",args[i]);
        }
    }
        printf("\n");
}