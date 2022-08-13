#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending
 * order using the Selection sort algorithm
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 *
 */

void selection_sort(int *array, size_t size)
{
	size_t i = 0, j, index;
	int min, status = 0;

	if (size > 1)
	{
		for (; i < size - 1; i++)
		{
			status = 0;
			min = array[i];
			for (j = i; j < size; j++)
			{

				if (array[j] < min)
				{
					status = 1;
					min = array[j];
					index = j;
				}
			}
			if (status == 1)
			{
				array[index] = array[i];
				array[i] = min;
				print_array(array, size);
			}
		}
	}
}
