#include "main.h"
/**
 * print_int - incorporate its options and print.
 * @args: list of argument to be invoked.
 * @buffer: string to store num and its options.
 * @flags: counted flags.
 * @width: counted width.
 * @precison: calcualted precison.
 * @modifier: calculated length modifier.
 * Return: length of the newly appended strings.
 */
int print_int(va_list args, char buffer[],
	int flags, int width, int precision, int modifier)
{
	int i = 1022;
	int sign = 0;
	long int n;
	unsigned long int num;

	n = va_arg(args, long int);
	n = convert_size_number(n, modifier);

	if (n == 0)
		buffer[i--] = '0';

	buffer[1023] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		sign = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(sign, i, buffer, flags, width, precision, modifier));
}
