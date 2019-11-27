# Project Simple Shell

## Description
The goal of this project is to represent the command line SHELL.

## Compilation
Compilation is done usign `gcc -Wall -Werror -Wextra -pedantic *.c -o hsh`.

### Overview
Es un programa que brinda una interfaz al usuario, la cual permite comunicación
del usuario con el sistema operativo, esto mediante una ventana o pantalla la
cual permite al usuario dar órdenes al sistema operativo. En otras palabras
podemos decir que el Shell es un programa que funciona de intermediario entre
un operador y el sistema operativo.

## Contents
|   ***File***    |  **Decription**                       |
|---------------|---------------------------------------|
|  `holberton.h`	|  Header file: contains 	|
|  `shell_main.c`	|  Main file				|
|  `shell_functions.c` |  Commands to read-tokenize and excecute|
|  `shell_basic_comands.c` |  Built-in functions	|
|  `shell_EXT_functions.c`	|  Our own functions|
|  `helpmsg.c`  |  appended to help function	 |
|  `shell_EXT_helps.c`  |  Function to print integer	 |
|  `_our_write.c`  |  writes a character to stdout	 |

### Example
This shell takes the input as a standard Unix SHELL.
Once the excecutable is run the user enters the desired
input followed by a return.
* `ls -l`
#Prototype_Shell $: ls -l
total 48
-rwxr-xr-x 1 usuario usuario   158 Nov 18 11:02 AUTHORS
-rwxr-xr-x 1 usuario usuario   854 Nov 26 10:47 README.md
-rwxr-xr-x 1 usuario usuario   706 Nov 23 18:37 holberton.h
-rwxrwxr-x 1 usuario usuario 13792 Nov 26 10:48 hsh
-rwxr-xr-x 1 usuario usuario  1612 Nov 26 10:44 man_1_simple_shell
-rwxr-xr-x 1 usuario usuario  3313 Nov 22 17:04 shell_EXT_functions.c
-rwxr-xr-x 1 usuario usuario  1394 Nov 23 18:59 shell_basic_comands.c
-rwxr-xr-x 1 usuario usuario  2536 Nov 23 19:05 shell_functions.c
-rwxr-xr-x 1 usuario usuario  1532 Nov 23 16:42 shell_main.c
* `pwd`
#Prototype_Shell $: pwd
/home/usuario/ShellProject/simple_shell
* `echo hello world`
#Prototype_Shell $: echo hello world
hello world
### Release History
* Nov 27 2019

### Authors
Jonathan Mazo - 1150@holbertonschool.com
Jose Diaz - 1149@holbertonschool.com