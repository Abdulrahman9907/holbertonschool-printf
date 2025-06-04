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
  {
	str = "NULL";
  }

while (*str)
{
	_putchar(*str);
	str++;
	count++;
}

return (count);
}

int _printf(const char *format, ...)
{
int num = 0, ch;
const char *str;
va_list args;

va_start(args, format);

while(*format)
{
        if (*format == '%' && *(format + 1))
        {
		format++;
        switch(*format)
        {
                case 's': {

                        str = va_arg(args, const char*);
                        num += _print_string(str);
                        break;
                          }
		case 'c': {

                        ch = va_arg(args, int);
                        num += _putchar(ch);
                        break;
                          }
		default: {
			_putchar('%');
			_putchar(*format);
			num += 2;
			break;
		 	}
	}
	}
	else
	{
		_putchar(*format);
		num++;
	}
        format++;
}

va_end(args);
return(num);
}
