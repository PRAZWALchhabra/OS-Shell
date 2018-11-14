compile: shell.o  print_prompt.o echo.o execute.o read_line_and_split.o pwd.o cd.o ls.o pinfo.o remindme.o clock.o setenv.o unsetenv.o pipe_redirect.o
	gcc shell.o print_prompt.o echo.o execute.o read_line_and_split.o pwd.o cd.o ls.o pinfo.o remindme.o clock.o setenv.o unsetenv.o pipe_redirect.o

shell.o: shell.c
	gcc -c shell.c

print_prompt.o: print_prompt.c
	gcc -c print_prompt.c

echo.o: echo.c
	gcc -c echo.c

execute.o: execute.c
	gcc -c execute.c

read_line_and_split.o: read_line_and_split.c
	gcc -c read_line_and_split.c

pwd.o: pwd.c
	gcc -c pwd.c

cd.o: cd.c
	gcc -c cd.c

ls.o: ls.c
	gcc -c ls.c

pinfo.o: pinfo.c
	gcc -c pinfo.c

remindme.o: remindme.c
	gcc -c remindme.c

clock.o: clock.c
	gcc -c clock.c

setenv.o: setenv.c
	gcc -c setenv.c

unsetenv.o: unsetenv.c
	gcc -c unsetenv.c

pipe_redirect.o: pipe_redirect.c
	gcc -c pipe_redirect.c

clean:
	rm shell.o print_prompt.o echo.o execute.o read_line_and_split.o pwd.o cd.o ls.o pinfo.o remindme.o clock.o setenv.o unsetenv.o pipe_redirect.o