#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge - Merges two subarrays into a sorted one.
 * @array: Original array.
 * @buffer: Temp buffer.
 * @left: Start index of left subarray.
 * @mid: Middle index.
 * @right: End index of right subarray.
 */
void merge(int *array, int *buffer, size_t left, size_t mid, size_t right)
{
	size_t i, j, k;

	printf("Merging...\n[left]: ");
	print_array(array + left, mid - left);

	printf("[right]: ");
	print_array(array + mid, right - mid);

	i = left;
	j = mid;

	for (k = left; k < right; k++)
	{
		if (i < mid && (j >= right || array[i] <= array[j]))
		{
			buffer[k] = array[i];
			i++;
		}
		else
		{
			buffer[k] = array[j];
			j++;
		}
	}

	for (k = left; k < right; k++)
		array[k] = buffer[k];

	printf("[Done]: ");
	print_array(array + left, right - left);
}

/**
 * top_down_split_merge - Recursively splits and merges the array.
 * @array: The array to sort.
 * @buffer: Buffer array for merging.
 * @left: Start index.
 * @right: End index.
 */
void top_down_split_merge(int *array, int *buffer, size_t left, size_t right)
{
	size_t mid;

	if (right - left < 2)
		return;

	mid = left + (right - left) / 2;

	top_down_split_merge(array, buffer, left, mid);
	top_down_split_merge(array, buffer, mid, right);
	merge(array, buffer, left, mid, right);
}

/**
 * merge_sort - Sorts an array using the Merge Sort algorithm.
 * @array: The array to sort.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (!array || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);

	if (!buffer)
		return;

	top_down_split_merge(array, buffer, 0, size);
	free(buffer);
}
