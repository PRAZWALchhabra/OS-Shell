This is an implementation of a shell with code in C .
* To compile: make 
* To run: ./a.out 
* Clean: make clean 
Incase the prompt doesn't appear after a background process is started/terminated or for any other reason, press ENTER.

Features implemented
1) A shell prompt of the form: <username@system_name:curr_dir> with path relative to home.
2) The directory where the shell is invoked is taken as the home directory.
3) Semi-colon (;) separated commands 
4) & to run a process in background 
5) Some built in commands like cd ,echo ,ls , and pwd re-implemented 
5) Type exit to exit the shell 
6) Implements foreground and background processes 
7) Process name and id printed when background process terminates 
8) Type pinfo in the prompt to print: pid, process, status, memory and executable path (on Linux machines) 
9) Piping and file redirection implemented. 
10) kjob command is used to send signals to kill, stop or continue a background process.
11) fg runs a background process in foreground whereas bg runs a stopped background process to run in background.
12) jobs to display all background processes with their ID's.
13) Ctrl-Z stops the current running process and moves  it to the background.
14) Ctrl-C terminates the current foreground process.
15) Overkill kills all background processes at once.
	**Some built-in bash commands are implemented and the rest are invoked using execvp**

Files in Directory:-

1) shell.c           :- contains the main ,split_line ,split_command , loop function . main function calls the loop function ,which further directs the futher implementation. All cobtains signal handlers to control functioning of Ctrl-Z and Ctrl-C signals.

2) ls.c             :- contains ls ,lsl ,get_perms function. It handles ls command .

3) echo.c           :- contains echo function . It handles echo command.

4) cd.c       		:- contains cd function . It handles cd command.

5) function.h 		:- contains all the definitions of functions and the definitions of the arrays and the libraries to be included.

6) pinfo.c    		:- contains pinfo function. It prints the process related info of our shell program.

7) pwd.c      		:- contains pwd function . It handles pwd command.

8) prompt.c :- contains the prompt function to display the hostname and commandline.

9) exec.c :-contains bg function to run a stopped background process; contains fg function to run a running or stopped background process in foreground,  contains jobs function to display all background processes, contains kjob function to send signals to a backgroung process, contains overkill function to tereminate all background processes,  sets the environment variable to the desired value, unsets the value of an environment variable.

10)pipe_redirect.c :- implements file redirection in the shell and piping.
