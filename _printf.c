#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - function that produces output according to a format
 * @format: string
 * Return: value
 */

int _printf(const char *format, ...)
{
	va_list ls;
	int counter = 0;

	va_start(ls, format);

	if (ls == NULL || format == NULL)
		return (-1);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;

			switch (*format)
			{
				case 'c':
						print_char(ls, &counter);
						break;
				case 's':
						print_string(ls, &counter);
						break;
				case '%':
						print_percent(&counter);
						break;
			}
		}
		else
		{
			putchar(*format);
			counter++;
		}
	format++;
	}
	va_end(ls);
	return (counter);
}
