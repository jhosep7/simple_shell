#include "holberton.h"

/**
 * print_numbers - Print integers
 * @our_digit: the number that i want to print it.
 * Return: Always 0 if the functions works.
 */

int print_numbers(int our_digit)
{
	unsigned int x, count = 0;

	if (our_digit < 0)
	{
		_our_write('-');
		our_digit = -our_digit;
		count = 1;
	}
	x = our_digit;

	if (x / 10)
		print_numbers(x / 10);

	_our_write(x % 10 + '0');

	for (; x >= 10; count++)
	{
		x = x / 10;
	}
	count += 1;
	return (count);
}
