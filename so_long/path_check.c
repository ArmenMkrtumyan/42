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

void	check_path(t_xy dims, t_xy e, t_mlx *mlx, int enemy_num)
{
	t_check_path	check_path_info;
	t_xy		curr_cell;
	t_xy		child_cell;
	t_const		constants;
	t_xys		coords;

	ft_lstclear(&mlx->lst);
	mlx->lst = NULL;
	init_nsew(mlx, dims, e);
	constants.exit_exists = 0;
	constants.coin_count = get_coin_count(mlx->char_mat, dims);
	while (check_visited(mlx->pos_mat, dims))
	{
		curr_cell = get_min(mlx->pos_mat, dims, mlx->char_mat);
		mlx->pos_mat[curr_cell.row][curr_cell.col].visited = 0;
		if (check_wall(curr_cell.wall, &constants, mlx))
			break ;
		if (curr_cell.row == e.row && \
		curr_cell.col == e.col && constants.coin_count == 0)
			constants.exit_exists = 1;
		coords = pack_coorniates(dims, &curr_cell, &child_cell, e);
		change_weights(&coords, &constants, mlx);
	}
	if (mlx->enemy_perspective == 1)
	{
		check_path_info.dest_xy = mlx->p_xy;
		check_path_info.start_xy = mlx->enemies[enemy_num];
		check_path_info.last_xy.value.row = mlx->p_xy.row;
		check_path_info.last_xy.value.col = mlx->p_xy.col;
		ft_lstadd_back(&mlx->enemies[enemy_num].enemy_path, ft_lstnew(check_path_info.last_xy));
		while (check_path_info.dest_xy.row != check_path_info.start_xy.row || check_path_info.dest_xy.col != check_path_info.start_xy.col)
		{
			check_path_info.temp = mlx->lst;
			while (check_path_info.temp != NULL)
			{
				if (check_path_info.temp->content.key.row == check_path_info.dest_xy.row
					&& check_path_info.temp->content.key.col == check_path_info.dest_xy.col)
				{
					ft_lstadd_back(&(mlx->enemies[enemy_num].enemy_path),
						ft_lstnew(check_path_info.temp->content));
					check_path_info.dest_xy = check_path_info.temp->content.value;
				}
				check_path_info.temp = check_path_info.temp->next;
			}
		}
		check_path_info.temp = mlx->enemies[enemy_num].enemy_path;
		while (check_path_info.temp != NULL)
			check_path_info.temp = check_path_info.temp->next;
	}
	mlx->dims = dims;
}
