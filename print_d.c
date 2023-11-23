#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/** printf_integer_recursive - prints a single or multi digit integer
* @num: a single or multi digit integer
* Return: The length of the integer
*/
int print_integer_recursive(int num)
{
	if (num < 0)
	{
		_putchar('-');
		num = -num;
	}

	if (num / 10)
	{
		int len = print_integer_recursive(num / 10);

		_putchar(num % 10 + '0');
		return len + 1;
	}
	else
	{
		_putchar(num % 10 + '0');
		return 1;
	}
}

/* printf_integer - prints an integer
 * @val: arguments
 * Return: the length of the integer
 */
int printf_integer(va_list val)
{
	int num = va_arg(val, int);
	return print_integer_recursive(num);
}
