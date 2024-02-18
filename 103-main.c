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
    merge_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
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
 * divide_list - divide the array into sub arrays
 * 
 * @array: the array given
 * @lower: the lower bound for the array
 * @upper: the upper bound for the array
 * Return: Void
 */
void divide_list(int *array, size_t lower, size_t upper)
{
    if (lower < upper)
    {
        size_t mid = lower + (upper - lower) / 2;
        divide_list(array, lower, mid);
        divide_list(array, mid + 1, upper);
        merge_list(array, lower, mid, upper);
    }
}

/**
 * merge_list - merges the sub array 
 * 
 * @array: the array given
 * @lower: the lower bound for the array
 * @mid: the middle of the array
 * @upper: the upper bound for the array
 * Return: Void
 */
void merge_list(int *array, size_t lower, size_t mid, size_t upper)
{
    size_t index = lower, i = lower, j = mid + 1;
    int *result = malloc((upper + mid) * sizeof(int));

    printf("Merging...\n[left]: ");
    for (int k = lower; k <= mid; k++)
    {
        printf("%d", array[k]);
        if (k != mid)
            printf(", ");
        else
            printf("\n");
    }

    printf("[right]: ");
    for (int k = mid + 1; k <= upper; k++)
    {
        printf("%d", array[k]);
        if (k != upper)
            printf(", ");
        else
            printf("\n");
    }

    while (i <= mid && j <= upper)
        result[index++] = (array[i] <= array[j]) ? array[i++] : array[j++];

    while (j <= upper)
        result[index++] = array[j++];
    while (i <= mid)
        result[index++] = array[i++];

    printf("[Done]: ");
    for (j = lower; j <= upper; j++)
    {
        array[j] = result[j];
        printf("%d", array[j]);
        if (j != upper)
            printf(", ");
        else
            printf("\n");
    }
}
