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
	float fval;
	int length = 0;

	index = 0;

	if (!fmt)
		return -1;

	va_start(args, fmt);

	for (index = 0; fmt[index]; index++)
	{
		ch = fmt[index];

		if (ch != '%')
		{
			_putchar(fmt[index]);
			length++;
			continue;
		}

		index++;

		switch (fmt[index])
		{
		case 'c':
			length += printf_char(args);
			break;
		case 'd':
		case 'i':
			length += printf_integer(args);
			break;
		case 'f':
			fval = va_arg(args, double);
			printf("%f", fval);
			break;
		case 's':
			length += printf_string(args);
			break;
		case '\0':
			return -1;
		case '!':
		case 'K':
			_putchar(fmt[index - 1]);
			length++;
			_putchar(fmt[index]);
			length++;
			break;
		default:
			_putchar(fmt[index]);
			length++;
		}
	}
	va_end(args);
	return length;
}
