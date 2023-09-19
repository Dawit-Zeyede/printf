#include "main.h"
/**
 * write_unsgnd - Writes an unsigned number
 * @sign: sign
 * @i: position
 * @buffer: string to be filled.
 * @flags: counted flags.
 * @width: counted width.
 * @precision: calcualted precision.
 * @modifier: calcualted size.
 * Return: Number of written chars.
 */
int write_unsgnd(int sign, int i,
	char buffer[],
	int flags, int width, int precision, int modifier)
{
	int len;
	int j = 0;
	char space = ' ';

	(void) (sign);
	(void) (modifier);

	len = 1023 - i;
	if (precision == 0 && i == 1022 && buffer[i] == '0')
		return (0);
	if (precision > 0 && precision < len)
		space = ' ';

	while (precision > len)
	{
		buffer[--i] = '0';
		len++;
	}

	if ((flags & 4) && !(flags & 1))
		space = '0';

	if (width > len)
	{
		for (j = 0; j < width - len; j++)
			buffer[j] = space;

		buffer[j] = '\0';

		if (flags & 1)
		{
			return (write(1, &buffer[i], len) + write(1, &buffer[0], j));
		}
		else
		{
			return (write(1, &buffer[0], j) + write(1, &buffer[i], len));
		}
	}

	return (write(1, &buffer[i], len));
}
