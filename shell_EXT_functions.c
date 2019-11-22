#include "holberton.h"

/**
 * str_concat - concatenate two strings.
 * @str_1: First string
 * @str_2: Second string
 * Return: the concatenated chain.
 */

char *str_concat(char *str_1, char *str_2)
{
	int x = 0, y = 0, concat, concat2;
	char *Arr_concat;

	if (str_1 == NULL)
		str_1 = "";
	if (str_2 == NULL)
		str_2 = "";

	while (str_1[x])
		x++;
	while (str_2[y])
		y++;

	Arr_concat = malloc(sizeof(char) * (x + (y + 1)));

	if (Arr_concat == NULL)
		return (NULL);

	for (concat = 0; concat < x; concat++)
		Arr_concat[concat] = str_1[concat];

	concat2 = concat;

	for (concat = 0; concat <= y; concat++)
	{
		Arr_concat[concat2] = str_2[concat];
		concat2++;
	}

	return (Arr_concat);
}

/**
 * _strcmp - function that compare to string.
 * @s1: String 1
 * @s2: Sstring 2
 * Return: Always 0 if two strings are equal.
 */

int _strcmp(char *s1, char *s2)
{
	int x;

	while (*s1 && *s2)
	{
		if (*s1 != *s2)
		{
			x = *s1 - *s2;
			return (x);
		}
		s1++;
		s2++;
	}

	if (*s1 == *s2)
	{
		return (0);
	}
	else
	{
		if (*s1 < *s2)
		{
			return (-1);
		}
		else
		{
			return (1);
		}
	}
}

/**
 * split_path - check the code for Holberton School students.
 * @env: sys variable.
 * Return: the token of comand in.
 */

char **split_path(char *env[])
{
	int count_env, count = 0, cmp = 0, aux;
	char *path = "PATH";
	char *token = NULL, *token_path = NULL;
	char **token_path_split = NULL, **enviroment = NULL;

	token_path_split = malloc(64 * sizeof(char *));
	if (token_path_split == NULL)
	{
		write(STDOUT_FILENO, "hsh: allocation error\n", 24);
		exit(EXIT_FAILURE);
	}
	enviroment = env;
	/* EL PROBLEMA ESTA AQUI, en resetear el ENV */
	for (count_env = 0; enviroment[count_env] != NULL; count_env++)
	{
		token = strtok(enviroment[count_env], "=");
		for (aux = 0; token[aux] && path[aux]; aux++)
		{
			cmp = token[aux] - path[aux];
		}
		cmp = _strcmp(enviroment[count_env], path);
		if (cmp == 0)
		{
			token = strtok(NULL, "=");
			token_path = strtok(token, ":");
			while (token_path != NULL)
			{
				token_path_split[count] = token_path;
				token_path = strtok(NULL, ":");
				count++;
			}
		}
	}
	token_path_split[count] = NULL;
	return (token_path_split);
}

/**
 * path_concat - concatenate two strings.
 * @args: Second string
 * @path: first string
 * Return: the concatenated chain.
 */

char *path_concat(char **args, char **path)
{
	char *path_complete = NULL;
	int len = 0, ok_access = 0, count_access = 0;

	while (path[len] != NULL)
	{/* Count all Tokens of PATH */
		len++;
	}
	while (path[count_access] != NULL)
	{
		path_complete = str_concat(path[count_access], "/");
		path_complete = str_concat(path_complete, args[0]);
		ok_access = access(path_complete, X_OK);
		if (ok_access == 0)
		{
			return (path_complete);
		}
		count_access++;
	}
	return (path_complete);
}
