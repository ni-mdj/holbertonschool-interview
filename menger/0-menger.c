#include <stdio.h>

#include "menger.h"

/**
 * is_hole - checks if a position must be empty
 * @row: row index
 * @col: column index
 *
 * Return: 1 if this cell is a hole, 0 otherwise
 */
static int is_hole(int row, int col)
{
	while (row > 0 || col > 0)
	{
		if ((row % 3) == 1 && (col % 3) == 1)
			return (1);
		row /= 3;
		col /= 3;
	}
	return (0);
}

/**
 * menger - draws a 2D Menger Sponge
 * @level: level of the sponge
 */
void menger(int level)
{
	int row, col, i, size;

	if (level < 0)
		return;

	size = 1;
	for (i = 0; i < level; i++)
		size *= 3;

	for (row = 0; row < size; row++)
	{
		for (col = 0; col < size; col++)
		{
			if (is_hole(row, col))
				printf(" ");
			else
				printf("#");
		}
		printf("\n");
	}
}
