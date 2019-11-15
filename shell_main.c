#include "holberton.h"

/**
 * main_loop - Loop that wait the user orders.
 * Return: dont return anything.
 */

int main_loop(int argc, char *argv[])
{
	char *line;
	char **args;
	int status = 1;

	do {
		printf("#Prototype_Shell$ ");

		if ((argc > 1) || (argv == NULL))
		{
			printf("hsh: expected only one argument\n");
			return (EXIT_SUCCESS);
		}
		line = read_line_of_comands();
		printf("%s\n", line);
		args = hsh_split_line(line);
		/* status = hsh_execute(args); */

		free(line);
		/* free(args); */
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
	char **av = argv;
	int status = 0;

	/* Load config files, if any. */

	/* Run command loop. */
	status = main_loop(ac, av);

	/* Perform any shutdown/cleanup. */

	return (status);
}
