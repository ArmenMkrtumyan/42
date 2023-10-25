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

void	check_pos(t_mlx *mlx, int pos, int row, int col)
{
	mlx->char_mat[row][col] = '0';
	if (pos == UP)
	{
		mlx->char_mat[row - 1][col] = 'P';
		mlx->p_xy.row = row - 1;
	}
	else if (pos == DOWN)
	{
		mlx->char_mat[row + 1][col] = 'P';
		mlx->p_xy.row = row + 1;
	}
	else if (pos == LEFT)
	{
		mlx->char_mat[row][col - 1] = 'P';
		mlx->p_xy.col = col - 1;
	}
	else if (pos == RIGHT)
	{
		mlx->char_mat[row][col + 1] = 'P';
		mlx->p_xy.col = col + 1;
	}
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
