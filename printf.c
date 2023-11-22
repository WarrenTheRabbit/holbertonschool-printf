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
	int cval, dval;
	char *sval;

	index = 0;

	if (!fmt)
		return EXIT_FAILURE;

	va_start(args, fmt);

	for (index = 0; fmt[index]; index++)
	{
		ch = fmt[index];

		if (ch != '%')
		{
			putchar(fmt[index]);
			continue;
		}

		index++;
		switch (fmt[index])
		{
		case 'c':
			cval = va_arg(args, int);
			printf("%c", cval);
			break;
		case 'd':
			dval = va_arg(args, int);
			printf("%d", dval);
			break;
		case 'f':
			fval = va_arg(args, double);
			printf("%f", fval);
			break;
		case 's':
			sval = va_arg(args, char *);
			printf("%s", sval);
			break;
		default:
			putchar(fmt[index]);
		}
	}
	va_end(args);
	return EXIT_SUCCESS;
}