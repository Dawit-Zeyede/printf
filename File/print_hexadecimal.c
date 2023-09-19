#include "main.h"
/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @args: list of argument to be passed.
 * @buffer: string to be filled
 * @flags:  counted flags.
 * @width: counted width.
 * @precision: counted  Precision.
 * @modifier: counted length modifier.
 * Return: newly appended characters.
 */
int print_hexadecimal(va_list args, char buffer[],
	int flags, int width, int precision, int modifier)
{
	return (print_hexa(args, "0123456789abcdef", buffer,
		flags, 'x', width, precision, modifier));
}
