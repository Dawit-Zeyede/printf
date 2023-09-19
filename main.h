#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int _printf(const char *format, ...);
void printer(char buffer[], int *p);
int format_handler(const char *format, int *i, va_list args, char buffer[], int flag, int width, int precision, int modifier);
int print_char(va_list args, char buffer[], int flags, int width, int precision, int modifier);
int print_string(va_list args, int flags, int width, int precision);
int print_int(va_list args, char buffer[], int flags, int width, int precision, int modifier);
int print_binary(va_list args);
int print_unsignd(va_list args, char buffer[], int flags, int width, int precision, int modifier);
int print_octal(va_list args, char buffer[], int flags, int width, int precision, int modifier);
int print_hexadecimal(va_list args, char buffer[], int flags, int width, int precision, int modifier);
int print_hexa_upper(va_list args, char buffer[], int flags, int width, int precision, int modifier);
int print_hexa(va_list args, char map[], char buffer[], int flags, char flag_ch, int width, int precision, int modifier);
int print_non_printable(va_list args, char buffer[],
	int flags, int width, int precision, int modifier);
int print_pointer(va_list args, char buffer[], int flags, int width, int precision, int modifier);
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list args);
int get_precision(const char *format, int *i, va_list args);
int get_size(const char *format, int *i);
int print_reverse(va_list args, char buffer[], int flags, int width, int precision, int modifier);
int print_rot13string(va_list args, char buffer[], int flags, int width, int precision, int modifier);
int handle_write_char(char c, char buffer[], int flags, int width, int precision, int modifier);
int write_number(int sign, int i, char buffer[], int flags, int width, int precision, int modifier);
int write_num(int i, char buffer[], int flags, int width, int precision, int len, char space, char ch);
int write_pointer(char buffer[], int i, int len, int width, int flags, char space, char extra_c, int _space);
int write_unsgnd(int sign, int i, char buffer[], int flags, int width, int precision, int modifier);
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);
long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);
int _putchar(char c);
#endif
