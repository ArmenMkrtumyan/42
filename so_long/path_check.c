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

void direction_init(char **maze, t_position **matrix, int row, int col)
{
	if (maze[row + 1][col] != '1')
		(matrix[row][col]).S = 1;
	if (maze[row - 1][col] != '1')
		(matrix[row][col]).N = 1;
	if (maze[row][col + 1] != '1')
		(matrix[row][col]).E = 1;
	if (maze[row][col - 1] != '1')
		(matrix[row][col]).W = 1;
}

int check_visited(t_position **matrix, t_coordinate dimensions)
{
	int i;
	int k;

	i = -1;
	while (++i < dimensions.row)
	{
		k = -1;
		while (++k < dimensions.column)
		{
			if (matrix[i][k].visited == 1)
				return (1);
		}
	}
	return (0);
}

t_coordinate get_minimum(t_position **node, t_coordinate dimensions, char **matrix)
{
	t_coordinate i_k;
	int min;
	t_coordinate min_coordinates;

	min = INT_MAX;
	i_k.row = 0;
	min_coordinates.wall = 0;
	while (i_k.row < dimensions.row)
	{
		i_k.column = 0;
		while (i_k.column < dimensions.column)
		{
			if (node[i_k.row][i_k.column].visited == 1 && node[i_k.row][i_k.column].cost < min)
			{
				min = node[i_k.row][i_k.column].cost;
				min_coordinates.row = i_k.row;
				min_coordinates.column = i_k.column;
			}
			i_k.column++;
		}
		i_k.row++;
	}
	if (matrix[min_coordinates.row][min_coordinates.column] == '1')
		min_coordinates.wall = 1;
	return (min_coordinates);
}

int get_coin_count(char **matrix, t_coordinate dimensions)
{
	int i;
	int k;
	int coin_count;

	i = -1;
	coin_count = 0;
	while (++i < dimensions.row)
	{
		k = -1;
		while (++k < dimensions.column)
		{
			if (matrix[i][k] == 'C')
				coin_count++;
		}
	}
	return (coin_count);
}

int check_wall_aka_the_end(int current_cell_wall, int exit_exists, int coin_count)
{
	if (current_cell_wall)
	{
		if (exit_exists == 0)
			printf("\n\nCouldnt Find an EXIT!!!!\n\n");
		else
		{
			if (coin_count == 0)
				printf("\n\nEXIT EXISTS AND COINS ARE COLLECTED!!!!\n\n");
			else
				printf("\n\nEXIT EXISTS BUT COULD NOT COLLECT ALL THE COINS!!!!\n\n");
		}
		return (0);
	}
	return (1);
}

void assign_cell(int k, t_coordinate *child_cell, t_coordinate *current_cell)
{
	switch (k)
	{
	case 0:
		child_cell->row = current_cell->row - 1;
		child_cell->column = current_cell->column;
		break;
	case 1:
		child_cell->row = current_cell->row + 1;
		child_cell->column = current_cell->column;
		break;
	case 2:
		child_cell->row = current_cell->row;
		child_cell->column = current_cell->column + 1;
		break;
	case 3:
		child_cell->row = current_cell->row;
		child_cell->column = current_cell->column - 1;
		break;
	}
	// if (k == 0)
	// {

	// }
	// else if (k == 1)
	// {

	// }
	// else if (k == 2)
	// {

	// }
	// else if (k == 3)
	// {

	// }
}

int check_wall(int wall, int exit_exists, int coin_count)
{
	if (wall)
	{
		if (exit_exists == 0)
			printf("\n\nCouldnt Find an EXIT!!!!\n\n");
		else
		{
			if (coin_count == 0)
				printf("\n\nEXIT EXISTS AND COINS ARE COLLECTED!!!!\n\n");
			else
				printf("\n\nEXIT EXISTS BUT COULD NOT COLLECT ALL THE COINS!!!!\n\n");
		}
		return (1);
	}
	return (0);
}

void initialize_directions(int *directions, t_matrices *matrices, t_coordinate current_cell)
{
	directions[0] = matrices->full_matrix[current_cell.row][current_cell.column].N;
	directions[1] = matrices->full_matrix[current_cell.row][current_cell.column].S;
	directions[2] = matrices->full_matrix[current_cell.row][current_cell.column].E;
	directions[3] = matrices->full_matrix[current_cell.row][current_cell.column].W;
	directions[4] = '\0';
}

