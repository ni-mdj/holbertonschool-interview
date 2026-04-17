#include "slide_line.h"

/**
 * compact_left - shifts non-zero values to the left
 * @line: array to compact
 * @size: number of elements in @line
 */
static void compact_left(int *line, size_t size)
{
	size_t read, write;

	write = 0;
	for (read = 0; read < size; read++)
	{
		if (line[read] != 0)
		{
			if (write != read)
			{
				line[write] = line[read];
				line[read] = 0;
			}
			write++;
		}
	}

	while (write < size)
		line[write++] = 0;
}

/**
 * compact_right - shifts non-zero values to the right
 * @line: array to compact
 * @size: number of elements in @line
 */
static void compact_right(int *line, size_t size)
{
	size_t read, write;

	write = size;
	for (read = size; read > 0; read--)
	{
		if (line[read - 1] != 0)
		{
			write--;
			if (write != read - 1)
			{
				line[write] = line[read - 1];
				line[read - 1] = 0;
			}
		}
	}

	while (write > 0)
		line[--write] = 0;
}

/**
 * merge_left - merges equal adjacent values to the left
 * @line: array to merge
 * @size: number of elements in @line
 */
static void merge_left(int *line, size_t size)
{
	size_t i;

	for (i = 0; i + 1 < size; i++)
	{
		if (line[i] != 0 && line[i] == line[i + 1])
		{
			line[i] *= 2;
			line[i + 1] = 0;
			i++;
		}
	}
}

/**
 * merge_right - merges equal adjacent values to the right
 * @line: array to merge
 * @size: number of elements in @line
 */
static void merge_right(int *line, size_t size)
{
	size_t i;

	if (size < 2)
		return;

	for (i = size - 1; i > 0;)
	{
		if (line[i] != 0 && line[i] == line[i - 1])
		{
			line[i] *= 2;
			line[i - 1] = 0;
			if (i < 2)
				break;
			i -= 2;
		}
		else
			i--;
	}
}

/**
 * slide_line - slides and merges a line like the game 2048
 * @line: pointer to array of integers
 * @size: number of elements in @line
 * @direction: SLIDE_LEFT or SLIDE_RIGHT
 *
 * Return: 1 on success, 0 on failure
 */
int slide_line(int *line, size_t size, int direction)
{
	if (line == NULL)
		return (0);

	if (direction == SLIDE_LEFT)
	{
		compact_left(line, size);
		merge_left(line, size);
		compact_left(line, size);
		return (1);
	}

	if (direction == SLIDE_RIGHT)
	{
		compact_right(line, size);
		merge_right(line, size);
		compact_right(line, size);
		return (1);
	}

	return (0);
}
