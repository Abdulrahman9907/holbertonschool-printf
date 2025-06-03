#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

/**
* _printf - prints outpit like printf
* @format: character string somposed of zero or more directives
**/

int _putchar(char c) {
    write(STDOUT_FILENO, &c, 1);
    return 1;
}

int _print_string(const char *str)
{
  int count = 0;

  if (!str)
    str = "NULL";

while (*str)
_putchar(*str);
str++;
count++;

return count;
}

int _printf(const char *format, ...)
{
int num = 0;
const char *str;
va_list argc;

va_start(argc, format);

if (*format == '%')
format++;

while(*format)
{
if (*format == 's')
str = va_arg(argc, const char*);
num += _print_string(str);
break;
}


return(num);
}