void fix_coordinates(int k, t_coordinate *child_cell, t_coordinate current_cell)
{
	if (k == 0)
	{
		child_cell->row = current_cell.row - 1;
		child_cell->column = current_cell.column;
	}
	else if (k == 1)
	{
		child_cell->row = current_cell.row + 1;
		child_cell->column = current_cell.column;
	}
	else if (k == 2)
	{
		child_cell->row = current_cell.row;
		child_cell->column = current_cell.column + 1;
	}
	else if (k == 3)
	{
		child_cell->row = current_cell.row;
		child_cell->column = current_cell.column - 1;
	}
}

void check_exit(int child_row, int child_column, int E_row, int E_column, int *exit_exists)
{
	if (child_row == E_row && child_column == E_column)
		*exit_exists = 1;
}

void change_weights(t_matrices *matrices, t_coordinate dimensions, t_coordinate *current_cell, t_coordinate *E_coordinates, t_coordinate *child_cell, int *coin_count, int *exit_exists)
{
	static int directions[5];
	int k;
	int temp_dist;

	initialize_directions(directions, matrices, *current_cell);
	k = 0;
	while (k < 4)
	{
		if (directions[k] == 1)
		{
			temp_dist = 0;
			fix_coordinates(k, child_cell, *current_cell);
			check_exit(child_cell->row, child_cell->column, E_coordinates->row, E_coordinates->column, exit_exists);
			if (matrices->full_matrix[child_cell->row][child_cell->column].visited == 0 ||
				matrices->full_matrix[child_cell->row][child_cell->column].cost != INT_MAX - 1)
			{
				k++;
				continue;
			}
			temp_dist = matrices->full_matrix[current_cell->row][current_cell->column].cost;
			if (matrices->passed_matrix[child_cell->row][child_cell->column] == 'C')
			{
				temp_dist += 100;
				*coin_count -= 1;
			}
			else
				temp_dist = matrices->full_matrix[current_cell->row][current_cell->column].cost + 1000;
			if (temp_dist < matrices->full_matrix[child_cell->row][child_cell->column].cost)
				matrices->full_matrix[child_cell->row][child_cell->column].cost = temp_dist;
		}
		k++;
	}
}

void check_path(t_matrices *matrices, t_coordinate dimensions, t_coordinate E_coordinates)
{
	int i;
	int k;
	t_coordinate current_cell;
	t_coordinate child_cell;
	int coin_count;
	int exit_exists;

	exit_exists = 0;
	coin_count = get_coin_count(matrices->passed_matrix, dimensions);
	i = 0;
	while (check_visited(matrices->full_matrix, dimensions))
	{
		current_cell = get_minimum(matrices->full_matrix, dimensions, matrices->passed_matrix);
		matrices->full_matrix[current_cell.row][current_cell.column].visited = 0;
		if (check_wall(current_cell.wall, exit_exists, coin_count))
			break;
		if (current_cell.row == E_coordinates.row && current_cell.column == E_coordinates.column && coin_count == 0)
			exit_exists = 1;
		change_weights(matrices, dimensions, &current_cell, &E_coordinates, &child_cell, &coin_count, &exit_exists);
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
}

int assign_NSEW(t_matrices *matrices, t_coordinate dimensions, t_coordinate E_coordinate)
{
	t_coordinate i_k;

	i_k.row = -1;
	while (++i_k.row < dimensions.row)
	{
		i_k.column = -1;
		while (++i_k.column < dimensions.column)
		{
			(matrices->full_matrix[i_k.row][i_k.column]).N = 0;
			(matrices->full_matrix[i_k.row][i_k.column]).S = 0;
			(matrices->full_matrix[i_k.row][i_k.column]).E = 0;
			(matrices->full_matrix[i_k.row][i_k.column]).W = 0;
			if (i_k.row == 0)
				matrices->full_matrix[i_k.row][i_k.column].N = 0;
			else if (i_k.row == dimensions.row - 1)
				matrices->full_matrix[i_k.row][i_k.column].S = 0;
			else if (i_k.column == 0)
				matrices->full_matrix[i_k.row][i_k.column].W = 0;
			else if (i_k.column == dimensions.column - 1)
				matrices->full_matrix[i_k.row][i_k.column].E = 0;
			else
				direction_init(matrices->passed_matrix, matrices->full_matrix, i_k.row, i_k.column);
		}
	}
	check_path(matrices, dimensions, E_coordinate);
	return (1);
}
