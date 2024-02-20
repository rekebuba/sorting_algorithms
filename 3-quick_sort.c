#include "sort.h"

/**
 * quick_sort - sort an array of integers in ascending order
 * using the Quick sort algorithm
 *
 * @array: an array of integers
 * @size: size of the array
 * Return: Void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;
	recursion(array, size, 0, size - 1);
}

/**
 * recursion - a recursion function that sorts
 * an array by using divide a concur method
 *
 * @array: the given array to sort
 * @size: the size of the array
 * @low: the lowest index to the array
 * @hig: the largest index to the array
 * Return: Void
 */
void recursion(int *array, size_t size, int low, int hig)
{
	int pivot_index;

	if (low > hig)
		return;
	pivot_index = find_pivot(array, size, low, hig);

	recursion(array, size, low, pivot_index - 1);
	recursion(array, size, pivot_index + 1, hig);
}

/**
 * find_pivot - dividing the array into sub arrays using pivot
 *
 * @array: the given array to sort
 * @size: the size of the array
 * @right: the rightest index to the array
 * @left: the largest index to the array
 * Return: the index of the pivot
 */
int find_pivot(int *array, size_t size, int left, int right)
{
	int *pivot = array + right;
	int start = left;
	int pivot_index = left;

	for (start = left; start < right; start++)
	{
		if (array[start] < *pivot)
		{
			if (pivot_index < start)
			{
				swap(array + start, array + pivot_index);
				print_array(array, size);
			}
			pivot_index++;
		}
	}
	if (array[pivot_index] > *pivot)
	{
		swap(array + pivot_index, pivot);
		print_array(array, size);
	}
	return (pivot_index);
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
