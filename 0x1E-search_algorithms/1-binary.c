#include "search_algos.h"

/**
 * binary_search - a function that searches for a value in a sorted
 * array of integers using the Binary search algorithm
 *
 * @array:  is a pointer to the first element of the array to search in
 * @size: is the number of elements in array
 * @value: is the value to search for
 *
 * Return: the first index where value is located
 */
int binary_search(int *array, size_t size, int value)
{
	size_t ltr, rtl, mon, count;

	ltr = 0;
	rtl = size - 1;
	if (array == NULL)
		return (-1);
	while (ltr <= rtl)
	{
		printf("Searching in array:");
		for (count = ltr; count <= rtl; count++)
		{
			if (count == ltr)
				printf(" %d", array[count]);
			else
				printf(", %d", array[count]);
		}
		printf("\n");
		mon = (ltr + rtl) / 2;
		if (array[mon] < value)
			ltr = mon + 1;
		else if (array[mon] > value)
			rtl = mon - 1;
		else
			return (mon);
	}

	return (-1);
}
