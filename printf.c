#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"



int print_by_specification(char *character, va_list args)
{
        double fval;
	int length;

        switch (*character)
        {
                case 'c':
               	        length = printf_char(args);
                        break;
                case 'd':
                        length = printf_integer(args);
                        break;
                case 'f':
                        fval = va_arg(args, double);
                        printf("%f", fval);
                        break;
                case 's':
                        length = printf_string(args);
                        break;
                default:
                        _putchar(*character);
			length = 1;
			break;
        }
	
	return (length);
}


int _printf(const char *const fmt, ...)
{
	va_list args;
	size_t index;
	char ch;
	int length = 0;

	index = 0;

	if (!fmt)
		return (-1);

	va_start(args, fmt);

	for (index = 0; fmt[index]; index++)
	{

		if (fmt[index] != '%')
		{
			_putchar(fmt[index]);
			length++;
		}
		else
		{
		index++;
		ch = fmt[index];
		length += print_by_specification(&ch, args);
		}

	}
	va_end(args);
	return (length);
}
