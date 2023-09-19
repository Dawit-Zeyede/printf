#include "main.h"
/**
  * write_rot13_encry - prints in a rot13 encryption.
  * @arg: list of arguments to be invoked.
  * Return: no of newly appended.
  */
int write_rot13_encry(va_list arg)
{
	unsigned int i;
	unsigned int j;
	char chr;
	char *str;
	int count = 0;
	char decod[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char encod[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(arg, char *);
	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; decod[j]; j++)
		{
			if (decod[j] == str[i])
			{
				chr = encod[j];
				write(1, &chr, 1);
				count++;
				break;
			}
		}
		if (!decod[j])
		{
			chr  = str[i];
			write(1, &chr, 1);
			count++;
		}
	}
	return (count);
}
