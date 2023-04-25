#include "sort.h"
#include<stdio.h>

/**
 * arr_zero_init - initialize array by 0
 *
 * @array: initialized array
 * @size: array size
 */
void arr_zero_init(int *array, int size)
{
	int k;

	for (k = 0; k < size; k++)
	{
		array[i] = 0;
	}
}

/**
 * get_max - shows maximum value in array
 *
 * @array: array to analyze
 * @size: array size
 *
 * Return: array maximum value
 */
int get_max(int *array, size_t size)
{
	int max;
	size_t k;

	if (size < 2)
		return (0);

	max = array[0];	/* start from first index */

	for (k = 1; k < size; k++)
	{
		if (max < array[k])
			max = array[k];
	}

	return (max);
}

/**
 * counting_sort - sorts array by counting
 * sort algorithm
 *
 * @array: initial array
 * @size: array size
 */
void counting_sort(int *array, size_t size)
{
	int i = get_max(array, size), j, *position, *sumPosition, *sorted;
	size_t k;

	if (i == 0)
		return;

	position = malloc(sizeof(int) * (i + 1));
	if (!position)
		return;
	arr_zero_init(position, i + 1);

	for (k = 0; k < size; k++)
		position[array[k]] += 1;    /* set one */

	sumPosition = malloc(sizeof(int) * (i + 1));
	if (!sumPosition)
		return;
	arr_zero_init(sumPosition, i + 1);
	sumPosition[0] = position[0];   /* make first index equal */

	for (j = 1; j < (i + 1); j++)
		sumPosition[j] = position[j] + sumPosition[j - 1];

	free(position), print_array(sumPosition, i + 1);

	sorted = malloc(sizeof(int) * size);
	if (!sorted)
		return;
	arr_zero_init(sorted, size);

	for (k = 0; k < size; k++)  /* get the sorted array */
	{
		sumPosition[array[k]] -= 1;
		sorted[sumPosition[array[k]]] = array[k];
	}
	free(sumPosition);

	for (k = 0; k < size; k++)
		array[k] = sorted[k];
	free(sorted);
}
