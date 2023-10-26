#include "main.h"
#include <stdlib.h>
/**
 * clear_bit - This program sets the value of a bit to 0 at a given index
 * @n: number to clear bit in
 * @index: is the index, starting from 0 of the bit you want to set
 * Return: 1 if success, -1 if error
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > sizeof(n) * 8)
		return (-1);
	*n &= ~(1 << index);
	return (1);
}
