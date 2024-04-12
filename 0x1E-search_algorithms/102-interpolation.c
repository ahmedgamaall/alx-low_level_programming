#include "search_algos.h"

/**
 * interpolation_search - a function that searches for a value in a sorted
 * array of integers using the Interpolation search algorithm
 *
 * @array:  is a pointer to the first element of the array to search in
 * @size: is the number of elements in array
 * @value: is the value to search for
 *
 * Return: the first index where value is located
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t lower, higher, position;

	if (array == NULL)
		return (-1);
	lower = 0;
	higher = size - 1;

	while ((array[higher] != array[lower]) &&
		   (value >= array[lower]) &&
		   (value <= array[higher]))
	{
		position = lower + (((double)(higher - lower) /
					  (array[higher] - array[lower])) *
					 (value - array[lower]));
		printf("Value checked array[%ld] = [%d]\n", position, array[position]);
		if (array[position] < value)
			lower = position + 1;
		else if (value < array[position])
			higher = position - 1;
		else
			return (position);
	}
	position = lower + (((double)(higher - lower) /
					  (array[higher] - array[lower])) *
					 (value - array[lower]));
	printf("Value checked array[%ld] is out of range\n", position);
	return (-1);
}
