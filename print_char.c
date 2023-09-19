#include "main.h"

/**
  * print_char - handles sigle character.
  * @arg: list of argument to be invoked.
  * @buffer: string to store characters.
  * @flags: counted flags.
  * @width: counted width.
  * @precision: calculated precison.
  * @modifier: calucated length modifers.
  * Return: characters appended.
  */
int print_char(va_list arg, char buffer[],
	int flags, int width, int precision, int modifier)
{
	char c = va_arg(arg, int);

	return (handle_write_char(c, buffer, flags, width, precision, modifier));
}
