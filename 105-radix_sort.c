#include "sort.h"

/**
 * len_digit - check the digit wise length of a number
 *
 * @array: the given array
 * @size: the size of the array
 * Return: the length of the number
 */
int len_digit(int *array, ssize_t size)
{
	int max = 0, temp, i;
	int count = 0;

	for (i = 0; i < size; i++)
	{
		if (max < array[i])
		{
			max = array[i];
		}
	}
	temp = max;
	while (temp > 0)
	{
		temp /= 10;
		count++;
	}
	return (count);
}

/**
 * allocate_mem - allocates 2 dimensional array to work with radix_sort
 *
 * @size: size to be allocated
 * Return: the allocated memory
 */
int **allocate_mem(size_t size)
{
	int **buffer = malloc(HEAP_SIZE * sizeof(int *));
	size_t i, j;

	for (i = 0; i < HEAP_SIZE; i++)
	{
		buffer[i] = malloc(size * sizeof(int));
	}

	for (i = 0; i < HEAP_SIZE; i++)
	{
		for (j = 0; j < size; j++)
		{
			buffer[i][j] = -1;
		}
	}
	return (buffer);
}

/**
 * radix_sort - sorts an array of integers in ascending order
 * using the Radix sort algorithm
 *
 * @array: the given array
 * @size: the size of the array
 * Return: Void
 */
void radix_sort(int *array, size_t size)
{
	int divisor = 1;
	size_t i;
	int value, digit_index, index;

	int digit = len_digit(array, size);
	int **buffer = allocate_mem(size);

	while (digit > 0)
	{
		index = 0;
		for (i = 0; i < size; i++)
		{
			value = array[i] / divisor;
			digit_index = value % 10;
			if (buffer[digit_index][index] != -1)
			{
				while (buffer[digit_index][index] != -1)
					index++;
				buffer[digit_index][index] = array[i];
				index = 0;
			}
			else
				buffer[digit_index][index] = array[i];
		}
		radix_unpack(array, buffer);
		print_array(array, size);
		divisor *= 10;
		digit--;
	}
	free_mem(buffer);
}

/**
 * radix_unpack - unpack the values to the original array
 *
 * @array: the given array
 * @buffer: the 2D array that holds the values
 * Return: Void
 */
void radix_unpack(int *array, int **buffer)
{
	int index1 = 0, index2;
	size_t i = 0;

	while (index1 < HEAP_SIZE)
	{
		index2 = 0;
		while (buffer[index1][index2] != -1)
		{
			array[i] = buffer[index1][index2];
			buffer[index1][index2] = -1;
			index2++;
			i++;
		}
		index1++;
	}
}

/**
 * free_mem - frees the allocated memory
 *
 * @buffer: the two-dimensional  array that is passed
 * Return: Void
 */
void free_mem(int **buffer)
{
	int i;

	for (i = 0; i < HEAP_SIZE; i++)
	{
		free(buffer[i]);
	}
	free(buffer);
}
