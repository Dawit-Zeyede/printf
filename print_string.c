#include "main.h"
/**
 * print_string - incorporates string with its options and prints it.
 * @args: list of argument to be invoked.
 * @flags: counted flags.
 * @width: counted width.
 * @precision: counted precision.
 * Return: length of newly appended.
 */
int print_string(va_list args, int flags, int width, int precision)
{
	int length = 0;
	int i;
	char *str = va_arg(args, char *);

	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}
	while (str[length] != '\0')
		length++;
	if (precision >= 0 && precision < length)
		length = precision;
	if (width > length)
	{
		if (flags & 1)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}
