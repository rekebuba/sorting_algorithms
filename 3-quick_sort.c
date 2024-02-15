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
 * @low: the lowest index to the array
 * @hig: the largest index to the array
 * Return: the index of the pivot
 */
int find_pivot(int *array, size_t size, int low, int hig)
{
	int pivot_index = hig;
	int start = low;
	int end = hig;
	while (start < end)
	{
		while (array[pivot_index] >= array[start])
			start++;
		while (array[pivot_index] < array[end])
			end--;

		if (start < end)
		{
			swap(&array[start], &array[end]);
			print_array(array, size);
		}
	}

	swap(&array[pivot_index], &array[end]);
	print_array(array, size);
	return end;
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
