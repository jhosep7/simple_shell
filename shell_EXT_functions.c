#include "holberton.h"

/**
 * str_concat - check the code for Holberton School students.
 * @s1: Lol
 * @s2: Lol
 * Return: Always 0.
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
