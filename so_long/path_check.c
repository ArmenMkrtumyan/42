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

int	check_path(t_matrices *matrices, t_coordinate dimensions, t_coordinate Es)
{
	t_coordinate current_cell;
	t_coordinate child_cell;
	int coin_count;
	int exit_exists;

	initialize_NSEW(matrices, dimensions, Es);
	exit_exists = 0;
	coin_count = get_coin_count(matrices->passed_matrix, dimensions);
	while (check_visited(matrices->full_matrix, dimensions))
	{
		current_cell = get_minimum(matrices->full_matrix, dimensions, matrices->passed_matrix);
		matrices->full_matrix[current_cell.row][current_cell.column].visited = 0;
		if (check_wall(current_cell.wall, exit_exists, coin_count, matrices))
			break;
		if (current_cell.row == Es.row && current_cell.column == Es.column && coin_count == 0)
			exit_exists = 1;
		change_weights(matrices, dimensions, &current_cell, &Es, &child_cell, &coin_count, &exit_exists);
	}
	int i2 = -1, k2;
	printf("\n");
	while (++i2 < dimensions.row)
	{
		k2 = -1;
		while (++k2 < dimensions.column)
			printf("%d", matrices->full_matrix[i2][k2].visited);
		printf("\n");
	}
	printf("\n\n\nNumber of remaining coins to collect: %d\n\n", coin_count);
	i2 = -1;
	while (++i2 < dimensions.row)
	{
		k2 = -1;
		while (++k2 < dimensions.column)
		{
			printf("               ");
			if (matrices->full_matrix[i2][k2].cost == INT_MAX - 1)
				printf("X");
			else
				printf("%d", matrices->full_matrix[i2][k2].cost);
		}
		printf("\n");
	}
	return (matrices->path_exists);
}
