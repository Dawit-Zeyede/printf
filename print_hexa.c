#include "main.h"
/**
 * print_hexa - sets num in base 16.
 * @args: list of argument to be invoked.
 * @hex_val: 16 hex val to be mapped with the num.
 * @buffer: string to be filled.
 * @flags:  counted flags.
 * @flag_ch: The flag.
 * @width:couted width.
 * @precision: counted Precision.
 * @modifier: counted modifiers.
 * Return: newly added characters.
 */
int print_hexa(va_list args, char hex_val[], char buffer[],
	int flags, char flag_ch, int width, int precision, int modifier)
{
	int i = 1022;
	unsigned long int num;
	unsigned long int init_num;

	num = init_num = va_arg(args, unsigned long int);
	num = convert_size_unsgnd(num, modifier);

	if (num == 0)
		buffer[i--] = '0';

	buffer[1023] = '\0';

	while (num > 0)
	{
		buffer[i--] = hex_val[num % 16];
		num /= 16;
	}

	if (flags & 8 && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, modifier));
}
