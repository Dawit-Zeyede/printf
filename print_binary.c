#include "main.h"
/**
 * print_binary - prints number as base 2.
 * @args: list of argument to be invoked.
 * Return: '0' and '1' printed.
 */
int write_binary(va_list args)
{
	unsigned int n;
	unsigned int m;
	unsigned int i;
	unsigned int sum;
	unsigned int a[32];
	int count;

	n = va_arg(args, unsigned int);
	m = 2147483648;
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
