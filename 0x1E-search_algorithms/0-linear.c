#include "search_algos.h"

/**
 * linear_search - a function that searches for a value in
 * an array of integers using the Linear search algorithm
 *
 * @array:  is a pointer to the first element of the array to search in
 * @size: is the number of elements in array
 * @value: is the value to search for
 *
 * Return: the first index where value is located
 */

int linear_search(int *array, size_t size, int value)
{
	size_t count;

	if (array == NULL)
		return (-1);
	for (count = 0; count < size; count++)
	{
		printf("Value checked array[%ld] = [%d]\n", count, array[count]);
		if (array[count] == value)
		{
			return (count);
		}
	}
	return (-1);
}
