#include "sort.h"

/**
* bubble_sort - sort an array of integers
* in ascending order using the Bubble sort algorithm
*
* @array: array to sort
* @size: size of the array
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, j, n;

	n = size;
	for (i = 0; i < size; i++)
	{
		for (j = 1; j < n; j++)
		{
			if (array[j - 1] > array[j])
			{
				int tmp = array[j - 1];

				array[j - 1] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
		n--;
	}
}
