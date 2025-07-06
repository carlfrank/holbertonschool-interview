#include "sort.h"
#include <stdlib.h>

/**
 * get_max - Gets the maximum value in an array
 * @array: The array to search
 * @size: The size of the array
 * Return: The maximum value
 */
int get_max(int *array, size_t size)
{
	size_t i;
	int max = array[0];

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * counting_sort_digit - Performs counting sort based on a specific digit
 * @array: The array to sort
 * @size: The size of the array
 * @exp: The current digit exponent (1, 10, 100, etc.)
 */
void counting_sort_digit(int *array, size_t size, int exp)
{
	int output[1024]; /* Assumption: array won't exceed 1024 elements */
	int count[10] = {0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size; i > 0; i--)
	{
		output[count[(array[i - 1] / exp) % 10] - 1] = array[i - 1];
		count[(array[i - 1] / exp) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	print_array(array, size);
}

/**
 * radix_sort - Sorts an array using LSD radix sort
 * @array: The array to sort
 * @size: The size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;

	if (!array || size < 2)
		return;

	max = get_max(array, size);

	for (exp = 1; max / exp > 0; exp *= 10)
		counting_sort_digit(array, size, exp);
}
