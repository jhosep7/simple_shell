#include "holberton.h"

/**
 * _strlen - calculate the length of String
 * @string: String.
 * Return: return the length
 */

int _strlen(char *string)
{
	int k;

	for (k = 0; string[k] != '\0'; k++)
	{; }
	return (k);
}

/**
 * hsh_num_builtins - change directory.
 * Return: Always returns 1, to continue executing.
 */

int hsh_num_builtins(void)
{
	char *builtin_str[] = {"cd", "exit", "help"};

	return (sizeof(builtin_str) / sizeof(char *));
}

/**
 * hsh_cd - change directory.
 * @args: List of args.  args[0] is "cd".  args[1] is the directory.
 * Return: Always returns 1, to continue executing.
 */

int hsh_cd(char **args)
{
	if (args[1] == NULL)
	{
		write(STDOUT_FILENO, "hsh: expected argument to \"cd\"\n", 34);
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("hsh");
		}
	}
	return (0);
}

/**
 * hsh_help - prints help.
 * @args: arguments.
 * Return: returns int.
 */

int hsh_help(char **args)
{
	int i, j, k;
	char *Commands[7] = {"cd [-L|[-P [-e]] [-@]] [dir]", "exit [n]",
		"help [-dms]", "echo [arg]", "pwd [-LP]", "env [NAME=VALUE]"
		};

	write(STDOUT_FILENO, "\nHolberton students bash,", 26);
	write(STDOUT_FILENO, " version 1.0-release (x86_64-pc-linux-gnu)\n", 44);
	write(STDOUT_FILENO, "Usage: \" help [BUILTIN]\"\n", 26);
	write(STDOUT_FILENO, "===================\n\n", 22);
	for (i = 0; args[i] != NULL; i++)
	{/*	write(STDOUT_FILENO, args[i], strlen(args[i]));*/	}
	i--;
	if (_strcmp(args[i], "help") == 0)
	{
		for (j = 0; j < 6; j++)
		{	write(STDOUT_FILENO, "\t", 1);
			for (k = 0; Commands[j][k]; k++)
			{write(STDOUT_FILENO, &Commands[j][k], 1); }
			write(STDOUT_FILENO, "\n", 1);
		}
		write(STDOUT_FILENO, "\n", 1);
		write(STDOUT_FILENO, "By: JONATAN MAZO - JOSE DIAZ.\n", 31);
		write(STDOUT_FILENO, "Website https://www.holbertonschool.com/co\n", 62);
		return (0);
	}
	if (_strcmp(args[1], "cd") == 0)
	{helpCD(); }
	if (_strcmp(args[1], "exit") == 0)
	{helpExit(); }
	if (_strcmp(args[1], "env") == 0)
	{helpEnv(); }
	if (_strcmp(args[1], "pwd") == 0)
	{helpPWD(); }
	if (_strcmp(args[1], "echo") == 0)
	{helpEcho(); }
	return (0);
}

/**
 * hsh_exit - exit.
 * @args: arguments.
 * Return: Always returns 0, to terminate execution.
 */

int hsh_exit(char **args)
{
	int x = 0;

	if (args == NULL)
	{
		write(STDOUT_FILENO, "Error to exit.\n", 16);
		return (0);
	}
	while (args[x] != NULL)
	{
		free(args[x]);
		x++;
	}
	free(args);
	exit(0);
}
