#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _strlen - returns the length of a string
 * @s: pointer referencing the string
 * Return: length of the string
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i])
		i++;

	return (i);
}

/**
 * _strncpy - function that copies a string
 * @dest: the destination
 * @src: the source
 * Return: the pointer to the destination
 */
char *_strncpy(char *dest, char *src)
{
	int count;
	int n = _strlen(src);

	for (count = 0; count < n && src[count] != '\0'; count++)
		dest[count] = src[count];

	for ( ; count < n; count++)
		dest[count] = '\0';

	return (dest);
}

/**
 * _strrev - function that reverses a string
 * @str: the string to reverse
 * Return: the reversed string
 */
char *_strrev(char *str)
{
	int i;
	int len = 0;
	char c;

	if (!str)
		return (NULL);

	while (str[len] != '\0')
	{
		len++;
	}

	for (i = 0; i < (len / 2); i++)
	{
		c = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = c;
	}

	return (str);
}

/**
 * _itoa - function converts numbers to strings
 * @i: the data
 * @strout: the destination
 * @base: the number base
 * Return: the pointer to the output string
 */
char *_itoa(int i, char *strout, int base)
{
	char *str = strout;
	int digit, sign = 0;

	if (i < 0)
	{
		sign = 1;
		i *= -1;
	}

	while (i)
	{
		digit = i % base;
		*str = (digit > 9) ? ('A' + digit - 10) : '0' + digit;
		i = i / base;
		str++;
	}

	if (sign)
	{
		*str++ = '-';
	}

	*str = '\0';

	_strrev(strout);

	return (strout);
}

/**
 * _printf - function that prints to standard output
 * @str: the string format
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list vl;
	int i = 0, j = 0;
	int temp_unsigned_int;
	char final[4];
	char buff[1000] = {0}, tmp[20];
	char *str_arg;

	va_start(vl, format);

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					buff[j] = (char)va_arg(vl, int);
					j++;
					break;
				case 'd':
					_itoa(va_arg(vl, int), tmp, 10);
					_strncpy(&buff[j], tmp);
					j += _strlen(tmp);
					break;
				case 'i':
					temp_unsigned_int = va_arg(vl, int);
					if (temp_unsigned_int < 0)
						temp_unsigned_int *= -1;
					_itoa(temp_unsigned_int, tmp, 10);
					_strncpy(&buff[j], tmp);
					j += _strlen(tmp);
					break;
				case 's':
					str_arg = va_arg(vl, char*);
					_strncpy(&buff[j], str_arg);
					j += _strlen(str_arg);
					break;
				case '%':
					str_arg = "%";
					_strncpy(&buff[j], str_arg);
					j += _strlen(str_arg);
					break;
				default:
					final[0] = '%';
					final[1] = format[i];
					_strncpy(&buff[j], final);
					j += _strlen(final);
					break;
			}
		}
		else
		{
			buff[j] = format[i];
			j++;
		}
		i++;
	}

	int k = 0;

	while (buff[k])
	{
		write(1, &buff[k], 1);

		k++;
	}
	va_end(vl);
	return (j);
}
