#include "main.h"
/**
 * format_handler - handles format specifications and type conversion.
 * @format: formatted string.
 * @i: position of '%'.
 * @buffer: string to be added on.
 * Return: length of the newly appended characters.
 */
int format_handler(const char *format, int *i, int *bu, char *buffer, int count, va_list arglist)
{
	*i += 1;

	switch (format[*i])
	{
		case 'c':
			for (; count > 1; count--)
				va_arg(arglist, int);
			buffer[*bu] = va_arg(arglist, int);
			*bu += 1;
			return (1);
			break;
		case '%':
			buffer[*bu] = '%';
			*bu += 1;
			return (1);
			break;
		case 's':
			return (format_char(bu, buffer, count, arglist));
			break;
	}
	return (0);
}
