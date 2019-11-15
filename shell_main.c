#include "holberton.h"

/**
 * main_loop - Loop that wait the user orders.
 * Return: dont return anything.
 */

void main_loop(void)
{
	char *line;
	char **args;
	int status;

	do {
		printf("#Prototype_Shell$ ");

		line = read_line_of_comands();
		args = split_line(line);
		status = hsh_execute(args);

		free(line);
		free(args);
	} while (status);
}

/**
 * main - Principal function to de prototype of Shell
 * @argc: Arguments count.
 * @argv: Arguments input by the user input.
 * Return: status of the code.
 */

int main(int argc, char *argv[])
{
	int ac = argc;
	char **av = argv;

	/* Load config files, if any. */

	if (ac > 1 || av == NULL)
	{
		return (1);
	}
	/* Run command loop. */
	main_loop();

	/* Perform any shutdown/cleanup. */

	return (EXIT_SUCCESS);
}
