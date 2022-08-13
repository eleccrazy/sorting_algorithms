#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending
 * order using the Bubble sort algorithm
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 *
 */

void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j = 0, reduced_size = size - 1;
	int temp, status;

	while (i < size)
	{
		status = 0;
		j = 0;

		while (j < reduced_size)
		{
			if (array[j] > array[j + 1])
			{
				status = 1;
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
			j++;
		}
		if (status != 1)
			break;

		reduced_size--;
		i++;
	}
}
