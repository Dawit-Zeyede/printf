#include "main.h"
/**
  * printer: printes the string with in a buffer.
  * @buffer: string to be printed.
  * @i: position of the last character in a string.
  */
void printer(char buffer[], int *p)
{
	if (*p > 0)
		write(1, &buffer[0], *p);
	*p = 0;
}
