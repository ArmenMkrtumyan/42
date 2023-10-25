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
	t_xy		curr_cell;
	t_xy	child_cell;
	t_const	constants;
	t_xys	coords;
	t_xy	dest_xy;
	t_xy		start_xy;
	t_list		*temp;
	t_list		*enemy_path;
	t_key_value	last_xy;

	ft_lstclear(&mlx->lst);
	mlx->lst = NULL;
	init_nsew(mlx, dims, e);
	constants.exit_exists = 0;
	constants.coin_count = get_coin_count(mlx->char_mat, dims);
	while (check_visited(mlx->pos_mat, dims))
	{
		curr_cell = get_min(mlx->pos_mat, dims, mlx->char_mat);
		mlx->pos_mat[curr_cell.row][curr_cell.column].visited = 0;
		if (check_wall(curr_cell.wall, &constants, mlx))
			break ;
		if (curr_cell.row == e.row && \
		curr_cell.column == e.column && constants.coin_count == 0)
			constants.exit_exists = 1;
		coords = pack_coorniates(dims, &curr_cell, &child_cell, e);
		change_weights(&coords, &constants, mlx);
	}
	if (mlx->enemy_perspective == 1)
	{
		dest_xy = mlx->p_xy;
		start_xy = mlx->enemies[enemy_num];
		last_xy.value.row = mlx->p_xy.row;
		last_xy.value.column = mlx->p_xy.column;
		ft_lstadd_back(&mlx->enemies[enemy_num].enemy_path, ft_lstnew(last_xy));
		while (dest_xy.row != start_xy.row || dest_xy.column != start_xy.column)
		{
			temp = mlx->lst;
			while (temp != NULL)
			{
				if (temp->content.key.row == dest_xy.row
					&& temp->content.key.column == dest_xy.column)
				{
					ft_lstadd_back(&(mlx->enemies[enemy_num].enemy_path),
						ft_lstnew(temp->content));
					dest_xy = temp->content.value;
				}
				temp = temp->next;
			}
		}
		temp = mlx->enemies[enemy_num].enemy_path;
		while (temp != NULL)
			temp = temp->next;
	}
	mlx->dims = dims;
}
