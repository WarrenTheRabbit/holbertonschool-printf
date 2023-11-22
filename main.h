#include <stdarg.h>
#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>

int _putchar(char c);
int _printf(const char *format, ...);
int printf_char(va_list val);
int printf_string(va_list val);
int _strlen(char *str);
int _strlenc(const char *str);
int print_integer_recursive(int num);

#endif
