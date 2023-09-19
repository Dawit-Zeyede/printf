#include "main.h"
/**
  * format_handler - matchs format specifier with its function.
  * @format: formatted string.
  * @i: position of '%'.
  * @arg: list of arguments according to format specifiers.
  * @buffer: string which is set to be filled.
  * @flags: counter for flags.
  * @width: counter for width.
  * @precision: counter for precision.
  * @modifier: counter for length modifier.
  * Return: number of characters that are newly appended.
  */
int format_handler(const char *format, int *i, va_list arg, char buffer[],
	int flags, int width, int precision, int modifier)
{
	int len = 0;
	int ret_len = -1;

	switch (format[*i])
	{
		case 'c':
			return (print_char(arg, buffer, flags, width, precision, modifier));
		case 's':
			return (print_string(arg, flags, width, precision));
		case '%':
			return (write(1, "%%", 1));
		case 'i':
			return (print_int(arg, buffer, flags, width, precision, modifier));
		case 'd':
			return (print_int(arg, buffer, flags, width, precision, modifier));
		case 'b':
			return (print_binary(arg));
		case 'u':
			return (print_unsignd(arg, buffer, flags, width, precision, modifier));
		case 'o':
			return (print_octal(arg, buffer, flags, width, precision, modifier));
		case 'x':
			return (print_hexadecimal(arg, buffer, flags, width, precision, modifier));
		case 'X':
			return (print_hexa_upper(arg, buffer, flags, width, precision, modifier));
		case 'p':
			return (print_pointer(arg, buffer, flags, width, precision, modifier));
		case 'S':
			return (print_non_printable(arg, buffer, flags, width, precision, modifier));
		case 'r':
			return (print_reverse(arg, buffer, flags, width, precision, modifier));
		case 'R':
			return (print_rot13string(arg, buffer, flags, width, precision, modifier));
		case '\0':
			return (-1);
		default:
			len += write(1, "%%", 1);
			if (format[*i - 1] == ' ')
				len += write(1, " ", 1);
			else if (width)
			{
				--(*i);
				while (format[*i] != ' ' && format[*i] != '%')
					--(*i);
				if (format[*i] == ' ')
					--(*i);
				return (1);
			}
			len += write(1, &format[*i], 1);
			return (len);
		}
	return (ret_len);
}
