#include "sort.h"
#include<stdio.h>

/**
 * swap_pos - swaps array of values
 *
 * @array: changing array
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
 * selection_sort - selection sort algorithm
 *
 * @array: array to be sorted
 * @size: array size
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int min_no, min_index, temp;

	if (size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		min_no = array[i];
		min_index = i;
		temp = 0;

		for (j = i + 1; j < size; j++)	/* start from the unsorted part */
		{
			if (min_no > array[j])  /* check min no */
			{
				min_no = array[j];
				min_index = j;
				temp = 1;
			}
		}

		if (temp)
		{
			swap_pos(&array, i, min_index);
			print_array(array, size);
		}
	}
}
