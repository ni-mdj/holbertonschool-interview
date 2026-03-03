#include "sandpiles.h"

/**
 * print_grid - Print a 3x3 grid
 * @grid: The grid to print
 *
 * Return: void
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * is_stable - Check if a sandpile is stable
 * @grid: The grid to check
 *
 * Return: 1 if stable, 0 if unstable
 */
static int is_stable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				return (0);
		}
	}
	return (1);
}

/**
 * topple - Perform one toppling round on unstable cells
 * @grid: The grid to topple
 *
 * Return: void
 */
static void topple(int grid[3][3])
{
	int i, j;
	int temp[3][3];
	int di[] = {-1, 1, 0, 0};
	int dj[] = {0, 0, -1, 1};
	int k;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			temp[i][j] = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{
				temp[i][j] -= grid[i][j];

				for (k = 0; k < 4; k++)
				{
					int ni = i + di[k];
					int nj = j + dj[k];

					if (ni >= 0 && ni < 3 && nj >= 0 && nj < 3)
						temp[ni][nj] += 1;
				}
			}
		}
	}

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid[i][j] += temp[i][j];
}

/**
 * sandpiles_sum - Compute the sum of two sandpiles
 * @grid1: First sandpile (will be modified to contain the result)
 * @grid2: Second sandpile (remains unchanged)
 *
 * Return: void
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}

	while (!is_stable(grid1))
	{
		print_grid(grid1);
		printf("=\n");
		topple(grid1);
	}
}
