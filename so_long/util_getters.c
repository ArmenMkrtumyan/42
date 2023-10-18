#include "so_long.h"

int	get_fd(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		printf("\n\nCould not read the file\n\n");
		exit(1);
	}
	return (fd);
}

int	get_coin_count(char **matrix, t_coordinate dimensions)
{
	int i;
	int k;
	int coin_count;

	i = -1;
	coin_count = 0;
	while (++i < dimensions.row)
	{
		k = -1;
		while (++k < dimensions.column)
		{
			if (matrix[i][k] == 'C')
				coin_count++;
		}
	}
	return (coin_count);
}

t_coordinate	get_min(t_pos **node, t_coordinate dimensions, char **matrix)
{
	t_coordinate i_k;
	int min;
	t_coordinate min_coordinates;

	min = INT_MAX;
	i_k.row = 0;
	min_coordinates.wall = 0;
	while (i_k.row < dimensions.row)
	{
		i_k.column = 0;
		while (i_k.column < dimensions.column)
		{
			if (node[i_k.row][i_k.column].visited == 1 && node[i_k.row][i_k.column].cost < min)
			{
				min = node[i_k.row][i_k.column].cost;
				min_coordinates.row = i_k.row;
				min_coordinates.column = i_k.column;
			}
			i_k.column++;
		}
		i_k.row++;
	}
	if (matrix[min_coordinates.row][min_coordinates.column] == '1')
		min_coordinates.wall = 1;
	return (min_coordinates);
}

int	get_len(char *sentence)
{
	int i;

	i = 0;
	while (sentence[i] != '\0')
		i++;
	return (i);
}