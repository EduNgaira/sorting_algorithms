#include "sort.h"
#include<stdio.h>

/**
 * find_pow - power of a number
 * @x: the number
 * @y: power value
 *
 * Return: the power of x
 */
int find_pow(int x, size_t y)
{
	if (y == NULL)
		return (1);
	else
		return (x * find_pow(x, y - 1));
}

/**
 * seq_generator - generate sequence
 * @size: sequence size
 *
 * Return: pointer to the address of sequence
 */
int *seq_generator(size_t size)
{
	size_t n = 0;
	int i = 0, nth_term, *sequence;

	sequence = malloc(sizeof(int) * size);
	if (sequence == NULL)
		return (NULL);

	nth_term = 0;
	while (n < size)
	{
		nth_term = nth_term + find_pow(3, n);
		sequence[i] = nth_term;
		n++;
		i++;
	}
	return (sequence);
}

/**
 * reverse_seq - reverse sequence
 * @sequence: pointer to the address of sequence
 * @size: sequence size
 *
 * Return: reverse sequence
 */
int *reverse_seq(int *sequence, size_t size)
{
	int *rev_seq;
	size_t j = 0, seq_index;

	rev_seq = malloc(sizeof(int) * size);
	if (rev_seq == NULL)
		return (NULL);

	seq_index = size - 1;
	while (j < size)
	{
		rev_seq[j] = sequence[seq_index];
		j++;
		seq_index--;
	}
	return (rev_seq);
}

/**
 * shell_sort - Shell sort algorithm
 * @array: array to be sorted
 * @size: size of array
 *
 * Return: nothing
 */
void shell_sort(int *array, size_t size)
{
	int k, flag = 0;
	int temp, *sequence, *rev_seq, hold;
	size_t i, seq_index = 0;

	sequence = seq_generator(size);
	if (sequence == NULL)
		return;

	rev_seq = reverse_seq(sequence, size);
	if (rev_seq == NULL)
		return;

	while (seq_index < size)
	{
		for (i = rev_seq[seq_index]; i < size; i++)
		{
			temp = array[i];
			hold = rev_seq[seq_index];
			for (k = i; k >= hold && array[k - hold] > temp; k = k - hold)
			{
				array[k] = array[k - rev_seq[seq_index]];
			}
			array[k] = temp;
			flag = 1;
		}
		if (flag)
			print_array(array, size);
		seq_index++;
	}
	free(sequence);
	free(rev_seq);
}
