#include "main.h"
/**
  * write_reverse - print a stiring in a reverse.
  * @args: List of argument to be invoked.
  * @buffer: string to be filled.
  * @flags: counted flags.
  * @width: counted width.
  * @precision: counted precision.
  * @modifier: counted modifier.
  * Return: newly appended characters.
  */
int write_reverse(va_list args)
{
	char *str;
	int i, count = 0;

	str = va_arg(args, char *);
	if (str == NULL)
	{
		str = ")Null(";
	}
	for (i = 0; str[i]; i++)
		;
	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		count++;
	}
	return (count);
}
