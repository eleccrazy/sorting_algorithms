#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending
 * order using the Counting sort algorithm
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 *
 */

void counting_sort(int *array, size_t size)
{
	size_t i = 1;
	int max, j;
	int *counter, *temp;

	if (size < 2)
		return;

	max = array[0];

	for (; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	counter = malloc(sizeof(int) * max + 1);
	temp = malloc(sizeof(int) * size);

	for (i = 0; i < size; i++)
		counter[array[i]] += 1;

	for (j = 1; j <= max; j++)
		counter[j] = counter[j] + counter[j - 1];

	print_array(counter, max + 1);

	for (i = 0; i < size; i++)
		temp[counter[array[i] - 1]] = array[i];

	for (i = 0; i < size; i++)
		array[i] = temp[i];

	free(temp);
	free(counter);
}
