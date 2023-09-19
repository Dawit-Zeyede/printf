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
	int fla, widt, prec, modif;
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
			fla = get_flags(format, &i);
			widt = get_width(format, &i, args);
			prec = get_precision(format, &i, args);
			modif = get_size(format, &i);
			++i;
			ret_len = format_handler(format, &i, args, buffer, fla, widt, prec, modif);
			if (ret_len == -1)
				return (-1);
			len += ret_len;
		}
	}
	printer(buffer, &p);
	va_end(args);
	return (len);
}
