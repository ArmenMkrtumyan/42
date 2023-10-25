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

int	get_fd(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		printf("\n\nCould not read the file\n\n");
		exit(1);
	}
	return (fd);
}

int	get_coin_count(char **matrix, t_xy dims)
{
	int	i;
	int	k;
	int	coin_count;

	i = -1;
	coin_count = 0;
	while (++i < dims.row)
	{
		k = -1;
		while (++k < dims.column)
		{
			if (matrix[i][k] == 'C')
				coin_count++;
		}
	}
	return (coin_count);
}

t_xy	get_min(t_pos **node, t_xy dims, char **matrix)
{
	t_xy	i_k;
	int		min;
	t_xy	min_coordinates;

	min = INT_MAX;
	i_k.row = -1;
	min_coordinates.wall = 0;
	while (++i_k.row < dims.row)
	{
		i_k.column = -1;
		while (++i_k.column < dims.column)
		{
			if (node[i_k.row][i_k.column].visited == 1 && \
			node[i_k.row][i_k.column].cost < min)
			{
				min = node[i_k.row][i_k.column].cost;
				min_coordinates.row = i_k.row;
				min_coordinates.column = i_k.column;
			}
		}
	}
	if (matrix[min_coordinates.row][min_coordinates.column] == '1')
		min_coordinates.wall = 1;
	return (min_coordinates);
}

int	get_len(char *sentence)
{
	int	i;

	i = 0;
	while (sentence[i] != '\0')
		i++;
	return (i);
}
