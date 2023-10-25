/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:19:14 by amkrtumy          #+#    #+#             */
/*   Updated: 2023/10/06 16:19:15 by amkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	check_wall(int wall, t_const *constants, t_mlx *mlx)
{
	if (wall)
	{
		if (constants->exit_exists == 0)
		{
			printf("\n\nCouldnt Find an EXIT!!!!\n\n");
			mlx->path_exists = 0;
		}
		else
		{
			if (constants->coin_count == 0)
			{
				if (mlx->enemy_perspective != 1)
					printf("\n\nEXIT EXISTS AND COINS ARE ACCESSIBLE!!!!\n\n");
				mlx->path_exists = 1;
			}
			else
			{
				if (mlx->enemy_perspective != 1)
					printf("\n\nEXIT EXISTS BUT COINS ARE UNAVAILABLE!!!!\n\n");
				mlx->path_exists = 0;
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

int	check_dimensions_map(int fd, t_xy *dims)
{
	int		sz;
	char	symbol[2];
	int		fix_columns;

	fix_columns = -1;
	sz = 1;
	while (sz != 0)
	{
		sz = read(fd, symbol, 1);
		symbol[sz] = '\0';
		if ((dims->row) - 1 == 0)
			fix_columns++;
		(dims->column)++;
		if (symbol[0] == '\n')
		{
			(dims->row)++;
			if (dims->column != fix_columns)
				return (0);
			dims->column = -1;
		}
	}
	if (dims->column != fix_columns || dims->row < 3)
		return (0);
	dims->column = fix_columns;
	return (1);
}

int	check_file_name(char *file_name)
{
	int	len;

	len = get_len(file_name);
	while (file_name[len] != '.')
		len--;
	if (len == 0)
	{
		printf("Error\nInput correct map name!\n");
		return (0);
	}
	if (ft_strncmp(&file_name[len], ".ber", 4) != 0)
	{
		printf("Error\nInput correct map name!\n");
		return (0);
	}
	return (1);
}

void	checkings(int fd1, int fd2, t_xy dims, t_mlx *mlx)
{
	t_inside		insides;

	if (check_dimensions_map(fd1, &dims))
	{
		if (check_insides_map(fd2, dims, &insides, mlx) == 0)
		{
			mlx->enemy_perspective = 0;
			printf("\n\nCORRECT MAP INSIDES, CHECKING PATHS...");
			check_path(insides.dims, insides.e_xy, mlx, 0);
			if (mlx->path_exists == 1)
				printf("\n\nCORRECT PATHS...Launching the game\n\n");
			else
				on_exit("Issue with paths!");
		}
	}
	else
		on_exit("\n\nWRONG DIMENSIONS\n\n");
}
