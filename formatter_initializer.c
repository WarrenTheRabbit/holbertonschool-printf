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
		specification[i].symbol = '\0';
		specification[i].print = NULL;
	}

	specification['c'].symbol = 'c';
	specification['c'].print = printf_char;
	specification['s'].symbol = 's';
	specification['s'].print = printf_string;
	specification['d'].symbol = 'd';
	specification['d'].print = printf_integer;
	specification['d'].symbol = 'd';
	specification['i'].symbol = 'i';
	specification['i'].print = printf_integer;
	specification['%'].symbol = '%';
	specification['%'].print = print_percent;
}
