#include "holberton.h"

int (*builtin_func[]) (char **) = {&hsh_cd, &hsh_exit};

/**
 * read_line_of_comands - Function that read all comands that user in.
 * Return: Always 0.
 */

char *read_line_of_comands(void)
{
/*	size_t bufsize = READLINE_BUFSIZE;
	ssize_t test;
        char *buffer = malloc(sizeof(char) * bufsize); */

        char *line = NULL;
	size_t bufsize = READLINE_BUFSIZE;
	ssize_t test = 0;

/*	test = read(STDIN_FILENO, buffer, (sizeof(char) * (bufsize)));

	printf("TEST %lu", test);
	if (test < 0)
	{
		exit(EXIT_FAILURE);
	}
	buffer[test] = '\0';
	return (buffer); */

	test = getline(&line, &bufsize, stdin);
	if (test < 0)
	{
		exit(EXIT_FAILURE);
	}
	return (line);
}


/**
 * split_line - Split a line into tokens (very naively).
 * @line: The line comands.
 * Return: Null-terminated array of tokens.
 */

char **split_line(char *line)
{
	int bufsize = TOK_BUFSIZE, position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token, **tokens_backup;

	if (tokens == NULL)
	{
		write(STDOUT_FILENO, "hsh: allocation error\n", 100);
		exit(EXIT_FAILURE);
	}
	token = strtok(line, TOK_DELIM);
	while (token != NULL)
	{
		tokens[position] = token;
		position++;
		if (position >= bufsize)
		{
			bufsize += TOK_BUFSIZE;
			tokens_backup = tokens;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (tokens == NULL)
			{
				free(tokens_backup);
				write(STDOUT_FILENO, "hsh: allocation error\n", 100);
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, TOK_DELIM);
	}
	tokens[position] = NULL;
	return (tokens);
}

/**
 * hsh_launch - Launch a program and wait for it to terminate.
 * @args: Null terminated list of arguments (including program).
 * Return: Always returns 1, to continue execution.
 */

int hsh_launch(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{/* Child process */
		if (execvp(args[0], args) == -1)
		{
			perror("hsh");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{/* Error forking */
		perror("hsh");
	}
	else
	{/* Parent process */
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}

/**
 * hsh_execute - Execute shell built-in or launch program.
 * @args: Null terminated list of arguments.
 * Return: 1 if the shell should continue running, 0 if it should terminate
 */

int hsh_execute(char **args)
{
	char *builtin_str[] = {"cd", "exit"};
	int i = 0, j = 0, rest;

	if (args[0] == NULL)
	{
		return (1);
	}

	for (i = 0; i < hsh_num_builtins(); i++)
	{
		for (j = 0; args[0][j] != '\0' &&
			     builtin_str[i][j] != '\0'; j++)
		{
			rest = args[0][j] - builtin_str[i][j];
			if (rest == 0)
			{
				return ((*builtin_func[i])(args));
			}
		}
/*		if (strcmp(args[0], builtin_str[i]) == 0)
		{
			return ((*builtin_func[i])(args));
			}*/
	}

	return (hsh_launch(args));
}
