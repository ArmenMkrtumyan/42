/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:18:57 by amkrtumy          #+#    #+#             */
/*   Updated: 2023/10/06 16:19:02 by amkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	on_exit(char *error_message)
{
	printf("\n\n%s\n\n", error_message);
	exit(1);
}

void	redraw_map(int pos, t_mlx mlx, int p_row, int p_column)
{
	if (!(p_row == mlx.e_xy.row && p_column == mlx.e_xy.column))
	{
		mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, mlx.empty_space, mlx.xy * mlx.e_xy.column, mlx.xy * mlx.e_xy.row);
		mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, mlx.door_closed, mlx.xy * mlx.e_xy.column, mlx.xy * mlx.e_xy.row);
		mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, mlx.empty_space, mlx.xy * p_column, mlx.xy * p_row);
		mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, mlx.pacman_eating, mlx.xy * p_column, mlx.xy * p_row);
	}
	else
		mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, mlx.pacman_eating, mlx.xy * p_column, mlx.xy * p_row);
	if (pos == UP && !(p_column == mlx.e_xy.column && p_row + 1 == mlx.e_xy.row))
		mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, mlx.empty_space, p_column * mlx.xy, (p_row + 1) * mlx.xy);
	else if (pos == DOWN && !(p_column == mlx.e_xy.column && p_row -1 == mlx.e_xy.row))
		mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, mlx.empty_space, p_column * mlx.xy, (p_row - 1) * mlx.xy);
	else if (pos == LEFT && !(p_column + 1 == mlx.e_xy.column && p_row == mlx.e_xy.row))
		mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, mlx.empty_space, (p_column + 1) * mlx.xy, p_row * mlx.xy);
	else if (pos == RIGHT && !(p_column - 1 == mlx.e_xy.column && p_row == mlx.e_xy.row))
		mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, mlx.empty_space, (p_column - 1) * mlx.xy, p_row * mlx.xy);
}

void	redraw_map_enemy(int pos, t_mlx mlx, int e_row, int e_column)
{
	if (!(e_row == mlx.e_xy.row && e_column == mlx.e_xy.column))
	{
		mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win,
			mlx.empty_space,
			mlx.xy * mlx.e_xy.column, mlx.xy * mlx.e_xy.row);
		mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win,
			mlx.door_closed,
			mlx.xy * mlx.e_xy.column, mlx.xy * mlx.e_xy.row);
		mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win,
			mlx.empty_space,
			mlx.xy * e_column, mlx.xy * e_row);
		mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win,
			mlx.enemy,
			mlx.xy * e_column, mlx.xy * e_row);
	}
	else
		mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, mlx.enemy, mlx.xy * e_column, mlx.xy * e_row);
	if (pos == UP && !(e_column == mlx.e_xy.column && e_row + 1 == mlx.e_xy.row))
	{
		if (mlx.char_mat[e_row + 1][e_column] == 'C')
			mlx_put_image_to_window(mlx.mlx_ptr,
				mlx.mlx_win, mlx.coin, e_column * mlx.xy, (e_row + 1) * mlx.xy);
		else
			mlx_put_image_to_window(mlx.mlx_ptr,
				mlx.mlx_win, mlx.empty_space, e_column * mlx.xy, (e_row + 1) * mlx.xy);
	}
	else if (pos == DOWN && !(e_column == mlx.e_xy.column && e_row - 1 == mlx.e_xy.row))
	{
		if (mlx.char_mat[e_row - 1][e_column] == 'C')
			mlx_put_image_to_window(mlx.mlx_ptr,
				mlx.mlx_win, mlx.coin,
				e_column * mlx.xy, (e_row - 1) * mlx.xy);
		else
			mlx_put_image_to_window(mlx.mlx_ptr,
				mlx.mlx_win, mlx.empty_space,
				e_column * mlx.xy, (e_row - 1) * mlx.xy);
	}
	else if (pos == LEFT && !(e_column + 1 == mlx.e_xy.column && e_row == mlx.e_xy.row))
	{
		if (mlx.char_mat[e_row][e_column + 1] == 'C')
			mlx_put_image_to_window(mlx.mlx_ptr,
				mlx.mlx_win, mlx.coin,
				(e_column + 1) * mlx.xy, e_row * mlx.xy);
		else
			mlx_put_image_to_window(mlx.mlx_ptr,
				mlx.mlx_win, mlx.empty_space,
				(e_column + 1) * mlx.xy, e_row * mlx.xy);
	}
	else if (pos == RIGHT && !(e_column - 1 == mlx.e_xy.column && e_row == mlx.e_xy.row))
	{
		if (mlx.char_mat[e_row][e_column - 1] == 'C')
			mlx_put_image_to_window(mlx.mlx_ptr,
				mlx.mlx_win, mlx.coin,
				(e_column - 1) * mlx.xy, e_row * mlx.xy);
		else
			mlx_put_image_to_window(mlx.mlx_ptr,
				mlx.mlx_win, mlx.empty_space,
				(e_column - 1) * mlx.xy, e_row * mlx.xy);
	}
}

void	draw_map(t_mlx *mlx)
{
	int	k;
	int	i;

	k = 0;
	i = 0;
	while (mlx->char_mat[k])
	{
		i = 0;
		while (mlx->char_mat[k][i])
		{
			if (mlx->char_mat[k][i] == '0')
				mlx_put_image_to_window(mlx->mlx_ptr,
					mlx->mlx_win, mlx->empty_space, i * mlx->xy, k * mlx->xy);
			else if (mlx->char_mat[k][i] == '1')
				mlx_put_image_to_window(mlx->mlx_ptr,
					mlx->mlx_win, mlx->wall, i * mlx->xy, k * mlx->xy);
			else if (mlx->char_mat[k][i] == 'C')
				mlx_put_image_to_window(mlx->mlx_ptr,
					mlx->mlx_win, mlx->coin, i * mlx->xy, k * mlx->xy);
			else if (mlx->char_mat[k][i] == 'M')
				mlx_put_image_to_window(mlx->mlx_ptr,
					mlx->mlx_win, mlx->enemy, i * mlx->xy, k * mlx->xy);
			else if (mlx->char_mat[k][i] == 'P')
				mlx_put_image_to_window(mlx->mlx_ptr,
					mlx->mlx_win, mlx->pacman_eating, i * mlx->xy, k * mlx->xy);
			else if (mlx->char_mat[k][i] == 'E')
				mlx_put_image_to_window(mlx->mlx_ptr,
					mlx->mlx_win, mlx->door_closed, i * mlx->xy, k * mlx->xy);
			i++;
		}
		k++;
	}
}
