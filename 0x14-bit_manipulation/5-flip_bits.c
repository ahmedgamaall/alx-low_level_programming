#include "main.h"

/**
 * flip_bits -  counters the number of bits to change
 * to get from one number to another
 * @n: first number
 * @m: second number
 *
 * Return: number of bits to change
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int xor = n ^ m;
	unsigned int counter = 0;

	while (xor)
	{
		counter += xor & 1;
		xor >>= 1;
	}

	return (counter);
}
