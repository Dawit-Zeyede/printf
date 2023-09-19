#include "main.h"
/**
  * length_modifier - long and short format.
  * @num: numeber to be modified.
  * @size: prefered format.
  * Return: length.
  */
long int length_modifier(long int num, int modifier)
{
	if (modifier == 2)
		return (num);
	else if (modifier == 1)
		return ((short)num);

	return ((int)num);
}
