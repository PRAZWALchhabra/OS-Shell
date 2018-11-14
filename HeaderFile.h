#ifndef HEADER
#define HEADER

#define TOKEN_BUFFER_SIZE 64
#define TOKEN_DELIM " \t\r\n\a"
#define CMD_DELIM ";\n"
#define PIPE_DELIM "|"


// Define COLORS
#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN    "\x1b[36m"
#define COLOR_RESET   "\x1b[0m"

// Global variables
char home[FILENAME_MAX];
int keeprunning;

void print_prompt();
void executeCommand(char** args);
int executeFunc(char** args);
void sysCommand(char** args);
char* readLine();
char** splitLine(char* line);
char** splitCommand(char* line);
void pwd();
void cd(char** args);
void ls(char** args);
void pinfo(char ** args);
void echo();
void remindme(char **args);
void clockt(char **args);
void  SIGINT_handler(int sig);
void  SIGQUIT_handler(int signal_num);
void  SIGTSTP_handler(int signal_num);
void background_fxn();
void back_process(int pid,char * cmd,int flag);
void start_shell();
////////////////// PART2 IMPLEMENTATION //////////////////
void setvar(char ** args);
void unsetvar(char ** args);
void kjob_cmd(char ** args);
void fg_cmd(char **args);
void bg_cmd(char **args);
void killAllBG(char **args);
void jobs_cmd(char **args);

void pipe_cmd(char** args);
void redirect_cmd(char** args);


///////////////////////process struct////////////////////
typedef struct process{
	int pid;
	int jobid;
	char * command;
	int flag;
}process;

process bg_process[111];

//////////////////////////////////////////////////////////

#endif