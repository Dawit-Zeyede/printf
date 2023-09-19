#include "main.h"
/**
 * inc_octal - sets number in base 8.
 * @args: list of argument to be invoked.
 * @buffer: string to be incorporated.
 * @flags: counted flags.
 * @width: counted width.
 * @precision: counted precision.
 * @modifier: counted length spacifier.
 * Return: Number of chars printed
 */
int inc_octal(va_list args, char buffer[],
	int flags, int width, int precision, int modifier)
{

	int i = 1022;
	int sign = 0;
	unsigned long int num;
	unsigned long int init_num;

	num = init_num = va_arg(args, unsigned long int);
	num = un_length_modifier(num, modifier);
	if (num == 0)
		buffer[i--] = '0';
	buffer[1023] = '\0';
	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}
	if (flags & 8 && init_num != 0)
		buffer[i--] = '0';
	i++;
	return (write_unsgnd(sign, i, buffer, flags, width, precision, modifier));
}
