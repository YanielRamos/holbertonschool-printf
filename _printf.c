#include "main.h"

/**
 * _printf - function that produces output according to a format
 * @format: string
 * Return: value
 */

int _printf(const char *format, ...)
{
	va_list ls;
	char c;
	const char *s;
	int counter;

	va_start(ls, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;

			switch (*format)
			{
				case 'c':
					{
						c = va_arg(ls, int);
						putchar(c);
						counter++;
						break;
					}
				case 's':
					{
						s = va_arg(ls, char *);
						while (*s != '\0')
						{

							putchar(*s);
							s++;
							counter++;
						}
						break;
					}
				case '%':
					{
						putchar('%');
						counter++;
						break;
					}
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
