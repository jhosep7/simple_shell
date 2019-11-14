#include "holberton.h"

/**
 * main_loop - Loop that wait the user orders.
 * Return: dont return anything.
 */

void main_loop(int ac, char *av)
{
	char *line;
	char **args;
	int status;

	do {
		printf("#Prototype_Holby_Shell$ ");

		line = hsh_read_line();
		args = hsh_split_line(line);
		status = hsh_execute(args);

		free(line);
		free(args);
	} while (status);

	return (0);
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
	char *av = argv;

	/* Load config files, if any. */

	/* Run command loop. */
	main_loop(ac, av);

	/* Perform any shutdown/cleanup. */

	return (EXIT_SUCCESS);
}
