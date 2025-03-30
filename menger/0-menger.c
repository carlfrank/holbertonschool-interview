#include "menger.h"
#include <stdio.h>
#include <math.h>

/**
 * draw_char - Draws a character for a given level of the Menger Sponge.
 *
 * @level: Level of the Menger Sponge.
 * @x: X coordinate of the character in the current level.
 * @y: Y coordinate of the character in the current level.
 *
 * Description:
 *  This function is used to draw a character at a given level of the
 *  Menger Sponge. It considers the current level and the coordinates of
 *  the character to decide whether it should be drawn as a space or
 *  as a '#' character.
 */
void draw_char(int level, int x, int y)
{
	int size = (int)pow(3, level - 1);

	if (level == 0)
	{
		printf("#");
		return;
	}

	if (x >= size && x < size * 2 && y >= size && y < size * 2)
	{
		printf(" ");
	}
	else
	{
		draw_char(level - 1, x % size, y % size);
	}
}

/**
 * draw_level - Draws a complete level of the Menger Sponge.
 *
 * @level: Level of the Menger Sponge to draw.
 *
 * Description:
 *  This function draws an entire level of the Menger Sponge.
 *  It uses the draw_char function to draw each character in the level.
 */
void draw_level(int level)
{
	int size = (int)pow(3, level);
	int y, x;

	for (y = 0; y < size; y++)
	{
		for (x = 0; x < size; x++)
		{
			draw_char(level, x, y);
		}
		printf("\n");
	}
}

/**
 * menger - Draws a Menger Sponge of a given level.
 *
 * @level: Level of the Menger Sponge to draw.
 *
 * Description:
 *  This function draws a Menger Sponge of the specified level.
 *  If the level is less than zero, the function does nothing.
 *  Otherwise, it calls draw_level to draw the Menger Sponge.
 */
void menger(int level)
{
	if (level < 0)
	{
		return;
	}

	draw_level(level);
}
