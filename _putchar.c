#include <unistd.h>

/**
 * _putchar - function to write to the standard output
 * @c: the character to write to the standard output
 * Return: number of characters writteen to standard output
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
