#include "main.h"
/**
  * un_length_modifier - modifies and type converts the given num.
  * @num: num to be modified.
  * @modifier: prefferd modifier.
  * Return: length of the full num.
 */
long int un_length_modifier(unsigned long int num, int size)
{
	if (size == 2)
		return (num);
	else if (size == 1)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
