#include "sort.h"
/**
 * shell_sort - Sorts an array of integers using the Shell sort algorithm
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t i;
	int j, temp, gap = 1, k;

	while (gap < (int)size / 3)
	{
		gap = gap * 3 + 1;
	}

	k = gap;

	for (; gap > 0; gap /= 2)
	{
		for (i = gap; i < size; i++)
		{
			j = i;
			
			while (j >= gap && array[j] < array[j - gap])
			{
				temp = array[j];
				array[j] = array[j - gap];
				array[j - gap] = temp;
				j -= gap;
			}
		}
		if (gap != k / 2)
		{
			print_array(array, size);
		}
	}
}
