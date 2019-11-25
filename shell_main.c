#include "holberton.h"

/**
 * handle_signal - get the signal.
 * @sig: the signal.
 * Return: dont return anything.
 */

void handle_signal(int sig)
{
	write(STDOUT_FILENO, "\n#Prototype_Shell $: ", 22);
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
	char *line = NULL;
	char **args, **tokens_path, *path_cat = NULL;
	int status = 0;

	do {
		write(STDOUT_FILENO, "#Prototype_Shell $: ", 21);

		line = read_line_of_comands();
		args = split_line(line);
		tokens_path = split_path(env);
		path_cat = path_concat(args, tokens_path);
		status = hsh_execute(path_cat, args, env);

		free(line);
		free(args);
		free(tokens_path);
		/* free(path_cat); */
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
	int ac = argc, count;
	char *av = NULL;
	char **args, **tokens_path, *path_cat = NULL;

	av = malloc(TOK_BUFSIZE * sizeof(char *));
	if (av == NULL)
	{
		return (0);
	}
	if (ac > 1)
	{
		count = 0;
		av = str_concat(_strdup(argv[0]), " ");
		while (argv[count] != NULL && count < 3)
		{
			av = str_concat(av, argv[count + 1]);
			av = str_concat(av, " ");
			count++;
		}
		args = split_line(av);
		tokens_path = split_path(env);
		path_cat = path_concat(args, tokens_path);
		if (execve(path_cat, args, NULL) == -1)
		{
			write(STDOUT_FILENO, args[0], _strlen(args[0]));
			write(STDOUT_FILENO, ": ", 2);
			write(STDOUT_FILENO, "1", 1);
			write(STDOUT_FILENO, ": ", 2);
			write(STDOUT_FILENO, args[1], _strlen(args[1]));
			write(STDOUT_FILENO, ": ", 2);
			write(STDOUT_FILENO, "command not found\n", 19);
		}
		free(av), free(args), free(path_cat), ac = -10;
	}
	if (ac == -10 || ac == 1)
	{
		signal(SIGINT, handle_signal);
		main_loop(env);
	}
	return (0);
}
