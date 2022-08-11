#include "main.h"

/**
 * output_decimal - function to write decimal to standard output
 * @number: decimal number to write to standard output
 * Return: number of characters writteen to standard output
 */

int output_decimal(int number)
{
	int count = 0;

	if (number < 0)
	{
		count += _putchar('-');
		number *= -1;
	}

	if (number / 10)
	{
		count += output_decimal(number / 10);
	}

	count += _putchar((number % 10) + '0');

	return (count);
}

/**
 * power - function to calculate power arithmetic
 * @base: the base number
 * @a: the power
 * Return: the result of the base raised to a
 */

long long int power(int base, int a)
{
	int result = 1;

	for (a; a > 0; a--)
	{
		result *= base;
	}

	return (result);
}

/**
 * number_to_base_10 - return the base 10 equivalent of a number
 * @number: number to be converted to base number
 * @base: the current base of the number
 * Return: the base 10 equivalent of the number
 */

long long number_to_base_10(int number, int base)
{
	int result = 0, i = 0;

	while (number != 0)
	{
		result += (number % 10) * power(base, i);
		i++;
		number /= 10;
	}

	i = 1;

	return (result);
}

/**
 * output_binary - function to write binary to standard output
 * @number: decimal number to write as binary to standard output
 * Return: number of characters writteen to standard output
 */

int output_binary(int number)
{
	int binary_buffer[32], i = 0, count = 0;

	while (number >= 2)
	{
		binary_buffer[i] = number % 2;
		number /= 2;
		i++;
	}

	binary_buffer[i] = number;

	for (i; i >= 0; i--)
	{
		count += _putchar(binary_buffer[i] + '0');
	}

	return (count);
}

/**
 * output_unsigned_int - function to write unsigned int to standard output
 * @number: decimal number to write to standard output
 * Return: number of characters writteen to standard output
 */

int output_unsigned_int(unsigned int number)
{
	int count = 0;

	if (number / 10)
		count += output_decimal(number / 10);

	count += _putchar(number % 10 + '0');

	return (count);
}
