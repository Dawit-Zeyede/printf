#include "main.h"
/**
 * handle_print - Prints an argument based on its type
 * @fmt: Formatted string in which to print the arguments.
 * @list: List of arguments to be printed.
 * @ind: ind.
 * @buffer: Buffer array to handle print.
 * @flags: Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: 1 or 2;
 */
int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int unknow_len = 0, printed_chars = -1;

	switch (fmt[*ind])
	{
		case 'c':
			return (print_char(list, buffer, flags, width, precision, size));
		case 's':
			return (print_string(list, flags, width, precision));
		case '%':
			return (write(1, "%%", 1));
		case 'i':
			return (print_int(list, buffer, flags, width, precision, size));
		case 'd':
			return (print_int(list, buffer, flags, width, precision, size));
		case 'b':
			return (print_binary(list));
		case 'u':
			return (print_unsignd(list, buffer, flags, width, precision, size));
		case 'o':
			return (print_octal(list, buffer, flags, width, precision, size));
		case 'x':
			return (print_hexadecimal(list, buffer, flags, width, precision, size));
		case 'X':
			return (print_hexa_upper(list, buffer, flags, width, precision, size));
		case 'p':
			return (print_pointer(list, buffer, flags, width, precision, size));
		case 'S':
			return (print_non_printable(list, buffer, flags, width, precision, size));
		case 'r':
			return (print_reverse(list, buffer, flags, width, precision, size));
		case 'R':
			return (print_rot13string(list, buffer, flags, width, precision, size));
		case '\0':
			return (-1);
		default:
			unknow_len += write(1, "%%", 1);
			if (fmt[*ind - 1] == ' ')
				unknow_len += write(1, " ", 1);
			else if (width)
			{
				--(*ind);
				while (fmt[*ind] != ' ' && fmt[*ind] != '%')
					--(*ind);
				if (fmt[*ind] == ' ')
					--(*ind);
				return (1);
			}
			unknow_len += write(1, &fmt[*ind], 1);
			return (unknow_len);
		}
	return (printed_chars);
}
