#include "main.h"
/**
  * count_precision - calcualtes precision.
  * @format: formatted string.
  * @i: position of '%' or 'flags' or 'width'.
  * @arg: list of argument to be invoked.
  * Return: Decimal point.
 */
int count_precision(const char *format, int *i, va_list arg)
{
	int k = *i + 1;
	int precision = -1;

	if (format[k] != '.')
		return (precision);
	precision = 0;
	for (k += 1; format[k] != '\0'; k++)
	{
		if (is_digit(format[k]))
		{
			precision *= 10;
			precision += format[k] - '0';
		}
		else if (format[k] == '*')
		{
			k++;
			precision = va_arg(arg, int);
			break;
		}
		else
			break;
	}
	*i = k - 1;
	return (precision);
}
