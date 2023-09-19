#include "main.h"
/**
  * count_len - calculate length modifier for type conversion.
  * @format: list of argments to be invoked.
  * @i: position of '%' or 'flag' or 'width' or 'precision'.
  * Return: end of the program
 */
int count_len(const char *format, int *i)
{
	int k = *i + 1;
	int size = 0;

	if (format[k] == 'l')
		size = 2;
	else if (format[k] == 'h')
		size = 1;
	if (size == 0)
		*i = k - 1;
	else
		*i = k;
	return (size);
}
