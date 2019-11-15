#ifndef HOLBERTON_H
#define HOLBERTON_H
#define READLINE_BUFSIZE 1024
#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM " \t\r\n\a"

#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *read_line_of_comands(void);

#endif
