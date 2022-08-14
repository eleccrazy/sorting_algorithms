#include "sort.h"

/**
 * swapper - Swappes two elements of the array.
 *
 * @array: The array whose elements to be swapped.
 * @a: The index of the first element to be swapped.
 * @b: The index of the second element to be swapped.
 *
 */

void swapper(int *array, size_t a, size_t b)
{
	int temp = array[a];

	array[a] = array[b];
	array[b] = temp;
}

/**
 * shell_sort - Sorts an array of integers in ascending order
 * using the Shell sort algorithm, using the Knuth sequence
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 *
 */

void shell_sort(int *array, size_t size)
{
	int gap = 1, n = size, j, i;

	if (size < 2)
		return;
	while (gap < n / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (i = gap; i < n; i++)
		{
			for (j = i - gap; j >= 0; j -= gap)
			{
				if (array[j] > array[j + gap])
					swapper(array, j, j + gap);
				else
					break;
			}
		}

		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
