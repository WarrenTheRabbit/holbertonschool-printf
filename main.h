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
int handle_char(va_list args);
int handle_integer(va_list args);
int handle_string(va_list args);
int handle_format_specifier(const char *fmt, size_t *index, va_list args);

#endif
