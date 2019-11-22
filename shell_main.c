#include "holberton.h"

/**
 * handle_signal - get the signal.
 * @sig: the signal.
 * Return: dont return anything.
 */

void handle_signal(int sig)
{
	write(STDOUT_FILENO, "\n#Prototype_Shell $:", 21);
	if (sig < 0)
	{
		write(STDOUT_FILENO, "Can't read the '^' comand\n", 28);
		exit(EXIT_FAILURE);
	}
}

/**
 * main_loop - Loop that wait the user orders.
 * @env: sys variable.
 * Return: dont return anything.
 */

void main_loop(char **env)
{
	char *line;
	char **args, **tokens_path, *path_cat = NULL;
	int status;

	do {
		printf("#Prototype_Shell $: ");

		line = read_line_of_comands();
		args = split_line(line);
		tokens_path = split_path(env);
		path_cat = path_concat(args, tokens_path);
		status = hsh_execute(path_cat, args);

		/* Provar un loop, para armar de nuevo el ENV */
		free(line);
		free(args);
		free(path_cat);
	} while (status);
}

/**
 * main - Principal function to de prototype of Shell
 * @argc: Arguments count.
 * @argv: Arguments input by the user input.
 * @env: sys variable.
 * Return: status of the code.
 */

int main(int argc, char *argv[], char **env)
{
	int ac = argc;
	char **av = argv;

	/* Load config files, if any. */

	if (ac > 10 && av == NULL)
	{
		write(STDOUT_FILENO, "Error unknown | Can't to enter to SHELL\n", 42);
		exit(EXIT_FAILURE);
	}
	/* Run command loop. */
	signal(SIGINT, handle_signal);
	main_loop(env);

	/* Perform any shutdown/cleanup. */

	return (EXIT_SUCCESS);
}
