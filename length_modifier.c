#include "main.h"
/**
  * length_modifier - long and short format.
  * @num: numeber to be modified.
  * @modifier: prefered format.
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
/**
  * un_length_modifier - modifies and type converts the given num.
  * @num: num to be modified.
  * @modifier: prefferd modifier.
  * Return: length of the full num.
 */
long int un_length_modifier(unsigned long int num, int modifier)
{
	if (modifier == 2)
		return (num);
	else if (modifier == 1)
		return ((unsigned short)num);
	return ((unsigned int)num);
}
