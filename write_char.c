#include "main.h"
/**
  * write_char - incorporte options with a char.
  * @args: character to be position according to its options.
  * @buffer: string to store final result.
  * @flags: counted flags.
  * @width: counted width.
  * @precision: calucated precision.
  * @modifier: counted modifiers.
  * Return: the newly appended.
  */
int write_char(va_list args, char buffer[], int flags, int width)
{
	int i = 0;
	char chr;
	char space = ' ';

	chr = va_arg(args, int);
	if (flags & 4)
		space = '0';

	buffer[i++] = chr;
	buffer[i] = '\0';

	if (width > 1)
	{
		buffer[1023] = '\0';
		for (i = 0; i < width - 1; i++)
			buffer[1022 - i] = space;

		if (flags & 1)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[1023 - i], width - 1));
		else
			return (write(1, &buffer[1023 - i], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}
