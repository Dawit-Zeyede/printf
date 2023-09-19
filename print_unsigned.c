#include "main.h"
/**
 * print_unsigned - type conversion and print it out.
 * @arg: list of argument to be invoked.
 * @buffer: string to store.
 * @flags: counted flags.
 * @width: counted width.
 * @precision: calcualted precision.
 * @modifier: calcualted length modifier.
 * Return: newly appended characters.
 */
int print_unsignd(va_list arg, char buffer[],
	int flags, int width, int precision, int modifier)
{
	int i = 1022;
	int sign = 0;
	unsigned long int num;
	
	num = va_arg(arg, unsigned long int);
	num = convert_size_unsgnd(num, modifier);

	if (num == 0)
		buffer[i--] = '0';

	buffer[1023] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(sign, i, buffer, flags, width, precision, modifier));
}
