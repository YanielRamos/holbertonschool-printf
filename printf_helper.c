#include "main.h"


/**
 * print_char - function that prints a character
 * @ls: list with elements
 * @counter: position in string
 * Return: amount 
 */
int print_char(va_list ls, int *counter)
{
	char c;

	c = (char)va_arg(ls, int);

	if (c == '\0')
		return (-1);

	putchar(c);
	(*counter)++;
	return (1);
}

/**
 * print_string - function that print a string
 * @ls: list with elements
 * @s: string to print
 */
int print_string(va_list ls, int *counter)
{
	const char * s;
	int str = 0;

	s = va_arg(ls, const char *);
	if (s == NULL)
	{
		s = "(null)";
	}

	while (*s != '\0')
	{
		putchar(*s);
		s++;
		(*counter)++;
		str++;
	}
	return (str);
}

/**
 * print_percent - function that prints a percent sign
 * @counter: the position in the string
 */
int print_percent(int *counter)
{
	char p = '%';

	putchar(p);
	(*counter)++;
	return (1);
}
