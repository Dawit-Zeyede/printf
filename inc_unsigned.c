#include "main.h"
/**
 * inc_unsign - type conversion and incorporates all of its options.
 * @arg: list of argument to be invoked.
 * @buff: string to store.
 * @fla: counted flags.
 * @wid: counted width.
 * @prec: calcualted precision.
 * @modif: calcualted length modifier.
 * Return: newly appended characters.
 */
int inc_unsign(va_list arg, char buff[], int fla, int wid, int prec, int modif)
{
	int i = 1022;
	int sign = 0;
	unsigned long int num;

	num = va_arg(arg, unsigned long int);
	num = un_length_modifier(num, modif);
	if (num == 0)
		buff[i--] = '0';
	buff[1023] = '\0';
	while (num > 0)
	{
		buff[i--] = (num % 10) + '0';
		num /= 10;
	}

	i += 1;
	return (write_unsgnd(sign, i, buff, fla, wid, prec, modif));
}
