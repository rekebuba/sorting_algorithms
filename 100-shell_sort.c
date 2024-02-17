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
	int k;
	for (gap = 1; gap < (size / 3); gap = (gap * 3) + 1)
		;

	while (gap > 0)
	{
		for (i = 0, j = gap; j < size; i++, j++)
		{
			if (array[i] > array[j])
			{
				swap(&array[i], &array[j]);
			}
			if (i >= gap)
			{
				for (k = i - gap; k > 0; k -= gap)
				{
					if (array[k] > array[k + gap])
					{
						swap(&array[k], &array[k + gap]);
					}
					else
						break;
				}
			}
		}
		print_array(array, size);
		gap /= 3;
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
