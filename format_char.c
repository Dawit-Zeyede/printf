#include "main.h"
/**
 * format_char - append string argument to the existing buffer.
 * @b: a position where the first character of a string is to be appended.
 * @buf: existing string where a new one is to be appended.
 * @co: amount to be invoked.
 * @arg: string  to be appended.
 * Return: length of the appended string.
 */
int format_char(int *b, char *buf, int co, va_list arg)
{
	int i;
	int len = 0;
	char *str;

	for (; co > 1; co--)
		va_arg(arg, char *);
	str = va_arg(arg, char *);
	for (i = 0; str[i] != '\0'; i++)
	{
		buf[*b] = str[i];
		*b += 1;
		len += 1;
	}
	return (len);
}
