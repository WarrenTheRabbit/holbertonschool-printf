#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
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

/**
 * print_by_specification - Prints a value based on the format specifier
 * @character: Format specifier character
 * @args: Variable arguments list
 * Return: The number of characters printed
 */
int print_by_specification(char character, va_list args)
{
	int length;

	Formatter specification[256];

	initialise_formatters(specification);

	if (specification[(int)character].print)
	{
		length = specification[(int)character].print(args);
	}
	else
	{
		_putchar('%');
		_putchar(character);
		length = 2;
	}

	return (length);
}

/**
 * _printf - produces output according to a format
 * @fmt: the format
 * Return: the number of characters printed
 */
int _printf(const char *const fmt, ...)
{
	va_list args;
	size_t index;
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
		else if (fmt[index] == '%' && fmt[index + 1] == '\0')
		{
			return (-1);
		}
		else
		{
			index++;
			length += print_by_specification(fmt[index], args);
		}
	}

	va_end(args);

	return (length);
}
