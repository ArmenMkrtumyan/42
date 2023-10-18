#include "so_long.h"

int check_dimensions_map(int fd, t_coordinate *dimensions)
{
	int		sz;
	char	symbol[2];
	int		fix_columns;

	fix_columns = -1;
	sz = 1; //so that it will safely enter the loop
	while (sz != 0)
	{
		sz = read(fd, symbol, 1);
		symbol[sz] = '\0';
		if ((dimensions->row) - 1 == 0)
			fix_columns++;
		(dimensions->column)++;
		if (symbol[0] == '\n')
		{
			(dimensions->row)++;
			if (dimensions->column != fix_columns)
				return(0);
			dimensions->column = -1;
		}
	}
	if (dimensions->column != fix_columns || dimensions->row < 3)
		return (0);
	dimensions->column = fix_columns;
	return (1);
}

void	change_weights(t_matrices *matrices, t_coordinate dimensions, t_coordinate *curr_cell, t_coordinate *Es, t_coordinate *child_cell, int *coin_count, int *exit_exists)
{
	static int directions[5];
	int k;
	int temp_dist;

	initialize_directions(directions, matrices, *curr_cell);
	k = 0;
	while (k < 4)
	{
		if (directions[k] == 1)
		{
			temp_dist = 0;
			fix_coordinates(k, child_cell, *curr_cell);
			check_exit(child_cell->row, child_cell->column, Es->row, Es->column, exit_exists);
			if (matrices->pos_info[child_cell->row][child_cell->column].visited == 0 ||
				matrices->pos_info[child_cell->row][child_cell->column].cost != INT_MAX - 1)
			{
				k++;
				continue;
			}
			update_weights(matrices, curr_cell, child_cell, coin_count, &temp_dist);
		}
		k++;
	}
}

void fix_coordinates(int k, t_coordinate *child_cell, t_coordinate curr_cell)
{
	if (k == 0)
	{
		child_cell->row = curr_cell.row - 1;
		child_cell->column = curr_cell.column;
	}
	else if (k == 1)
	{
		child_cell->row = curr_cell.row + 1;
		child_cell->column = curr_cell.column;
	}
	else if (k == 2)
	{
		child_cell->row = curr_cell.row;
		child_cell->column = curr_cell.column + 1;
	}
	else if (k == 3)
	{
		child_cell->row = curr_cell.row;
		child_cell->column = curr_cell.column - 1;
	}
}

void update_weights(t_matrices *matrices, t_coordinate *curr_cell, t_coordinate *child_cell, int *coin_count, int *temp_dist)
{
	*temp_dist = matrices->pos_info[curr_cell->row][curr_cell->column].cost;
	if (matrices->char_info[child_cell->row][child_cell->column] == 'C')
	{
		*temp_dist += 1;
		*coin_count -= 1;
	}
	else if (matrices->char_info[child_cell->row][child_cell->column] == 'M')
		*temp_dist += 100;
	else
		*temp_dist = matrices->pos_info[curr_cell->row][curr_cell->column].cost + 10;
	if (*temp_dist < matrices->pos_info[child_cell->row][child_cell->column].cost)
		matrices->pos_info[child_cell->row][child_cell->column].cost = *temp_dist;
}

void	assign_cell(int k, t_coordinate *child_cell, t_coordinate *curr_cell)
{
	if (k == 0)
	{
		child_cell->row = curr_cell->row - 1;
		child_cell->column = curr_cell->column;
	}
	else if (k == 1)
	{
		child_cell->row = curr_cell->row + 1;
		child_cell->column = curr_cell->column;
	}
	else if (k == 2)
	{
		child_cell->row = curr_cell->row;
		child_cell->column = curr_cell->column + 1;
	}
	else if (k == 3)
	{
		child_cell->row = curr_cell->row;
		child_cell->column = curr_cell->column - 1;
	}
}