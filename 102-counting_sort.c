#include "sort.h"

/**
 * counting_sort - array of integers in ascending order
 * using the counting sort algorithm
 *
 * @array: the given array
 * @size: the size of the array
 * Return: Void
 */
void counting_sort(int *array, size_t size)
{
	int *result, *key;
	size_t i;
	int j, max;

	if (!array || size < 2)
		return;

	result = malloc(sizeof(int) * size);
	if (!result)
		return;

	max = max_num(array, size);
	key = calloc(1, (max + 1) * sizeof(int));
	if (!key)
	{
		free(result);
		return;
	}

	for (i = 0; i < size; i++)
		key[array[i]]++;

	for (j = 1; j <= max; j++)
		key[j] += key[j - 1];

	print_array(key, max + 1);

	for (j = size - 1; j >= 0; j--)
		result[--key[array[j]]] = array[j];

	for (i = 0; i < size; i++)
		array[i] = result[i];

	free(result);
	free(key);
}

/**
 * max_num - find the maximum number in an array
 *
 * @array: the given array
 * @size: the size of the array
 * Return: the maximum number
 */
int max_num(int *array, size_t size)
{
	size_t i;
	int max = 0;

	for (i = 0; i < size; i++)
	{
		if (max < array[i])
		{
			max = array[i];
		}
	}

	return (max);
}
