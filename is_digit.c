#include "main.h"
/**
 * check - checks for numbers.
 * @c: Char to be checked.
 * Return: end of the program.
 */
int check(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}
