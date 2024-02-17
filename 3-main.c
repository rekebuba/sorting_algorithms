#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    quick_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}

/**
 * quick_sort - sort an array of integers in ascpivot_indexing order
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
 * @right: the rightest index to the array
 * @left: the largest index to the array
 * Return: Void
 */
void recursion(int *array, size_t size, int right, int left)
{
    int pivot;
    if (right < left)
    {
        pivot = find_pivot(array, size, right, left);

        recursion(array, size, right, pivot - 1);
        recursion(array, size, pivot + 1, left);
    }
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
    return pivot_index;
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

void print_array(const int *array, size_t size)
{
    size_t i;

    i = 0;
    while (array && i < size)
    {
        if (i > 0)
            printf(", ");
        printf("%d", array[i]);
        ++i;
    }
    printf("\n");
}
