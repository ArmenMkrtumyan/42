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

int	check_path(t_matrices *matrix, t_coordinate dimensions, t_coordinate e)
{
	t_coordinate	curr_cell;
	t_coordinate	child_cell;
	int				coins;
	int				exit_exists;
	t_coords		coords;

	initialize_NSEW(matrix, dimensions, e);
	exit_exists = 0;
	coins = get_coin_count(matrix->char_info, dimensions);
	while (check_visited(matrix->pos_info, dimensions))
	{
		curr_cell = get_min(matrix->pos_info, dimensions, matrix->char_info);
		matrix->pos_info[curr_cell.row][curr_cell.column].visited = 0;
		if (check_wall(curr_cell.wall, exit_exists, coins, matrix))
			break ;
		if (curr_cell.row == e.row && \
		curr_cell.column == e.column && coins == 0)
			exit_exists = 1;
		coords = pack_coorniates(dimensions, &curr_cell, &child_cell, e);
		change_weights(matrix, &coords, &coins, &exit_exists);
	}
	return (matrix->path_exists);
}
// 	int i2 = -1, k2;
// 	printf("\n");
// 	while (++i2 < dimensions.row)
// 	{
// 		k2 = -1;
// 		while (++k2 < dimensions.column)
// 			printf("%d", matrix->pos_info[i2][k2].visited);
// 		printf("\n");
// 	}
// //	printf("\n\n\nNumber of remaining coins to collect: %d\n\n", coins);
// 	i2 = -1;
// 	while (++i2 < dimensions.row)
// 	{
// 		k2 = -1;
// 		while (++k2 < dimensions.column)
// 		{
// 			printf("    ");
// 			if (matrix->pos_info[i2][k2].cost == INT_MAX - 1)
// 				printf("X");
// 			else
// 				printf("%d", matrix->pos_info[i2][k2].cost);
// 		}
// 		printf("\n");
// 	}
