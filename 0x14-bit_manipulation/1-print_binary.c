#include "main.h"

/**
 * print_binary - prints the binary equivalent of a decimal number
 * @n: number to print in binary
 */
void print_binary(unsigned long int number)
{
	int i, counter = 0;
	unsigned long int current;

	for (i = 63; i >= 0; i--)
	{
		current = number >> i;

		if (current & 1)
		{
			_putchar('1');
			counter++;
			_putchar('\n');
		}
		else if (counter)
			_putchar('0');
	}
	if (!counter)
		_putchar('0');
	_putchar('\n');
}
