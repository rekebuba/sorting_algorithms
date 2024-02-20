#include "sort.h"

/**
 * merge_sort - sorts an array of integers in ascending order
 * using the Merge sort algorithm
 *
 * @array: the given array
 * @size: the size of the array
 * Return: Void
 */
void merge_sort(int *array, size_t size)
{
	divide_list(array, 0, size - 1);
}

/**
 * divide_list - divide the array and sort them
 *
 * @array: the array passed
 * @lower: the lower bound
 * @upper: the upper bound
 * Return: Void
 */
void divide_list(int *array, size_t lower, size_t upper)
{
	size_t mid = (lower + upper) / 2;

	divide_list(array, lower, mid);
	divide_list(array, mid + 1, upper);
	merge_list(array, lower, mid, upper);
}

/**
 * merge_list - apply the merge algorithm
 *
 * @array: the array passed
 * @lower: the lower bound
 * @mid: the middle value
 * @upper: the upper bound
 */
void merge_list(int *array, size_t lower, size_t mid, size_t upper)
{
	size_t index = 0, i = lower, j = mid;
	int *result = malloc(upper * sizeof(int));

	while (i <= mid && j <= upper)
	{
		if (array[i] >= array[j])
		{
			result[index++] = array[j];
			j++;
		}
		else
		{
			result[index++] = array[i];
			i++;
		}
	}
	for (; j <= upper; j++)
	{
		result[index++] = array[j];
	}
	for (; i <= mid; i++)
	{
		result[index++] = array[i];
	}

	for (i = mid, j = 0; j < index; i++, j--)
		array[i] = result[j];
}
