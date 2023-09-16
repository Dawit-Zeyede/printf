#include "main.h"
/**
 * _printf - formatted printer.
 * @format: format string.
 * ...: list of arguments corrosponding to format specifiers.
 * Return: No of characters printed on stdout.
 */
int _printf(const char *format, ...)
{
	int i;
	int count = 0;
	int bu = 0;
	char buffer[1024];
	int len = 0;
	va_list arglist;

	va_start(arglist, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			count++;
			len += format_handler(format, &i, &bu, buffer, count, arglist);
		}
		else
		{
			buffer[bu++] = format[i];
			len += 1;
		}
	}
	va_end(arglist);
	printer(buffer, len);
	return (len);
}
