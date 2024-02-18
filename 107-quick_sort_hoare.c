#include "sort.h"

/**
 * quick_sort_hoare - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 *
 * @array: the given array
 * @size: the size of the array
 * Return: the length of the number
 */
void quick_sort_hoare(int *array, size_t size)
{
    quick_sort_rec(array, size, 0, size - 1);
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

/**
 * quick_sort_rec - a recursion function that sorts
 * an array by using divide a concur method
 * 
 * @array: the given array to sort
 * @size: the size of the array
 * @left: the lowest index to the array
 * @right: the largest index to the array
 * Return: Void
 */
void quick_sort_rec(int *array, size_t size, size_t left, size_t right)
{
    if (left < right)
    {
        int j = pivot(array, size, left, right);
        quick_sort_rec(array, size, left, j);
        quick_sort_rec(array, size, j + 1, right);
    }
}

/**
 * pivot - dividing the array into sub arrays using pivot
 *
 * @array: the given array to sort
 * @size: the size of the array
 * @right: the rightest index to the array
 * @left: the largest index to the array
 * Return: the index of the pivot
 */
int pivot(int *array, size_t size, size_t left, size_t right)
{
    int pivot_value = array[right];
    size_t i = left, j = right;
    while (i < j)
    {
        while (array[i] <= pivot_value)
        {
            i++;
        }
        while (array[j] > pivot_value)
        {
            j--;
        }
        if (i < j)
        {
            swap(&array[i], &array[j]);
            print_array(array, size);
        }
    }
    if (j == right)
        j--;
    return (j);
}
