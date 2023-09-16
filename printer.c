#include "main.h"
/**
 * printer - prints a given buffer.
 * @buffer: string to be printed.
 * @len: length of the buffer.
 */
void printer(char buffer[], int len)
{
	int i;

	for (i = 0; i < len; i++)
		_putchar(buffer[i]);
}
