#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge - merge two sorted subarrays
 */
void merge(int *array, int *buffer, size_t left, size_t mid, size_t right)
{
	size_t i = left, j = mid, k = left;

	printf("Merging...\n[left]: ");
	for (size_t x = left; x < mid; x++)
		printf("%d%s", array[x], x + 1 < mid ? ", " : "\n");

	printf("[right]: ");
	for (size_t x = mid; x < right; x++)
		printf("%d%s", array[x], x + 1 < right ? ", " : "\n");

	while (i < mid && j < right)
	{
		if (array[i] <= array[j])
			buffer[k++] = array[i++];
		else
			buffer[k++] = array[j++];
	}
	while (i < mid)
		buffer[k++] = array[i++];
	while (j < right)
		buffer[k++] = array[j++];

	for (i = left; i < right; i++)
		array[i] = buffer[i];

	printf("[Done]: ");
	for (i = left; i < right; i++)
		printf("%d%s", array[i], i + 1 < right ? ", " : "\n");
}

/**
 * merge_sort_recursive - recursive helper function for merge sort
 */
void merge_sort_recursive(int *array, int *buffer, size_t left, size_t right)
{
	if (right - left < 2)
		return;

	size_t mid = left + (right - left) / 2;

	merge_sort_recursive(array, buffer, left, mid);
	merge_sort_recursive(array, buffer, mid, right);
	merge(array, buffer, left, mid, right);
}

/**
 * merge_sort - sorts array using merge sort (top-down)
 */
void merge_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	int *buffer = malloc(sizeof(int) * size);
	if (!buffer)
		return;

	merge_sort_recursive(array, buffer, 0, size);
	free(buffer);
}
