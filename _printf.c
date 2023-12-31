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
	int len = 0;
	int fla, widt, prec, modif;
	int ret_len = 0;
	int pos = 0;
	char buffer[1024];
	va_list args;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[pos] = format[i];
			pos += 1;
			if (pos == 1024)
				printer(buffer, &pos);
			len += 1;
		}
		else
		{
			printer(buffer, &pos);
			fla = count_flags(format, &i);
			widt = count_width(format, &i, args);
			prec = count_precision(format, &i, args);
			modif = count_len(format, &i);
			i += 1;
			ret_len = format_handler(format, &i, args, buffer, fla, widt, prec, modif);
			if (ret_len == -1)
				return (-1);
			len += ret_len;
		}
	}
	printer(buffer, &pos);
	va_end(args);
	return (len);
}
