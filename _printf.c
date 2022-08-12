#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - function to emulate the print function
 * @format: the character format
 * Return: number of characters writteen to standard output
 */

int _printf(const char *format, ...)
{
	int char_count = 0, i;
	va_list input_data;

	va_start(input_data, format);
	if (!format)
		return (-1);
	for (i = 0; format[i] != '\0';)
	{
		if (format[i] != '%')
		{
			char_count += _putchar(format[i]);
			i++;
		}
		else if (format[i] == '%' && format[i + 1] != ' ')
		{
			/* The switch ststement is more appropriate but I'll be violating betty's */
			/* 40 lines per function rule */
			s = format[i + 1];
			if (s == 'c')
				char_count += _putchar(va_arg(input_data, int));
			if (s == 's')
				char_count += output_string(va_arg(input_data, char *));
			if (s == '%')
				char_count += _putchar('%');
			if (s == 'd' || s == 'i')
				char_count += output_decimal(va_arg(input_data, int));
			if (s == 'u')
				char_count += output_unsigned_int(va_arg(input_data, unsigned int));
			if (s == '\0')
				return (-1);
			if (s != 'c' && s != 's' && s != '%' && s != 'd'
					&& s != 'i' && s != 'u' && s != '\0')
			{
				char_count += _putchar('%');
				char_count += _putchar(format[i + 1]);
			}
			i += 2;
		}
	}
	return (char_count);
}
