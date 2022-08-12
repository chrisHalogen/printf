#include "main.h"

/**
 * output_string - function that writes string to standard output
 * @string: the pointer to the string
 * Return: num of characters writteen to standard output
 */

int output_string(char *string)
{

	int count = 0, i;

	if (!string)
		return (output_string("(null)"));

	for (i = 0; string[i] != '\0'; i++)
	{
		count += _putchar(string[i]);
	}

	return (count);
}
