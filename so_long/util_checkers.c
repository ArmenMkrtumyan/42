#include "so_long.h"

int	check_visited(t_pos **matrix, t_xy dims)
{
	int	i;
	int	k;

	i = -1;
	while (++i < dims.row)
	{
		k = -1;
		while (++k < dims.column)
		{
			if (matrix[i][k].visited == 1)
				return (1);
		}
	}
	return (0);
}

void	check_exit(t_xys *coords, t_const *constants)
{
	if (coords->child_cell->row == coords->e_xy.row \
	&& coords->child_cell->column == coords->e_xy.column)
		constants->exit_exists = 1;
}

int	check_wall(int wall, t_const *constants, t_matrices *matrices)
{
	if (wall)
	{
		if (constants->exit_exists == 0)
		{
			printf("\n\nCouldnt Find an EXIT!!!!\n\n");
			matrices->path_exists = 0;
		}
		else
		{
			if (constants->coin_count == 0)
			{
				printf("\n\nEXIT EXISTS AND COINS ARE ACCESSIBLE!!!!\n\n");
				matrices->path_exists = 1;
			}
			else
			{
				printf("\n\nEXIT EXISTS BUT COINS ARE UNAVAILABLE!!!!\n\n");
				matrices->path_exists = 0;
			}
		}
		return (1);
	}
	return (0);
}

int	ft_strncmp(char *str1, char *str2, int n)
{
	int	i;

	i = 0;
	if (get_len(str1) != 4)
		return (1);
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (1);
		i++;
	}
	return (0);
}
