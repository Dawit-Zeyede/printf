#include "main.h"
/**
  * count_flags - get the required for the given option.
  * @format: Formatted string.
  * @i: postion of '%'.
  * Return: amount to be printed.
 */
int count_flags(const char *format, int *i)
{
	int j;
	int k;
	int flags = 0;
	const char flag_list[] = {'-', '+', '0', '#', ' ', '\0'};
	const int flag_val[] = {1, 2, 4, 8, 16, 0};

	for (k = *i + 1; format[k] != '\0'; k++)
	{
		for (j = 0; flag_list[j] != '\0'; j++)
			if (format[k] == flag_list[j])
			{
				flags |= flag_val[j];
				break;
			}

		if (flag_list[j] == 0)
			break;
	}

	*i = k - 1;

	return (flags);
}
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
		if (check(format[k]))
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
/**
  * count_len - calculate length modifier for type conversion.
  * @format: list of argments to be invoked.
  * @i: position of '%' or 'flag' or 'width' or 'precision'.
  * Return: end of the program
 */
int count_len(const char *format, int *i)
{
	int k = *i + 1;
	int size = 0;

	if (format[k] == 'l')
		size = 2;
	else if (format[k] == 'h')
		size = 1;
	if (size == 0)
		*i = k - 1;
	else
		*i = k;
	return (size);
}
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
/**
 * check - checks for numbers.
 * @c: Char to be checked.
 * Return: end of the program.
 */
int check(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
