#include "sort.h"

/**
* counting_sort - Sorts an array of integers in ascending order
*                 using the Counting Sort algorithm
* @array: Pointer to the array of integers to be sorted
* @size: Number of elements in the array
*/
void counting_sort(int *array, size_t size)
{
	int *count_array;

	size_t i, idx, max;

	if (!array || size < 2)
		return;

	max = array[0];

	for (i = 1; i < size; i++)
	{
		if ((size_t)array[i] > max)
			max = array[i];
	}

	count_array = malloc((max + 1) * sizeof(int));

	if (!count_array)
		return;

	for (i = 0; i <= max; i++)
		count_array[i] = 0;

	for (i = 0; i < size; i++)
		count_array[array[i]]++;

	print_array(count_array, max + 1);

	idx = 0;
	for (i = 0; i <= max; i++)
	{
		while (count_array[i] > 0)
		{
			array[idx++] = i;
			count_array[i]--;
		}
	}

	free(count_array);
}
