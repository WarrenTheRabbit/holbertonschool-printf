#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdarg.h>

int _putchar(char c);
int _printf(const char *format, ...);
int printf_char(va_list val);
int printf_string(va_list val);
int _strlen(char *str);
int _strlenc(const char *str);
int print_37(void);
int print_integer_recursive(int num);
int printf_integer(va_list val);
int print_percent(va_list val);
typedef struct
{
	char symbol;
	int (*print)(va_list args);
} Formatter;
int handle_char(va_list args);
void initialise_formatters(Formatter *specification);

#endif
