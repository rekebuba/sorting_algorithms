#include "sort.h"

/**
 * shell_sort - sorts an array of integers  in ascending order
 * using the shell sort algorithm.
 *
 * @array: the array to be sorted
 * @size: the size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, j, i;
	int temp;

	for (gap = 1; gap < (size / 3); gap = (gap * 3) + 1)
		;

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			j = i;

			while (j >= gap && array[j - gap] > temp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}

			array[j] = temp;
		}
		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}

/**
 * swap - swap the given values
 *
 * @a: a pointer to integer
 * @b: a pointer to integer
 * Return: void
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
