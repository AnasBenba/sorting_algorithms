#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order using
 *               the Bubble Sort algorithm.
 *
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 */
void bubble_sort(int *array, size_t size)
{
	int swap, i = 1, temp = 0;
	size_t j;

	do {
		swap = 0;
		for (j = 0; j < size - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swap = 1;
				print_array(array, size);
			}
		}
		i++;
	} while (swap);
}
