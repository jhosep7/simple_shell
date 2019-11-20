#ifndef HOLBERTON_H
#define HOLBERTON_H

#define READLINE_BUFSIZE 1024
#define TOK_BUFSIZE 64
#define TOK_DELIM " \t\r\n\a"

#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <signal.h>

char *read_line_of_comands(void);
char **split_line(char *line);
int hsh_execute(char **args,char **env);
int hsh_cd(char **args);
int hsh_exit(char **args);
int hsh_launch(char **args, char **path);
int hsh_num_builtins(void);
char *str_concat(char *str_1, char *str_2);

#endif
