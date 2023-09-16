#ifndef PRINTF_HEADER
#define PRINTF_HEADER
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
int _putchar(char c);
int _printf(const char *format, ...);
int format_handler(const char *format, int *i, int *bu, char *buffer, int count, va_list arglist);
int format_char(int *bu, char *buffer, int count, va_list arglist);
void printer(char buffer[], int len);
#endif
