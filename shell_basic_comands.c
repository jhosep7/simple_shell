#include "holberton.h"

/**
 * hsh_num_builtins - change directory.
 * Return: Always returns 1, to continue executing.
 */

int hsh_num_builtins(void)
{
	char *builtin_str[] = {"cd", "exit"};

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
		printf("hsh: expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("hsh");
		}
	}
	return (1);
}

/**
 * hsh_exit - exit.
 * @args: arguments.
 * Return: Always returns 0, to terminate execution.
 */

int hsh_exit(char **args)
{
	if (args == NULL)
	{
		write(STDOUT_FILENO, "Error to exit.\n", 100);
		return (1);
	}
	return (0);
}
