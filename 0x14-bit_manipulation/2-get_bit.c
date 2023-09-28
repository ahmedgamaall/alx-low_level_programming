#include "main.h"

/**
 * get_bit - returns the value of a bit at an index in a decimal number
 * @num: number to search
 * @index: index of the bit
 *
 * Return: value of the bit
 */
int get_bit(unsigned long int num, unsigned int index)
{
	if (index >= (sizeof(num) * 8))
		return (-1);

	return ((num >> index) & 1);
}
