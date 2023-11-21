#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int _printf(const char *const fmt, ...)
{
	/*va_list args;*/
	size_t index;
	char ch;

	index = 0;

	if (!fmt)
		return EXIT_FAILURE;

	while ((ch = fmt[index]))
	{
		if (ch != '%')
		{
			putchar(ch);
		}
		index++;
	}
	return EXIT_SUCCESS;
}