#include "sort.h"

/**
 * swap - Swaps two integer values.
 * @x: Pointer to the first integer.
 * @y: Pointer to the second integer.
 */
void swap(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * partition - Partitions an array for quicksort.
 * @array: The array to be partitioned.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition.
 * @size: The size of the array.
 *
 * Return: The index of the partition.
 */
int partition(int *array, int low, int high, size_t size)
{
	int i = low, j, pivot = array[high];

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
	}
	if (pivot != array[i])
	{
		swap(&array[i], &pivot);
		print_array(array, size);
	}
	return (i);
}

/**
 * quick_sort_recursion - Recursive function to perform quicksort.
 * @array: The array to be sorted.
 * @low: The starting index of the subarray.
 * @high: The ending index of the subarray.
 * @size: The size of the array.
 */
void quick_sort_recursion(int *array, int low, int high, size_t size)
{
	int i;

	if (low < high)
	{
		i = partition(array, low, high, size);
		quick_sort_recursion(array, low, i - 1, size);
		quick_sort_recursion(array, i + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick Sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
	{
		return;
	}
	quick_sort_recursion(array, 0, size - 1, size);
}
