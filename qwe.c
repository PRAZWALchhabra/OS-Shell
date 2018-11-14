





































   
    
                
                }
                }
                }
                }
                }
                }
                }
                }
            {
            {
            {
            {
            {
            {
            {
            {
            }
            }
            }
            }
            }
            }
            }
            }
        {
        {
        {
        {
        {
        {
        {
        {
        {
        {
        {
        {
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
    {
    {
    {
    {
    {
    {
    {
    {
    }
    }
    }
    }
    }
    }
    }
    }
    }
    }
//    {
//    {
//    }
//    }
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
{
{
{
{
{
{
}
}
}
}
}
}
}
}
};
// Auhor : Prazwal Chhabra
            char buf[1001];
    char buf[1001];
    char buf[1001];
    char buf[1001];
   char buf[1001];
        char cwd[FILENAME_MAX];
        char cwd[FILENAME_MAX];
        char cwd[FILENAME_MAX];
        char cwd[FILENAME_MAX];
    char date[10];
char* flags[] = { "-a","-l","-al","-la" };
    // Check for directory existence
    // Check for file existence
/// Check whether argument passed is a file or a directory ///
                // concatenation done to get full name earlier was giving error
                // concatenation done to get full name earlier was giving error
                // concatenation done to get full name earlier was giving error
                // concatenation done to get full name earlier was giving error
                // concatenation done to get full name earlier was giving error
                // concatenation done to get full name earlier was giving error
                // concatenation done to get full name earlier was giving error
                {continue;}
                {continue;}
                {continue;}
                {continue;}
            DIR* p;
            DIR* p;
            DIR* p;
            DIR* p;
            DIR* p;
            DIR* p;
            DIR* p;
            DIR* p;
                else{
                else{
                else{
                else{
        else if (isFile(args[i]))
        else if (isFile(args[i]))
        else if (isFile(args[i]))
        else if (isFile(args[i]))
    exflag=0;
//        exflag=1;
//        exflag=1;
            (*flag[i])(args);
//////////////////////////////////////////  FLAGS AND FUNCTION POINTERS /////////////////////////////////////
    for (int i=0;i<numflagfunc() && args[1]!=NULL;i++){
    for(int i=1;args[i]!=NULL;i++)
    for(int i=2;args[i]!=NULL;i++)
   for(int i=2;args[i]!=NULL;i++)
    for(int i=2+exflag;args[i]!=NULL;i++)
        getcwd(cwd,sizeof(cwd));
        getcwd(cwd,sizeof(cwd));
        getcwd(cwd,sizeof(cwd));
        getcwd(cwd,sizeof(cwd));
    if (args[1]==NULL)
    if (args[2+exflag]==NULL){
    if (args[2]==NULL)
    if (args[2]==NULL)
                if (d->d_name[0]=='.')
                if (d->d_name[0]=='.')
                if (d->d_name[0]=='.')
                if (d->d_name[0]=='.')
                // if hidden , then don't display
                // if hidden , then don't display
                // if hidden , then don't display
        if ( isDirectory(args[i]) )
        if ( isDirectory(args[i]) && (isFile(args[i]))==0 )
        if ( isDirectory(args[i]) && (isFile(args[i]))==0 )
        if ( isDirectory(args[i]) && (isFile(args[i]))==0 )
                if(isDirectory(buf)){
                if(isDirectory(buf)){
                if(isDirectory(buf)){
                if(isDirectory(buf)){
        if ( isDirectory(cwd) )
        if ( isDirectory(cwd) )
        if ( isDirectory(cwd) )
        if ( isDirectory(cwd) )
    if (S_ISDIR(stats.st_mode))
    if (S_ISREG(stats.st_mode))
    if(stat(file,&fileStat) < 0)  
        if (strcmp(args[1],flags[i])==0){
//    if (strcmp(args[2],"-a")==0)
//     if (strcmp(args[2],"-l")==0)
#include <dirent.h>
#include <fcntl.h>
#include <grp.h>
#include "HeaderFile.h"
#include <limits.h>
#include <pwd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include<sys/stat.h>
#include <sys/utsname.h>
#include <sys/wait.h>
#include<time.h>
#include <unistd.h>
            infoFile(args[i]);
            infoFile(args[i]);
                infoFile(buf);
                infoFile(buf);
                infoFile(buf);
                infoFile(buf);
int exflag=0;
        int i=0;
        int i=0;
        int i=0;
        int i=0;
int isDirectory(const char *path)
int isFile(const char *path)
int numflagfunc() {
// It’s an array of  FUNCTION POINTERS 
//        lsal(args);
//        lsal(args);
	&lsa,&lsl,&lsal,&lsal
    // Name of file/directory group
    // Name of file/directory owner or creator
    // Owner and Group of file/directory
            p=opendir(args[i]);
            p=opendir(args[i]);
            p=opendir(args[i]);
            p=opendir(args[i]);
            p=opendir(cwd);
            p=opendir(cwd);
            p=opendir(cwd);
            p=opendir(cwd);
    printf(" ");
    printf(" ");
    printf(" %10ld ",fileStat.st_size);
                    printf(COLOR_BLUE "%s "  COLOR_RESET,d->d_name);
                    printf(COLOR_BLUE "%s "  COLOR_RESET,d->d_name);
                    printf(COLOR_BLUE "%s "  COLOR_RESET,d->d_name);
                    printf(COLOR_BLUE "%s "  COLOR_RESET,d->d_name);
    // printf("File inode: \t\t%d\n",fileStat.st_ino);
    printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
    printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
    printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
    printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
    printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
    printf( (fileStat.st_mode & S_IXOTH) ? "x" : "-");
    printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
    printf( gr->gr_name ? "%s" : "-",gr->gr_name);
        printf("\n");
        printf("\n");
        // printf("\n1\n");
    // printf("Number of Links: \t%d\n",fileStat.st_nlink);
    printf( pw->pw_name ? "%s" : "-",pw->pw_name);
            printf("%s ",args[i]);
            printf("%s ",args[i]);
            printf("%s ",args[i]);
            printf("%s ",args[i]);
    printf(" %s ",date);
                    printf("%s ",d->d_name);
                    printf("%s ",d->d_name);
                    printf("%s ",d->d_name);
                    printf("%s ",d->d_name);
                printf("%s ",d->d_name);
    printf( (S_ISDIR(fileStat.st_mode)) ? "d" : "-");
                printf("%s\n",d->d_name);
                printf("%s\n",d->d_name);
                printf("%s\n",d->d_name);
            return;
        return;
//        return;
//        return;
    return 0;
    return 0;
        return 1;
        return 1;
// return Number of functions
	return sizeof(flags) / sizeof(char *);
    // Size of file or directory
                sprintf(buf, "%s/%s", args[i], d->d_name);
                sprintf(buf, "%s/%s", args[i], d->d_name);
                sprintf(buf, "%s/%s", args[i], d->d_name);
                sprintf(buf, "%s/%s", args[i], d->d_name);
                sprintf(buf, "%s/%s", cwd, d->d_name);
                sprintf(buf, "%s/%s", cwd, d->d_name);
                sprintf(buf, "%s/%s", cwd, d->d_name);
                sprintf(buf, "%s/%s", cwd, d->d_name);
    stat(path, &stats);
    stat(path, &stats);
    strftime(date, 20, "%d-%m-%y", localtime(&(fileStat.st_ctime)));
            struct dirent *d;
            struct dirent *d;
            struct dirent *d;
            struct dirent *d;
            struct dirent *d;
            struct dirent *d;
            struct dirent *d;
            struct dirent *d;
    struct group  *gr = getgrgid(fileStat.st_gid);
    struct passwd *pw = getpwuid(fileStat.st_uid);
    struct stat fileStat;
    struct stat stats;
    struct stat stats;
//////////////////////////////// Useful with -l flag ////////////////////////////////////
void (*flag[]) (char **) = {
void infoFile(char* file)
void lsa(char** args)
void lsal(char** args)
void ls(char** args){
void lsl(char** args)
    // when only ls -a is he command
    // When only ls -al is given
    // when only ls is the command
    // when only ls -l is he command
            while(d=readdir(p))
            while(d=readdir(p))
            while(d=readdir(p))
            while(d=readdir(p))
            while(d=readdir(p))
            while(d=readdir(p))
            while(d=readdir(p))
            while(d=readdir(p))






































   
    
                
                }
                }
                }
                }
                }
                }
                }
                }
            {
            {
            {
            {
            {
            {
            {
            {
            }
            }
            }
            }
            }
            }
            }
            }
        {
        {
        {
        {
        {
        {
        {
        {
        {
        {
        {
        {
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
    {
    {
    {
    {
    {
    {
    {
    {
    }
    }
    }
    }
    }
    }
    }
    }
    }
    }
//    {
//    {
//    }
//    }
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
{
{
{
{
{
{
}
}
}
}
}
}
}
}
};
// Auhor : Prazwal Chhabra
            char buf[1001];
    char buf[1001];
    char buf[1001];
    char buf[1001];
   char buf[1001];
        char cwd[FILENAME_MAX];
        char cwd[FILENAME_MAX];
        char cwd[FILENAME_MAX];
        char cwd[FILENAME_MAX];
    char date[10];
char* flags[] = { "-a","-l","-al","-la" };
    // Check for directory existence
    // Check for file existence
/// Check whether argument passed is a file or a directory ///
                // concatenation done to get full name earlier was giving error
                // concatenation done to get full name earlier was giving error
                // concatenation done to get full name earlier was giving error
                // concatenation done to get full name earlier was giving error
                // concatenation done to get full name earlier was giving error
                // concatenation done to get full name earlier was giving error
                // concatenation done to get full name earlier was giving error
                {continue;}
                {continue;}
                {continue;}
                {continue;}
            DIR* p;
            DIR* p;
            DIR* p;
            DIR* p;
            DIR* p;
            DIR* p;
            DIR* p;
            DIR* p;
                else{
                else{
                else{
                else{
        else if (isFile(args[i]))
        else if (isFile(args[i]))
        else if (isFile(args[i]))
        else if (isFile(args[i]))
    exflag=0;
//        exflag=1;
//        exflag=1;
            (*flag[i])(args);
//////////////////////////////////////////  FLAGS AND FUNCTION POINTERS /////////////////////////////////////
    for (int i=0;i<numflagfunc() && args[1]!=NULL;i++){
    for(int i=1;args[i]!=NULL;i++)
    for(int i=2;args[i]!=NULL;i++)
   for(int i=2;args[i]!=NULL;i++)
    for(int i=2+exflag;args[i]!=NULL;i++)
        getcwd(cwd,sizeof(cwd));
        getcwd(cwd,sizeof(cwd));
        getcwd(cwd,sizeof(cwd));
        getcwd(cwd,sizeof(cwd));
    if (args[1]==NULL)
    if (args[2+exflag]==NULL){
    if (args[2]==NULL)
    if (args[2]==NULL)
                if (d->d_name[0]=='.')
                if (d->d_name[0]=='.')
                if (d->d_name[0]=='.')
                if (d->d_name[0]=='.')
                // if hidden , then don't display
                // if hidden , then don't display
                // if hidden , then don't display
        if ( isDirectory(args[i]) )
        if ( isDirectory(args[i]) && (isFile(args[i]))==0 )
        if ( isDirectory(args[i]) && (isFile(args[i]))==0 )
        if ( isDirectory(args[i]) && (isFile(args[i]))==0 )
                if(isDirectory(buf)){
                if(isDirectory(buf)){
                if(isDirectory(buf)){
                if(isDirectory(buf)){
        if ( isDirectory(cwd) )
        if ( isDirectory(cwd) )
        if ( isDirectory(cwd) )
        if ( isDirectory(cwd) )
    if (S_ISDIR(stats.st_mode))
    if (S_ISREG(stats.st_mode))
    if(stat(file,&fileStat) < 0)  
        if (strcmp(args[1],flags[i])==0){
//    if (strcmp(args[2],"-a")==0)
//     if (strcmp(args[2],"-l")==0)
#include <dirent.h>
#include <fcntl.h>
#include <grp.h>
#include "HeaderFile.h"
#include <limits.h>
#include <pwd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include<sys/stat.h>
#include <sys/utsname.h>
#include <sys/wait.h>
#include<time.h>
#include <unistd.h>
            infoFile(args[i]);
            infoFile(args[i]);
                infoFile(buf);
                infoFile(buf);
                infoFile(buf);
                infoFile(buf);
int exflag=0;
        int i=0;
        int i=0;
        int i=0;
        int i=0;
int isDirectory(const char *path)
int isFile(const char *path)
int numflagfunc() {
// It’s an array of  FUNCTION POINTERS 
//        lsal(args);
//        lsal(args);
	&lsa,&lsl,&lsal,&lsal
    // Name of file/directory group
    // Name of file/directory owner or creator
    // Owner and Group of file/directory
            p=opendir(args[i]);
            p=opendir(args[i]);
            p=opendir(args[i]);
            p=opendir(args[i]);
            p=opendir(cwd);
            p=opendir(cwd);
            p=opendir(cwd);
            p=opendir(cwd);
    printf(" ");
    printf(" ");
    printf(" %10ld ",fileStat.st_size);
                    printf(COLOR_BLUE "%s "  COLOR_RESET,d->d_name);
                    printf(COLOR_BLUE "%s "  COLOR_RESET,d->d_name);
                    printf(COLOR_BLUE "%s "  COLOR_RESET,d->d_name);
                    printf(COLOR_BLUE "%s "  COLOR_RESET,d->d_name);
    // printf("File inode: \t\t%d\n",fileStat.st_ino);
    printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
    printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
    printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
    printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
    printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
    printf( (fileStat.st_mode & S_IXOTH) ? "x" : "-");
    printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
    printf( gr->gr_name ? "%s" : "-",gr->gr_name);
        printf("\n");
        printf("\n");
        // printf("\n1\n");
    // printf("Number of Links: \t%d\n",fileStat.st_nlink);
    printf( pw->pw_name ? "%s" : "-",pw->pw_name);
            printf("%s ",args[i]);
            printf("%s ",args[i]);
            printf("%s ",args[i]);
            printf("%s ",args[i]);
    printf(" %s ",date);
                    printf("%s ",d->d_name);
                    printf("%s ",d->d_name);
                    printf("%s ",d->d_name);
                    printf("%s ",d->d_name);
                printf("%s ",d->d_name);
    printf( (S_ISDIR(fileStat.st_mode)) ? "d" : "-");
                printf("%s\n",d->d_name);
                printf("%s\n",d->d_name);
                printf("%s\n",d->d_name);
            return;
        return;
//        return;
//        return;
    return 0;
    return 0;
        return 1;
        return 1;
// return Number of functions
	return sizeof(flags) / sizeof(char *);
    // Size of file or directory
                sprintf(buf, "%s/%s", args[i], d->d_name);
                sprintf(buf, "%s/%s", args[i], d->d_name);
                sprintf(buf, "%s/%s", args[i], d->d_name);
                sprintf(buf, "%s/%s", args[i], d->d_name);
                sprintf(buf, "%s/%s", cwd, d->d_name);
                sprintf(buf, "%s/%s", cwd, d->d_name);
                sprintf(buf, "%s/%s", cwd, d->d_name);
                sprintf(buf, "%s/%s", cwd, d->d_name);
    stat(path, &stats);
    stat(path, &stats);
    strftime(date, 20, "%d-%m-%y", localtime(&(fileStat.st_ctime)));
            struct dirent *d;
            struct dirent *d;
            struct dirent *d;
            struct dirent *d;
            struct dirent *d;
            struct dirent *d;
            struct dirent *d;
            struct dirent *d;
    struct group  *gr = getgrgid(fileStat.st_gid);
    struct passwd *pw = getpwuid(fileStat.st_uid);
    struct stat fileStat;
    struct stat stats;
    struct stat stats;
//////////////////////////////// Useful with -l flag ////////////////////////////////////
void (*flag[]) (char **) = {
void infoFile(char* file)
void lsa(char** args)
void lsal(char** args)
void ls(char** args){
void lsl(char** args)
    // when only ls -a is he command
    // When only ls -al is given
    // when only ls is the command
    // when only ls -l is he command
            while(d=readdir(p))
            while(d=readdir(p))
            while(d=readdir(p))
            while(d=readdir(p))
            while(d=readdir(p))
            while(d=readdir(p))
            while(d=readdir(p))
            while(d=readdir(p))
