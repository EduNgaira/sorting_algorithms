#include "sort.h"
#include<stdio.h>
/**
 * swap_pos - change value positions in array
 *
 * @array: array to swap
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
 * bubble_sort - sorting algorithm that bubbles numbers
 * of a bubble
 *
 * @array: array to be sorted
 * @size: array size
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, temp;

	if (size < 2)
		return;

	for (i = 0; i < size - 1; i++)	/* iterate the array */
	{
		temp = 0;
		for (j = 0; j < size - i - 1; j++)	/* loop only the unsorted */
		{
			if (array[j] > array[j + 1])
			{
				swap_pos(&array, j, j + 1);
				print_array(array, size);
				temp = 1;
			}
		}

		/* check for no swapping */
		if (temp == 0)
			break;
	}
}
