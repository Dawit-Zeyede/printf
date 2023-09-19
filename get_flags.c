#include "main.h"
/**
  * count_flags - get the required for the given option.
  * @format: Formatted string.
  * @i: postion of '%'.
  * Return: amount to be printed.
 */
int count_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j;
	int k;
	int flags = 0;
	const char flag_list[] = {'-', '+', '0', '#', ' ', '\0'};
	const int flag_val[] = {1, 2, 4, 8, 16, 0};

	for (k = *i + 1; format[k] != '\0'; k++)
	{
		for (j = 0; flag_list[j] != '\0'; j++)
			if (format[k] == flag_list[j])
			{
				flags |= flag_val[j];
				break;
			}

		if (flag_list[j] == 0)
			break;
	}

	*i = k - 1;

	return (flags);
}
