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

void	change_weights(t_matrices *matrices, t_xys *coords, t_const *constants, t_mlx *mlx)
{
	static int	dir[5];
	int			k;
	t_xy		child;

	init_directions(dir, matrices, *coords->curr_cell);
	k = 0;
	while (k < 4)
	{
		if (dir[k] == 1)
		{
			constants->temp_dist = 0;
			fix_coordinates(k, coords->child_cell, *coords->curr_cell);
			check_exit(coords, constants);
			child.row = coords->child_cell->row;
			child.column = coords->child_cell->column;
			if (matrices->pos_info[child.row][child.column].visited == 0 || \
			matrices->pos_info[child.row][child.column].cost != INT_MAX - 1)
			{
				k++;
				continue ;
			}
			update_weights(matrices, coords, constants, mlx);
		}
		k++;
	}
}

void	update_weights(t_matrices *matrices, t_xys *coords, t_const *constants, t_mlx *mlx)
{
	t_xy		child;
	t_xy		curr;
	t_key_value	content;

	curr.row = coords->curr_cell->row;
	curr.column = coords->curr_cell->column;
	child.row = coords->child_cell->row;
	child.column = coords->child_cell->column;
	constants->temp_dist = matrices->pos_info[curr.row][curr.column].cost;
	if (matrices->char_info[child.row][child.column] == 'C' && mlx->enemy_perspective == 0)
	{
		constants->temp_dist += 1;
		constants->coin_count -= 1;
	}
	else if (matrices->char_info[child.row][child.column] == 'M')
		constants->temp_dist += 100;
	else
		constants->temp_dist = \
		matrices->pos_info[curr.row][curr.column].cost + 10;
	if (constants->temp_dist < matrices->pos_info[child.row][child.column].cost)
	{
		matrices->pos_info[child.row][child.column].cost = constants->temp_dist;
		content.key.row = child.row;
		content.key.column = child.column;
		content.value.row = curr.row;
		content.value.column = curr.column;
		ft_lstadd_back(&(mlx->lst), ft_lstnew(content));
	}
}

void	update_weights_after_move(t_mlx *mlx)
{
	t_matrices	matrix;
	int			enemy_num;

	enemy_num = 0;
	matrix.char_info = mlx->char_mat;
	matrix.pos_info = mlx->pos_mat;
	mlx->enemy_perspective = 1;
	while (enemy_num < mlx->enemy_count)
	{
		mlx->enemies[enemy_num].enemy_path = NULL;
		mlx->start_xy.enemy_path = mlx->enemies[enemy_num].enemy_path;
		update_visited_and_costs(mlx, mlx->enemies[enemy_num]);
		check_path(&matrix, mlx->dims, mlx->e_xy, mlx, enemy_num);
		move_enemy(mlx->enemies[enemy_num].enemy_path, mlx, enemy_num);
		enemy_num++;
	}
}

void	update_visited_and_costs(t_mlx *mlx, t_xy zero_position)
{
	int	k2;
	int	i2;

	i2 = -1;
	while (++i2 < mlx->dims.row)
	{
		k2 = -1;
		while (++k2 < mlx->dims.column)
		{
			mlx->pos_mat[i2][k2].cost = INT_MAX - 1;
			mlx->pos_mat[i2][k2].visited = 1;
		}
	}
	mlx->pos_mat[zero_position.row][zero_position.column].cost = 0;
}