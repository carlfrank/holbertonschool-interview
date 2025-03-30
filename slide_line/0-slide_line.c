#include "slide_line.h"

/**
 * left - Slide and merge elements to the left
 * @line: Pointer to the array of integers
 * @size: Number of elements in the array
 */
static void left(int *line, size_t size)
{
	int i, j, k;

	for (i = 0; i < (int)size; i++)
	{
		if (line[i] == 0)
			continue;
		for (j = i + 1; j < (int)size; j++)
		{
			if (line[j] != 0)
				break;
		}
		if (j == (int)size)
			break;
		if (line[i] == line[j])
		{
			line[i] *= 2;
			line[j] = 0;
		}
	}
	for (i = 0, k = 0; i < (int)size; i++)
	{
		if (line[i] != 0)
		{
			line[k++] = line[i];
		}
	}
	for (; k < (int)size; k++)
	{
		line[k] = 0;
	}
}

/**
 * right - Slide and merge elements to the right
 * @line: Pointer to the array of integers
 * @size: Number of elements in the array
 */
static void right(int *line, size_t size)
{
	int i, j, k;

	for (i = size - 1; i >= 0; i--)
	{
		if (line[i] == 0)
			continue;
		for (j = i - 1; j >= 0; j--)
		{
			if (line[j] != 0)
				break;
		}
		if (j < 0)
			break;
		if (line[i] == line[j])
		{
			line[i] *= 2;
			line[j] = 0;
		}
	}
	for (i = size - 1, k = size - 1; i >= 0; i--)
	{
		if (line[i] != 0)
		{
			line[k--] = line[i];
		}
	}
	for (; k >= 0; k--)
	{
		line[k] = 0;
	}
}

/**
 * slide_line - Slides and merges an array of integers
 * @line: Pointer to the array of integers
 * @size: Number of elements in the array
 * @direction: Direction to slide (SLIDE_LEFT or SLIDE_RIGHT)
 *
 * Return: 1 upon success, or 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);

	if (direction == SLIDE_LEFT)
		left(line, size);
	else if (direction == SLIDE_RIGHT)
		right(line, size);

	return (1);
}