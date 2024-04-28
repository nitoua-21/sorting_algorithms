#include "sort.h"


/**
* swap - Swaps two elements in an array.
* @a: Pointer to the first element.
* @b: Pointer to the second element.
*/
void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
* lomuto_partition - Partitions the array using Lomuto partition scheme.
* @array: The array to be partitioned.
* @low: The starting index of the partition.
* @high: The ending index of the partition.
* @size: The size of the array.
*
* Return: The index of the pivot element after partitioning.
*/
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];

	int i = low - 1, j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (i + 1 != high)
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
* quicksort_recursive - Recursively sorts an array using Quick Sort.
* @array: The array to be sorted.
* @low: The starting index of the partition.
* @high: The ending index of the partition.
* @size: The size of the array.
*/
void quicksort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot_idx = lomuto_partition(array, low, high, size);

		quicksort_recursive(array, low, pivot_idx - 1, size);
		quicksort_recursive(array, pivot_idx + 1, high, size);
	}
}

/**
* quick_sort - Sorts an array of integers in ascending order using
*              the Quick sort algorithm with Lomuto partition scheme.
* @array: The array to be sorted.
* @size: The size of the array.
*/
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	quicksort_recursive(array, 0, size - 1, size);
}
