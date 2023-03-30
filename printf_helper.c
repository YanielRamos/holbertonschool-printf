#include "main.h"


/**
 * print_char - function that prints a character
 * @ls: list with elements
 * @counter: sum of character printed
 * Return: amount of charcter printed in function
 */
int print_char(va_list ls, int *counter)
{
	char c;

	c = va_arg(ls, int);


	_putchar(c);
	(*counter)++;
	return (1);
}

/**
 * print_string - function that print a string
 * @ls: list with elements
 * @counter: sum of character printed
 * Return: str with the total of character printed in function
 */
int print_string(va_list ls, int *counter)
{
	const char *s;
	int str = 0;

	s = va_arg(ls, const char *);
	if (s == NULL)
	{
		s = "(null)";
	}

	while (*s != '\0')
	{
		_putchar(*s);
		(*counter)++;
		str++;
		s++;
	}
	return (str);
}

/**
 * print_percent - function that prints a percent sign
 * @counter: the position in the string
 * Return: character printed
 */
int print_percent(int *counter)
{
	char p = '%';

	_putchar(p);
	(*counter)++;
	return (1);
}

/**
 * print_int - function that prints a integer
 * @ls: list with elements
 * @counter: amount of character printed
 * Return: amount of characters printed
 */
int print_int(va_list ls, int *counter)
{
	int value = va_arg(ls, int), num_digit, temp, i, digit, divisor = 1, ret = 0;
	char prt;

	if (value < 0)
	{
		_putchar('-');
		value = -value;
		(*counter)++;
		ret++;
	}

	num_digit = 0, temp = value;
	while (temp != 0)
	{
		num_digit++;
		temp /= 10;
	}

	if (num_digit == 0)
	{
		prt = '0';
	}
	else
	{
		for (; num_digit > 0; num_digit--)
		{

			for (i = 1; i < num_digit; i++)
			{
				divisor *= 10;
			}
			digit = value / divisor;
			value -= digit * divisor;
			prt = (digit % 10) + '0';
			_putchar(prt);
			(*counter)++;
			ret++;
		}
	}
	return (ret);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{

	return (write(1, &c, 1));

}
