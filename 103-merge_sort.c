#include "sort.h"

/**
 * merge_list - Sort a sub array of integers.
 * @sub_array: A sub array of an array of integers to sort.
 * @buff: A buffer to store the sorted sub array.
 * @left: The left index of the array.
 * @mid: The middle index of the array.
 * @right: The right index of the array.
 */
void merge_list(int *sub_array, int *buff, size_t left, size_t mid,
		size_t right)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(sub_array + left, mid - left);

	printf("[right]: ");
	print_array(sub_array + mid, right - mid);

	for (i = left, j = mid; i < mid && j < right; k++)
		buff[k] = (sub_array[i] < sub_array[j]) ? sub_array[i++] : sub_array[j++];
	for (; i < mid; i++)
		buff[k++] = sub_array[i];
	for (; j < right; j++)
		buff[k++] = sub_array[j];
	for (i = left, k = 0; i < right; i++)
		sub_array[i] = buff[k++];

	printf("[Done]: ");
	print_array(sub_array + left, right - left);
}

/**
 * divide_list - Implement the merge sort algorithm through recursion.
 * @sub_array: A sub array of an array of integers to sort.
 * @buff: A buffer to store the sorted result.
 * @left: The left index of the sub array.
 * @right: The right index of the sub array.
 */
void divide_list(int *sub_array, int *buff, size_t left, size_t right)
{
	size_t mid;

	if (right - left > 1)
	{
		mid = left + (right - left) / 2;
		divide_list(sub_array, buff, left, mid);
		divide_list(sub_array, buff, mid, right);
		merge_list(sub_array, buff, left, mid, right);
	}
}

/**
 * merge_sort - Sort an array of integers in ascending
 *              order using the merge sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	divide_list(array, buff, 0, size);

	free(buff);
}
