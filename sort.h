#ifndef SORTING_ALGORITHMS
#define SORTING_ALGORITHMS

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>


#define HEAP_SIZE 10

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;


void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);

void swap(int *a, int *b);
void swap_list(listint_t **list, listint_t *a, listint_t *b);
int find_pivot(int *array, size_t size, int low, int hig);
void recursion(int *array, size_t size, int low, int hig);
int max_num(int *array, size_t size);
void divide_list(int *sub_array, int *buff, size_t left, size_t right);
void merge_list(int *sub_array, int *buff, size_t left, size_t mid, size_t right);
void radix_unpack(int *array, int **buffer);
void free_mem(int **buffer);
int **allocate_mem(size_t size);
void quick_sort_rec(int *array, size_t size, size_t left, size_t right);
int pivot(int *array, size_t size, size_t left, size_t right);

#endif /* SORTING_ALGORITHMS */
