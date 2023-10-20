#include "so_long.h"

int	check_dimensions_map(int fd, t_xy *dims)
{
	int		sz;
	char	symbol[2];
	int		fix_columns;

	fix_columns = -1;
	sz = 1;
	while (sz != 0)
	{
		sz = read(fd, symbol, 1);
		symbol[sz] = '\0';
		if ((dims->row) - 1 == 0)
			fix_columns++;
		(dims->column)++;
		if (symbol[0] == '\n')
		{
			(dims->row)++;
			if (dims->column != fix_columns)
				return (0);
			dims->column = -1;
		}
	}
	if (dims->column != fix_columns || dims->row < 3)
		return (0);
	dims->column = fix_columns;
	return (1);
}

void	change_weights(t_matrices *matrices, t_xys *coords, t_const *constants)
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
			update_weights(matrices, coords, constants);
		}
		k++;
	}
}

void	fix_coordinates(int k, t_xy *child_cell, t_xy curr_cell)
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

void	update_weights(t_matrices *matrices, t_xys *coords, t_const *constants)
{
	t_xy	child;
	t_xy	curr;

	curr.row = coords->curr_cell->row;
	curr.column = coords->curr_cell->column;
	child.row = coords->child_cell->row;
	child.column = coords->child_cell->column;
	constants->temp_dist = matrices->pos_info[curr.row][curr.column].cost;
	if (matrices->char_info[child.row][child.column] == 'C')
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
		matrices->pos_info[child.row][child.column].cost = constants->temp_dist;
}

void	assign_cell(int k, t_xy *child_cell, t_xy *curr_cell)
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
