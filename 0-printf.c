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
* _printf - custom implementation of printf function
* @format: character string composed of zero or more directives
* Description: This function produces output according to a format string.
* It handles basic format specifiers like %s (string) and %c (character).
* For unknown specifiers, it prints the % and the character literally.
* This is a simplified version of the standard printf function.
* Supported format specifiers:
* - %s: prints a string
* - %c: prints a character
* - %%: prints a literal % character
* Return: The number of characters printed (excluding null terminator)
*/
int _printf(const char *format, ...)
{
int num = 0, ch;
const char *str;
va_list args;

va_start(args, format);
while (*format)
{
if (*format == '%')
{
format++;
	if (*format == '\0')
	{
		va_end(args);
		return (-1);
	}
switch (*format)
{
case 's':
	str = va_arg(args, const char *);
	num += print_string(str);
break;
case 'c':
ch = va_arg(args, int), num += _putchar(ch);
break;
case '%':
	num += _putchar('%');
	break;
default:
_putchar('%'), _putchar(*format), num += 2;
break;
}
}
else
{
_putchar(*format), num++;
}
format++;
}
va_end(args);
return (num);
}
