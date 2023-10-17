#include "so_long.h"

int	check_visited(t_position **matrix, t_coordinate dimensions)
{
	int i;
	int k;

	i = -1;
	while (++i < dimensions.row)
	{
		k = -1;
		while (++k < dimensions.column)
		{
			if (matrix[i][k].visited == 1)
				return (1);
		}
	}
	return (0);
}

void	check_exit(int child_row, int child_column, int E_row, int E_column, int *exit_exists)
{
	if (child_row == E_row && child_column == E_column)
		*exit_exists = 1;
}

int	check_wall(int wall, int exit_exists, int coin_count, t_matrices *matrices)
{
	if (wall)
	{
		if (exit_exists == 0)
		{
			printf("\n\nCouldnt Find an EXIT!!!!\n\n");
			matrices->path_exists = 0;
		}
		else
		{
			if (coin_count == 0)
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

int ft_strncmp(char *str1, char *str2, int n)
{
	int i;

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