#include "sort.h"

/**
 * selection_sort - sort an array of integers in ascending order
 * using the selection sort algorithm
 *
 * @array: an array of integers
 * @size: size of the array
 * Return: Void
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index;
	int min;

	if (array == NULL || size <= 1)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = array[i];
		min_index = i;
		for (j = i + 1; j < size; j++)
		{
			if (min > array[j])
			{
				min = array[j];
				min_index = j;
			}
		}
		if (min != array[i])
		{
			swap(&array[i], &array[min_index]);
			print_array(array, size);
		}
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
