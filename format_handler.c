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
	char upper[] = "0123456789ABCDEF";
	char lower[] = "0123456789abcdef";

	switch (format[*i])
	{
		case 'c':
			return (handle_write_char(arg, buffer, flags, width));
		case 's':
			return (write_string(arg, flags, width, precision));
		case '%':
			return (write(1, "%%", 1));
		case 'i':
			return (inc_int(arg, buffer, flags, width, precision, modifier));
		case 'd':
			return (inc_int(arg, buffer, flags, width, precision, modifier));
		case 'b':
			return (write_binary(arg));
		case 'u':
			return (inc_unsignd(arg, buffer, flags, width, precision, modifier));
		case 'o':
			return (inc_octal(arg, buffer, flags, width, precision, modifier));
		case 'x':
			return (inc_hexa(arg, lower, buffer, flags, 'x', width, precision, modifier));
		case 'X':
			return (inc_hexa(arg, upper, buffer, flags, 'X', width, precision, modifier));
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
				while ((format[*i] != ' ') && (format[*i] != '%'))
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
