#include "main.h"
/**
  * handle_write_char - incorporte options with a char.
  * c: character to be position according to its options.
  * @buffer: string to store final result.
  * @flags: counted flags.
  * @width: counted width.
  * @precison: calucated precision.
  * @modifier: counted modifiers.
  * Return: the newly appended.
  */
int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int modifier)
{
	int i = 0;
	char padd = ' ';

	(void) precision;
	(void) (modifier);

	if (flags & 4)
		padd = '0';

	buffer[i++] = c;
	buffer[i] = '\0';

	if (width > 1)
	{
		buffer[1023] = '\0';
		for (i = 0; i < width - 1; i++)
			buffer[1022 - i] = padd;

		if (flags & 1)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[1023 - i], width - 1));
		else
			return (write(1, &buffer[1023 - i], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}
