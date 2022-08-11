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
	for (i = 0; format[i] != '\0';)
	{
		if (format[i] != '%')
		{
			char_count += _putchar(format[i]);
			i++;
		}
		else if (format[i] == '%' && format[i + 1] != ' ')
		{
			switch (format[i + 1])
			{
				case 'c':
					char_count += _putchar(va_arg(input_data, int));
					break;
				case 's':
					char_count += output_string(va_arg(input_data, char *));
					break;
				case '%':
					char_count += _putchar('%');
					break;
				case 'd':
					char_count += output_decimal(va_arg(input_data, int));
					break;
				case 'i':
					char_count += output_decimal(va_arg(input_data, int));
					break;
				case 'u':
					char_count += output_unsigned_int(va_arg(input_data, unsigned int));
					break;
				default:
					break;
			}
			i += 2;
		}
	}
	return (char_count);
}
