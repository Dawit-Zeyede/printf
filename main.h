#ifndef PRINTF_HEADER
#define PRINTF_HEADER
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
int _putchar(char c);
int _printf(const char *format, ...);
int format_spec(const char *fo, int *i, int *b, char *buf, int co, va_list arg);
int format_char(int *b, char *buf, int co, va_list arg);
void printer(char buffer[], int len);
#endif
