#include "holberton.h"

int (*builtin_func[]) (char **args) = {&hsh_cd, &hsh_exit, &hsh_help};

/**
 * read_line_of_comands - Function that read all comands that user in.
 * Return: Always 0.
 */

char *read_line_of_comands(void)
{
	char *line = NULL;
	size_t bufsize = READLINE_BUFSIZE;
	ssize_t test = 0;

	test = getline(&line, &bufsize, stdin);
	if (test < 0)
	{
		write(STDOUT_FILENO, "\n", 1);
		exit(EXIT_SUCCESS);
	}
	return (line);
}


/**
 * cutting_line - Split a line into tokens (very naively).
 * @line: The line comands.
 * Return: Null-terminated array of tokens.
 */

char **cutting_line(char *line)
{
	int bufsize = TOK_BUFSIZE, position = 0;
	char **tokens_args = malloc(bufsize * sizeof(char *));
	char *token_args;

	if (tokens_args == NULL)
	{
		write(STDOUT_FILENO, "hsh: allocation error\n", 23);
		exit(EXIT_FAILURE);
	}
	token_args = strtok(line, TOK_DELIM);
	while (token_args != NULL)
	{
		tokens_args[position] = token_args;
		if (tokens_args[position] == NULL)
		{
			free(tokens_args);
			return (NULL);
		}
		position++;
		token_args = strtok(NULL, TOK_DELIM);
	}
	tokens_args[position] = NULL;
	return (tokens_args);
}

/**
 * hsh_launch - Launch a program and wait for it to terminate.
 * @args: Null terminated list of arguments (including program).
 * @path: Path.
 * @count: general counter
 * @exe_file: name of the executable file of shell [hsh].
 * Return: Always returns 1, to continue execution.
 */

int hsh_launch(char *path, char **args, int count, char *exe_file)
{
	pid_t child;
	int status;

	child = fork();
	if (child == 0)
	{/* Child process */
		if (execve(path, args, NULL) == -1)
		{
			write(STDOUT_FILENO, exe_file, _strlen(exe_file));
			write(STDOUT_FILENO, ": ", 2);
			print_numbers(count);
			write(STDOUT_FILENO, ": ", 2);
			write(STDOUT_FILENO, args[0], _strlen(args[0]));
			write(STDOUT_FILENO, ": ", 2);
			write(STDOUT_FILENO, "not found\n", 11);
			if (args[0][0] == '/')
			{free(path); }
			return (-1);
		}
		if (args[0][0] == '/')
		{free(path); }
		if (isatty(fileno(stdin)) == 0)
		{return (-1); }
		return (0);
	}
	else if (child < 0)
	{perror("hsh"); }
	else
	{/* Parent process */
		do {
			waitpid(child, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (0);
}

/**
 * hsh_exec - Execute shell built-in or launch program.
 * @args: Null terminated list of arguments.
 * @path: Path.
 * @env: sys variable.
 * @exe_file: name of the executable file of shell [hsh].
 * @count: General counter.
 * Return: 1 if the shell should continue running, 0 if it should terminate
 */

int hsh_exec(char *path, char **args, char **env, int count, char *exe_file)
{
	char *builtin_str[] = {"cd", "exit", "help"};
	int count_builtin = 0, x = 0;

	if (args[0] == NULL)
	{
		return (0);
	}
	if (_strcmp(args[0], "env") == 0)
	{
		while (env[x] != NULL)
		{
			write(STDOUT_FILENO, env[x], _strlen(env[x]));
			write(STDOUT_FILENO, "\n", sizeof(char));
			x++;
		}
	}

	for (count_builtin = 0; count_builtin < hsh_num_builtins(); count_builtin++)
	{
		if (_strcmp(args[0], builtin_str[count_builtin]) == 0)
		{
			return ((*builtin_func[count_builtin])(args));
		}
	}
	return (hsh_launch(path, args, count, exe_file));
}
