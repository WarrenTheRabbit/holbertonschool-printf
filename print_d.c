#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/* printf_integer - prints a singe or multi digit integer
 * @val: variable length argument list
 * Return: the length of the integer
 */
int printf_integer(va_list val)
{
	long num = va_arg(val, int);
	char buffer[20];
	int i, len = 0, digitCount = 0;

	if (num == 0)
	{
		_putchar('0');
		++digitCount;
		return digitCount;
	}

	if (num < 0)
	{
		_putchar('-');
		num = -num;
		digitCount++;
	}

	while (num)
	{
		buffer[len++] = num % 10 + '0';
		num /= 10;
		digitCount++;
	}

	for (i = len - 1; i >= 0; i--)
	{
		_putchar(buffer[i]);
	}
	return digitCount;
}
