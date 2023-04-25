#include "sort.h"
#include<stdio.h>

/**
 * swap_pos - swaps  valiue's position in array
 *
 * @array: array to be changed
 * @first: first index
 * @second: second index
 */
void swap_pos(int **array, size_t first, size_t second)
{
	int temp;

	temp = (*array)[first];
	(*array)[first] = (*array)[second];
	(*array)[second] = temp;
}

/**
 * partition - divides array into two parts
 * lower and higher
 *
 * @array: array to be sorted
 * @lower: lower boundary
 * @upper: upper boundary
 * @size: size of the array
 *
 * Return: index of sorted pivot
 */
size_t partition(int **array, size_t lower, size_t upper, size_t size)
{
	size_t initial, sequential, pivot;

	pivot = upper;
	lb = lower;

	for (sequential = initial; sequential < pivot; sequential++)
	{
		/* check if sequential is lesser than pivot */
		if ((*array)[sequential] <= (*array)[pivot])
		{
			if (initial != sequential)
			{
				swap_pos(array, initial, sequential);
				print_array(*array, size);
			}
			initial += 1;
		}
	}

	/* swap pivot to its original position */
	if (initial != sequential)
	{
		swap_pos(array, initial, sequential);
		print_array(*array, size);
	}
	return (initial);
}
/**
 * sorter - sorts array recursively
 *
 * @array: array to be sorted
 * @lb: lower bound
 * @ub: upper bound
 * @size: size of the array
 */
void sorter(int **array, size_t lb, size_t ub, size_t size)
{
	size_t sorted_index;

	/* recursive breakpoint */
	if (lb < ub && *array)
	{
		sorted_index = partition(array, lb, ub, size);

		/* perform recursive sort */
		if (sorted_index - lb > 1)	/* more than one element present */
			sorter(array, lb, sorted_index - 1, size);    /* sorts lower boundary */

		if (ub - sorted_index > 1)
			sorter(array, sorted_index + 1, ub, size);    /* sort upper boundary */
	}
}

/**
 * quick_sort - applies quick sort to given array
 *
 * @array: array to be sorted
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	/* create the sorter function */
	sorter(&array, 0, size - 1, size);
}
