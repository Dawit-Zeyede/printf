#include "main.h"
/**
  * write_number - incorporates options.
  * @sign: sign.
  * @i: position with in a buffer.
  * @buffer: string to store its options.
  * @flags: counted falgs.
  * @width: counted width.
  * @precision: calculated precison.
  * @modifier: calcualted length modifier.
  * Return: length of the newly appended.
  */
int write_number(int sign, int i, char buffer[],
	int flags, int width, int precision, int modifier)
{
	int len;
	char space = ' ';
	char ch = 0;

	(void) (modifier);

	len = 1023 - i;
	if ((flags & 4) && !(flags & 1))
		space = '0';
	if (sign)
		ch = '-';
	else if (flags & 2)
		ch = '+';
	else if (flags & 16)
		ch = ' ';

	return (write_num(i, buffer, flags, width, precision,
		len, space, ch));
}
