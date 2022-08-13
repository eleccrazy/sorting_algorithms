#include "sort.h"

/**
 * swapper - swappes two elements in the array
 *
 * @array: The array whose elements to be swapped.
 * @a: The index of the first element to be swapped.
 * @b: The index of the second element to be swapped.
 *
 */

void swapper(int *array, int a, int b)
{
	int temp = array[a];

	array[a] = array[b];
	array[b] = temp;
}

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
	size_t i = 0, j = 0, reduced_size = size;

	if (size < 2)
		print_array(array, size);
	else if (size == 2)
	{
		if (array[0] > array[1])
			swapper(array, 0, 1);
		print_array(array, size);
	}

	else
	{
		while (i < size)
		{
			j = 0;

			while (j < reduced_size)
			{
				if (!array[j + 1])
					break;

				if (array[j] > array[j + 1])
				{
					swapper(array, j, j + 1);
					print_array(array, size);
				}
				j++;
			}

			reduced_size -= 1;
			i++;
		}
	}
}
