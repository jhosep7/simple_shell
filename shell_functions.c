#include "holberton.h"

/**
   @brief Split a line into tokens (very naively).
   @param line The line.
   @return Null-terminated array of tokens.
 */

char **lsh_split_line(char *line)
{
  int bufsize = LSH_TOK_BUFSIZE, position = 0;
  char **tokens = malloc(bufsize * sizeof(char*));
  char *token, **tokens_backup;

  if (!tokens) {
    fprintf(stderr, "lsh: allocation error\n");
    exit(EXIT_FAILURE);
  }

  token = strtok(line, LSH_TOK_DELIM);
  while (token != NULL) {
    tokens[position] = token;
    position++;

    if (position >= bufsize) {
      bufsize += LSH_TOK_BUFSIZE;
      tokens_backup = tokens;
      tokens = realloc(tokens, bufsize * sizeof(char*));
      if (!tokens) {
		free(tokens_backup);
        fprintf(stderr, "lsh: allocation error\n");
        exit(EXIT_FAILURE);
      }
    }

    token = strtok(NULL, LSH_TOK_DELIM);
  }
  tokens[position] = NULL;
  return tokens;
}

/**
 * read_line_of_comands - Function that read all comands that user in.
 * Return: Always 0.
 */

char *read_line_of_comands(void)
{
	int bufsize = READLINE_BUFSIZE;
	int position = 0;
	char *buffer = malloc(sizeof(char) * bufsize);
	int Char_by_char;

	if (buffer == NULL)
	{
		printf("hsh: allocation error\n");
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		Char_by_char = getchar(); /* Read a character */
		if (Char_by_char == EOF)
		{
			exit(EXIT_SUCCESS);
		}
		else if (Char_by_char == '\n')
		{
			buffer[position] = '\0';
			return (buffer);
		}
		else
		{
			buffer[position] = Char_by_char;
		}
		position++;
		/* If we have exceeded the buffer, reallocate. */
		if (position >= bufsize)
		{
			bufsize += READLINE_BUFSIZE;
			buffer = realloc(buffer, bufsize);
			if (buffer == NULL)
			{
				printf("hsh: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
	}
}
