#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

/**
* _putchar - writes a character to stdout
* @c: The character to print
*
* Description: This function writes a single character to the standard
* output using the write system call. It's a helper function for our
* custom printf implementation.
*
* Return: On success 1, on error -1
*/
int _putchar(char c)
{
write(STDOUT_FILENO, &c, 1);
return (1);
}

/**
* print_string - prints a string to stdout
* @str: The string to be printed
*
* Description: This function prints a string character by character
* using _putchar. If the input string is NULL, it prints "NULL".
* It counts and returns the number of characters printed.
*
* Return: The number of characters printed
*/
int print_string(const char *str)
{
int count = 0;

if (!str)
{
str = "(null)";
}
while (*str)
{
_putchar(*str);
str++;
count++;
}
return (count);
}

/**
 * print_number - print a number
 * @n: contain a number to print
 * Return: The number of numbers printed
 */
int print_number(int n)
{
	int count = 0;
	unsigned int num;

	if (n < 0)
	{
		count += _putchar('-');
		num = (unsigned int)(-(long)n);
	}
	else
	{
		num = (unsigned int)n;
	}

	if (num / 10)
	{
		count += print_number((num / 10));
	}

	count += _putchar((num % 10) + '0');

	return (count);
}

/**
 * handle_format - Handles format specifier
 * @format: The specifier character
 * @args: The variadic arguments list
 *
 * Return: Number of characters printed
 */
int handle_format(char format, va_list args)
{
	int ch;
	const char *str;

	switch (format)
	{
	case 's':
		str = va_arg(args, const char *);
		return (print_string(str));
	case 'c':
		ch = va_arg(args, int);
		return (_putchar(ch));
	case 'd':
	case 'i':
		return (print_number(va_arg(args, int)));
	case '%':
		return (_putchar('%'));
	default:
		_putchar('%');
		_putchar(format);
		return (2);
	}
}

/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int num = 0;

	if (!format)
		return (-1);

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (!*format)
				return (-1);
			num += handle_format(*format, args);
		}
		else
		{
			num += _putchar(*format);
		}
		format++;
	}
	va_end(args);
	return (num);
}
