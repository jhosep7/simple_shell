#ifndef HOLBERTON_H
#define HOLBERTON_H

#define READLINE_BUFSIZE 1024
#define TOK_BUFSIZE 64
#define PATH_BUFSIZE 1024
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
char **cutting_line(char *line);
int hsh_execute(char *args, char **path, char **env, int count, char *exe_file);
int hsh_cd(char **args);
int hsh_exit(char **args);
int hsh_help(char **args);
int hsh_launch(char *args, char **path, int count, char *exe_file);
int hsh_num_builtins(void);
char *str_concat(char *str_1, char *str_2);
char **split_path(char *env[]);
int _strcmp(char *s1, char *s2);
char *path_concat(char **args, char **path);
int _strlen(char *string);
char *_strdup(char *str);
int print_numbers(int our_digit);
int _our_write(char c);

/* Help Mesage */
int helpExit(void);
int helpCD(void);
int helpEnv(void);
int helpPWD(void);
int helpEcho(void);

#endif
