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

int	check_path(t_matrices *matrix, t_xy dims, t_xy e, t_mlx *mlx)
{
	t_xy	curr_cell;
	t_xy	child_cell;
	t_const	constants;
	t_xys	coords;
	t_xy	tmp_xy;

	ft_lstclear(&mlx->lst);
	mlx->lst = NULL;
	init_nsew(matrix, dims, e);
	constants.exit_exists = 0;
	constants.coin_count = get_coin_count(matrix->char_info, dims);
	while (check_visited(matrix->pos_info, dims))
	{
		curr_cell = get_min(matrix->pos_info, dims, matrix->char_info);
		matrix->pos_info[curr_cell.row][curr_cell.column].visited = 0;
		if (check_wall(curr_cell.wall, &constants, matrix))
			break ;
		if (curr_cell.row == e.row && \
		curr_cell.column == e.column && constants.coin_count == 0)
			constants.exit_exists = 1;
		coords = pack_coorniates(dims, &curr_cell, &child_cell, e);
		change_weights(matrix, &coords, &constants, mlx);
	}
	printf("Printing the path:\n");
	t_list	*temp;
	temp = mlx->lst;
	tmp_xy = mlx->e_xy;
	while(tmp_xy.row != mlx->p_xy.row || tmp_xy.column != mlx->p_xy.column)
	{
		while (temp != NULL)
		{
			if (temp->content.key.row == tmp_xy.row && temp->content.key.column == tmp_xy.column)
			{
				printf("(%d, %d)\n", temp->content.key.row, temp->content.key.column);
				printf("(%d, %d)\n", temp->content.value.row, temp->content.value.column);
			}
			temp = temp->next;
			tmp_xy = temp->content.value;
		}
	}

	int i2 = -1, k2;
	// printf("\n");
	// while (++i2 < dims.row)
	// {
	// 	k2 = -1;
	// 	while (++k2 < dims.column)
	// 		printf("%d", matrix->pos_info[i2][k2].visited);
	// 	printf("\n");
	// }
//	printf("\n\n\nNumber of remaining coins to collect: %d\n\n", coins);
	i2 = -1;
	while (++i2 < dims.row)
	{
		k2 = -1;
		while (++k2 < dims.column)
		{
			printf("    ");
			if (matrix->pos_info[i2][k2].cost == INT_MAX - 1)
				printf("X");
			else
				printf("%d", matrix->pos_info[i2][k2].cost);
		}
		printf("\n");
	}
	mlx->dims = dims;
	mlx->char_mat = matrix->char_info;
	mlx->pos_mat = matrix->pos_info;
	return (matrix->path_exists);
}
