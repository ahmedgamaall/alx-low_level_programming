#include "search_algos.h"
#include <math.h>

/**
 * jump_search - a function that searches for a value in a sorted
 * array of integers using the Jump search algorithm
 *
 * @array:  is a pointer to the first element of the array to search in
 * @size: is the number of elements in array
 * @value: is the value to search for
 *
 * Return: the first index where value is located
 */

int jump_search(int *array, size_t size, int value)
{
	size_t ltr, rtl, mon, count;

	if (array == NULL)
		return (-1);
	ltr = 0;
	mon = sqrt(size);
	rtl = mon;
	while (1)
	{
		printf("Value checked array[%ld] = [%d]\n", ltr, array[ltr]);
		if (rtl >= size || array[rtl] >= value)
			break;
		else if (array[rtl] < value)
		{
			ltr = rtl;
			rtl += mon;
		}
	}
	printf("Value found between indexes [%ld] and [%ld]\n", ltr, rtl);
	for (count = ltr; count < size && count <= rtl; count++)
	{
		printf("Value checked array[%ld] = [%d]\n", count, array[count]);
		if (array[count] == value)
		{
			return (count);
		}
	}
	return (-1);
}
