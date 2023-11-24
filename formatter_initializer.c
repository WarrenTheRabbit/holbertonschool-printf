#include <stddef.h>
#include "main.h"
/**
 * initialise_formatters - Initializes the array of format specifiers
 * @specification: Array of Formatter structures
 */
void initialise_formatters(Formatter *specification)
{
	int i = 0;

	for (i = 0; i < 256; i++)
	{
		specification[i] = (Formatter){ '\0', NULL };
	}

	specification['c'] = (Formatter){ .symbol = 'c', .print = printf_char };
	specification['s'] = (Formatter){ .symbol = 's', .print = printf_string };
	specification['d'] = (Formatter){ .symbol = 'd', .print = printf_integer };
	specification['i'] = (Formatter){ .symbol = 'i', .print = printf_integer };
	specification['%'] = (Formatter){ .symbol = '%', .print = print_percent };
}
