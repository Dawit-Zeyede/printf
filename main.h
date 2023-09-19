#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int _printf(const char *format, ...);
int count_flags(const char *format, int *i);
int count_width(const char *format, int *i, va_list args);
int count_precision(const char *format, int *i, va_list args);
int count_len(const char *format, int *i);
void printer(char buffer[], int *p);
int format_handler(const char *format, int *i, va_list args, char buffer[], int flag, int width, int precision, int modifier);
int write_char(va_list args, char buffer[], int flags, int width);
int write_string(va_list args, int flags, int width, int precision);
int inc_int(va_list args, char buffer[], int flags, int width, int precision, int modifier);
int write_binary(va_list args);
int inc_unsign(va_list args, char buffer[], int flags, int width, int precision, int modifier);
int inc_octal(va_list args, char buffer[], int flags, int width, int precision, int modifier);
int inc_hexa(va_list args, char map[], char buffer[], int flags, char flag_ch, int width, int precision, int modifier);
int write_reverse(va_list args);
int write_rot13_encry(va_list args);
int write_number(int sign, int i, char buffer[], int flags, int width, int precision, int modifier);
int write_num(int i, char buffer[], int flags, int width, int precision, int len, char space, char ch);
int write_unsgnd(int sign, int i, char buffer[], int flags, int width, int precision, int modifier);
int check(char);
long int length_modifier(long int num, int modifier);
long int un_length_modifier(unsigned long int num, int modifier);
#endif
