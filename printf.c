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

	index = 0;

	if (!fmt)
		return EXIT_FAILURE;

	va_start(args, fmt);

	for (index = 0; fmt[index]; index++)
	{
		ch = fmt[index];

		if (ch != '%')
		{
			_putchar(fmt[index]);
			continue;
		}

		index++;

	
		/* I will refactor this section so that switch statements
		 * are not necessary. */

		switch (fmt[index])
		{
		case 'c':
			printf_char(args);
			break;
		case 'd':
			printf_integer(args);
			break;
		case 'f':
			fval = va_arg(args, double);
			printf("%f", fval);
			break;
		case 's':
			printf_string(args);
			break;
		default:
			_putchar(fmt[index]);
		}
	}
	va_end(args);
	return EXIT_SUCCESS;
}
