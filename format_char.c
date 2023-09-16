#include "main.h"
/**
 * format_char - append string argument to the existing buffer.
 * @bu: the first position where the first character of a string is to be appended.
 * @buffer: existing string where a new one is to be appended.
 * @count: amount to be invoked.
 * @arglist: string  to be appended.
 * Return: length of the appended string.
 */
int format_char(int *bu, char *buffer, int count, va_list arglist)
{
	int i;
	int len = 0;
	char *str;

	for (; count > 1; count--)
		va_arg(arglist, char *);
	str = va_arg(arglist, char *);
	for (i = 0; str[i] != '\0'; i++)
	{
		buffer[*bu] = str[i];
		*bu += 1;
		len += 1;
	}
	return (len);
}
