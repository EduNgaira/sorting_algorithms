#include "sort.h"
#include<stdio.h>

/**
 * swap_pos - swaps value positions
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
 * selection_sort - selection sorting an array
 * @array: array to be sorted
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int min, flag;

	for (i = 0; i < size; i++)
	{
		min = i;
		flag = 0;

		for (j = i + 1; j < size; j++)	/* start from the unsorted part */
		{
			if (array[min] > array[j])  /* check for min value */
			{
				min = j;
				flag = 1;
			}
		}

		if (min != i)
		{
			swap_pos(&array, i, min);
			print_array(array, size);
		}
	}
}
