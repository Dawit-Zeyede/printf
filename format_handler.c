#include "main.h"
/**
 * format_handler - handles format specifications and type conversion.
 * @format: formatted string.
 * @i: position of '%'.
 * @bu: position in a buffer for appending.
 * @buffer: string to be added on.
 * @count: invoking counter.
 * @arglist: list of arguments to be formatted.
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
		case '%':
			buffer[*bu] = '%';
			*bu += 1;
			return (1);
		case 's':
			return (format_char(bu, buffer, count, arglist));
	}
	return (0);
}
