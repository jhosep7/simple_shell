#include "holberton.h"

/**
 * helpExit - prints the exit help page.
 * Return: Always 1
 */
int helpExit(void)
{
	write(STDOUT_FILENO, "exit: exit [n]\n\n", 17);
	write(STDOUT_FILENO, "  Exit the shell.\n\n", 20);
	write(STDOUT_FILENO, "  Exits the shell with a status of N.\n", 39);
	write(STDOUT_FILENO, "  the exit status is that", 26);
	write(STDOUT_FILENO, "  the exit status is that of", 29);
	write(STDOUT_FILENO, "  the last command executed.\n", 30);
	write(STDOUT_FILENO, "   \n", 5);
	return (0);
}
/**
 * helpCD - prints the alias help
 * Return: Always 1
 */
int helpCD(void)
{
	write(STDOUT_FILENO, "cd: cd [-L|[-P [-e]] [-@]] [dir]\n", 34);
	write(STDOUT_FILENO, "    Change the shell working directory.\n\n", 42);
	write(STDOUT_FILENO, "The default DIR is the value of the HOME shell.", 48);
	write(STDOUT_FILENO, "The variable CDPATH defines the search path.\n", 46);
	write(STDOUT_FILENO, "Alt DIR names in CDPATH separated by colon (:).\n", 49);
	write(STDOUT_FILENO, "A null DIR name is the same as the cur dir.\n", 45);
	write(STDOUT_FILENO, "-L force symbolic links to be followed\n", 40);
	write(STDOUT_FILENO, " links in DIR after processing instances:\n", 42);
	write(STDOUT_FILENO, "-P	use the physical DIR structure without \n", 44);
	write(STDOUT_FILENO, "	symbolic links.\n", 19);
	write(STDOUT_FILENO, "-e	if the -P option is supplied.\n", 34);
	write(STDOUT_FILENO, "	exit with a non-zero status\n", 30);
	write(STDOUT_FILENO, "Exit Status:\n", 14);
	write(STDOUT_FILENO, "Returns 0 if the directory is changed\n", 39);
	write(STDOUT_FILENO, "successfully when -P is used.\n", 31);
	write(STDOUT_FILENO, "   \n", 5);
	return (0);
}
/**
 * helpEnv - prints the env help page.
 * Return: Always 1
 */
int helpEnv(void)
{
	write(STDOUT_FILENO, "env: env  [-] [NAME=VALUE].. [COMMAND [ARG].]\n\n", 48);
	write(STDOUT_FILENO, "  Prints out the current environment\n\n", 39);
	write(STDOUT_FILENO, "  Exit Status:\n", 16);
	write(STDOUT_FILENO, "  Returns success unless invalid option given\n", 47);
	write(STDOUT_FILENO, "  or an error occurs.\n", 23);
	write(STDOUT_FILENO, "   \n", 5);
	return (0);
}
/**
 * helpPWD - prints the Pwd
 * Return: Always 1
 */
int helpPWD(void)
{
	write(STDOUT_FILENO, "pwd: pwd [-LP]\n", 16);
	write(STDOUT_FILENO, "	Print the name of the cur working DIR.\n\n", 42);
	write(STDOUT_FILENO, "	Options:\n", 11);
	write(STDOUT_FILENO, "	-L	print the value of $PWD.\n", 30);
	write(STDOUT_FILENO, "	-P	print the physical directory.\n", 35);
	write(STDOUT_FILENO, "	`pwd' behaves as if `-L' were specified.\n\n", 44);
	write(STDOUT_FILENO, "	Exit Status:\n", 15);
	write(STDOUT_FILENO, "	Returns 0 unless invalid option is given\n", 43);
	write(STDOUT_FILENO, "	cannot be read.\n", 18);
	write(STDOUT_FILENO, "   \n", 5);
	return (0);
}
/**
 * helpEcho - prints the Echo help
 * Return: Always 1
 */
int helpEcho(void)
{
	write(STDOUT_FILENO, "echo: echo [-neE] [arg ...]\n", 29);
	write(STDOUT_FILENO, "	Write arguments to the standard output.\n\n", 43);
	write(STDOUT_FILENO, "	Display the ARGs, followed by", 31);
	write(STDOUT_FILENO, "	a newline, on the standard output.\n\n", 38);
	write(STDOUT_FILENO, "	Options:\n", 11);
	write(STDOUT_FILENO, "	-n	do not append a newline\n", 29);
	write(STDOUT_FILENO, "	-e	enable interpretation of backslash\n", 40);
	write(STDOUT_FILENO, "	-E	explicitly suppress interpretation\n", 40);
	write(STDOUT_FILENO, "	`echo' interprets this characters:\n\n", 38);
	write(STDOUT_FILENO, "	\\a	alert (bell)\n", 18);
	write(STDOUT_FILENO, "	\\b	backspace\n", 15);
	write(STDOUT_FILENO, "	\\c	suppress further output\n\n", 30);
	write(STDOUT_FILENO, "	Exit Status:\n", 15);
	write(STDOUT_FILENO, "	Returns success unless write error occurs\n", 44);
	write(STDOUT_FILENO, "   \n", 5);
	return (0);
}
