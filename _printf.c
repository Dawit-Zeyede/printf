#include "main.h"
/**
  * _printf - a function for foramatted printer.
  * @format: Formatted string.
  * ...: list of arguments accoring to format specifiers.
  * Return: end of the program.
  */
int _printf(const char *format, ...)
{
	int i;
	int ret_len = 0;
	int len = 0;
	int flags;
	int width;
	int precision;
	int modifier;
	int p = 0;
	va_list args;
	char buffer[1024];

	if (format == NULL)
		return (-1);
	va_start(args, format);
	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[p] = format[i];
			p += 1;
			if (p == 1024)
				printer(buffer, &p);
			len += 1;
		}
		else
		{
			printer(buffer, &p);
			flags = get_flags(format, &i);
			width = get_width(format, &i, args);
			precision = get_precision(format, &i, args);
			modifier = get_size(format, &i);
			++i;
			ret_len = format_handler(format, &i, args, buffer,
				flags, width, precision, modifier);
			if (ret_len == -1)
				return (-1);
			len += ret_len;
		}
	}

	printer(buffer, &p);

	va_end(args);

	return (len);
}
