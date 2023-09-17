#include "main.h"
/**
 * format_spec - handles format specifications and type conversion.
 * @fo: formatted string.
 * @i: position of '%'.
 * @b: position in a buffer for appending.
 * @buf: string to be added on.
 * @co: invoking counter.
 * @arg: list of arguments to be formatted.
 * Return: length of the newly appended characters.
 */
int format_spec(const char *fo, int *i, int *b, char *buf, int co, va_list arg)
{
	*i += 1;

	switch (fo[*i])
	{
		case 'c':
			for (; co > 1; co--)
				va_arg(arg, int);
			buf[*b] = va_arg(arg, int);
			*b += 1;
			return (1);
		case '%':
			buf[*b] = '%';
			*b += 1;
			return (1);
		case 's':
			return (format_char(b, buf, co, arg));
	}
	return (0);
}
