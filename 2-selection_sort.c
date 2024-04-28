#include "sort.h"

/**
* selection_sort - sorts an array of integers in ascending order
* using the Selection sort algorithm
*
* @array: array to be sorted
* @size: size of array
*
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j, idxMin;
	int tmp;

	if (size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		idxMin = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[idxMin])
				idxMin = j;
		}
		if (idxMin != i)
		{
			tmp = array[i];
			array[i] = array[idxMin];
			array[idxMin] = tmp;
			print_array(array, size);
		}
	}
}
