#include "main.h"
/**
 * write_num - incorporates all options and prints it.
 * @i: position in a buffer.
 * @buffer: string to store and print num and its options.
 * @flags: counted flags.
 * @width: counted width.
 * @precision: calculated precision.
 * @len: len
 * @space: width handler.
 * @ch: flag specifier.
 * Return: Number of printed chars.
 */
int write_num(int i, char buffer[],
	int flags, int width, int precision,
	int len, char space, char ch)
{
	int j;
	int _space = 1;

	if (precision == 0 && i == 1022 && buffer[i] == '0' && width == 0)
		return (0);
	if (precision == 0 && i == 1022 && buffer[i] == '0')
		buffer[i] = space = ' ';
	if (precision > 0 && precision < len)
		space = ' ';
	while (precision > len)
	{
		buffer[--i] = '0';
		len++;
	}
	if (ch != 0)
		len++;
	if (width > len)
	{
		for (j = 1; j < width - len + 1; j++)
			buffer[j] = space;
		buffer[j] = '\0';
		if (flags & 1 && space == ' ')
		{
			if (ch)
				buffer[--i] = ch;
			return (write(1, &buffer[i], len) + write(1, &buffer[1], i - 1));
		}
		else if (!(flags & 1) && space == ' ')
		{
			if (ch)
				buffer[--i] = ch;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[i], len));
		}
		else if (!(flags & 1) && space == '0')
		{
			if (ch)
				buffer[--_space] = ch;
			return (write(1, &buffer[_space], i - _space) +
				write(1, &buffer[i], len - (1 - _space)));
		}
	}
	if (ch)
		buffer[--i] = ch;
	return (write(1, &buffer[i], len));
}
