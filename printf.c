#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

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

	while (fmt[index])
	{
		ch = fmt[index];

		if (ch != '%')
		{
			_putchar(ch);
			length++;
		}
		else
		{
			index++;
			length += handle_format_specifier(fmt, &index, args);
		}

		index++;
	}

	va_end(args);
	return (length);
}

int handle_char(va_list args)
{
	char c = va_arg(args, int);
	_putchar(c);
	return (1);
}

int handle_integer(va_list args)
{
	int num = va_arg(args, int);
	return (print_integer_recursive(num));
}

int handle_string(va_list args)
{
	char *str = va_arg(args, char *);
	return (printf_string(str));
}

int handle_format_specifier(const char *fmt, size_t *index, va_list args)
{
	char specifier = fmt[*index];

	switch (specifier)
	{
	case 'c':
		return (handle_char(args));
	case 'd':
		return (handle_integer(args));
	case 'f':
		{
			double fval = va_arg(args, double);
			printf("%f", fval);
			break;
		}
	case 's':
		return (handle_string(args));
	case '\0':
		return (-1);
	case '!':
	case 'K':
		_putchar(fmt[*index - 1]);
		_putchar(fmt[*index]);
		return (2);
	default:
		_putchar(specifier);
		return (1);
	}
	return (0);
}
