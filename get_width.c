#include "main.h"
/**
  * count_width - get the amount of spaces used.
  * @format: formatted printer.
  * @i: position of '%' or 'flag'.
  * @arg: list of arguments to be invoked.
  * Return: speces to be printed.
 */
int count_width(const char *format, int *i, va_list arg)
{
	int k;
	int width = 0;

	for (k = *i + 1; format[k] != '\0'; k++)
	{
		if (check(format[k]))
		{
			width *= 10;
			width += format[k] - '0';
		}
		else if (format[k] == '*')
		{
			k++;
			width = va_arg(arg, int);
			break;
		}
		else
			break;
	}
	*i = k - 1;
	return (width);
}
