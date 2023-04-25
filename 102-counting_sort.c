#include "sort.h"
#include<stdio.h>

/**
 * arr_zero_init - initialize array
 *
 * @array: array
 * @size: array size
 */
void arr_zero_init(int *array, int size)
{
	int j;

	for (j = 0; j < size; j++)
	{
		array[i] = 0;
	}
}

/**
 * get_max - array maximum value
 *
 * @array: array to get max value from
 * @size: array size
 *
 * Return: maximum array value
 */
int get_max(int *array, size_t size)
{
	int max;
	size_t x;

	if (size < 2)
		return (0);

	max = array[0];	/* start from first index */

	for (x = 1; x < size; x++)
	{
		if (max < array[x])
			max = array[x];
	}

	return (max);
}

/**
 * counting_sort - sorts an array using the counting
 * sort algorithm
 *
 * @array: initial array
 * @size: array size
 */
void counting_sort(int *array, size_t size)
{
	int k = get_max(array, size), l, *position, *sumPosition, *sorted;
	size_t i;

	if (k == 0)
		return;

	position = malloc(sizeof(int) * (k + 1));
	if (!position)
		return;
	arr_zero_init(position, k + 1);

	for (i = 0; i < size; i++)
		position[array[i]] += 1;    /* set one to the positions */

	sumPosition = malloc(sizeof(int) * (k + 1));
	if (!sumPosition)
		return;
	arr_zero_init(sumPosition, k + 1);
	sumPosition[0] = position[0];   /* make first index equal */

	for (l = 1; l < (k + 1); l++)
		sumPosition[j] = position[j] + sumPosition[j - 1];

	free(position), print_array(sumPosition, k + 1);

	sorted = malloc(sizeof(int) * size);
	if (!sorted)
		return;
	arr_zero_init(sorted, size);

	for (i = 0; i < size; i++)  /* get the sorted array */
	{
		sumPosition[array[i]] -= 1;
		sorted[sumPosition[array[i]]] = array[i];
	}
	free(sumPosition);

	for (i = 0; i < size; i++)  /* update array */
		array[i] = sorted[i];
	free(sorted);
}
