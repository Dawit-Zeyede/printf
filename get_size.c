#include "main.h"
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
