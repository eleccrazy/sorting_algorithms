#include "sort.h"

/**
 * swapper - Swappes two elements of the array.
 *
 * @array: The array to be sorted.
 * @a: The first index to be swapped.
 * @b: The second index to be swapped.
 *
 */

void swapper(int *array, int a, int b)
{
	int temp = array[a];

	array[a] = array[b];
	array[b] = temp;
}

/**
 * pivot_finder - Finds the pivot from the array.
 *
 * @size: The size of the array.
 * @array: The array to be sorted.
 * @l: The lowest index
 * @h: The higherst index.
 *
 * Return: Returns the pivot index from the array.
 *
 */

int pivot_finder(int *array, int l, int h, size_t size)
{
	int p_value = array[h];
	int i = l, j, temp;

	for (j = l; j < h; j++)
	{
		if (array[j] <= p_value)
		{
			temp = array[i];
			swapper(array, i, j);
			if (array[i] != temp)
				print_array(array, size);
			i++;
		}
	}

	temp = array[i];
	swapper(array, i, h);
	if (array[i] != temp)
		print_array(array, size);
	return (i);
}

/**
 * recursive_helper - helps the quick_sort function by applying
 * recursive checking on the partitioned array.
 *
 * @array: The array to be sorted
 * @low: The lowest index from the pivot index.
 * @high: The higer index from the pivot index.
 * @size: The size of the array.
 *
 */

void recursive_helper(int *array, int low, int high, size_t size)
{
	int p_index;

	if (low < high)
	{
		p_index = pivot_finder(array, low, high, size);
		recursive_helper(array, low, p_index - 1, size);
		recursive_helper(array, p_index + 1, high, size);
	}
	else
		return;
}

/**
 * quick_sort - sorts an array of integers in ascending
 * order using the Quick sort algorithm
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 *
 */

void quick_sort(int *array, size_t size)
{
	recursive_helper(array, 0, size - 1, size);
}
