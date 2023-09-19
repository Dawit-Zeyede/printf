#include "main.h"
/**
 * print_hexa_upper - sets num to base 16 with upper case notation.
 * @types: list of arguments to be invoked.
 * @buffer: string to be filled
 * @flags: counted flags.
 * @width: counted width.
 * @precision: counted Precision.
 * @modifier: counted length modifier.
 * Return: newly appended strings.
 */
int print_hexa_upper(va_list args, char buffer[],
	int flags, int width, int precision, int modifier)
{
	return (print_hexa(args, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, modifier));
}
