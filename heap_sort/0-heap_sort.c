#include "sort.h"

/**
 * swap - Swaps two integers in an array
 *
 * @a: First integer to swap
 * @b: Second integer to swap
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * sift_down - Implements the sift-down heap sort algorithm
 *
 * @array: The array to be sorted
 * @size: Size of the array
 * @root: Index of the root of the subtree
 * @max: Maximum index of the heap
 */
void sift_down(int *array, size_t size, size_t root, size_t max)
{
	size_t largest, left, right;

	largest = root;
	left = 2 * root + 1;
	right = 2 * root + 2;

	/* Compare root with its left child */
	if (left < max && array[left] > array[largest])
		largest = left;

	/* Compare largest with right child */
	if (right < max && array[right] > array[largest])
		largest = right;

	/* If largest is not root, swap and continue to sift down */
	if (largest != root)
	{
		swap(&array[root], &array[largest]);
		print_array(array, size);
		sift_down(array, size, largest, max);
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order
 * using the Heap sort algorithm
 *
 * @array: The array to be sorted
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	/* Build max heap */
	for (i = size / 2 - 1; i >= 0; i--)
		sift_down(array, size, i, size);

	/* Extract elements from the heap one by one */
	for (i = size - 1; i > 0; i--)
	{
		/* Move current root to end */
		swap(&array[0], &array[i]);
		print_array(array, size);

		/* Call sift_down on the reduced heap */
		sift_down(array, size, 0, i);
	}
}
