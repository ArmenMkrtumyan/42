#include "so_long.h"

t_xys	pack_coorniates(t_xy dims, t_xy *curr, t_xy *child, t_xy e_xy)
{
	t_xys	coords;

	coords.dims = dims;
	coords.child_cell = child;
	coords.curr_cell = curr;
	coords.e_xy = e_xy;
	return (coords);
}

void	move_enemy(t_list *enemy_path, t_mlx *mlx, int enemy_num)
{
	t_list	*prev;
	t_list	*last;
	int		pos;

	if (hit_enemy(mlx))
		on_exit("You lost!");
	ft_lstdellast(&enemy_path);
	last = ft_lstlast(enemy_path);
	if (mlx->enemies[enemy_num].row != last->content.value.row)
	{
		if (mlx->enemies[enemy_num].row > last->content.value.row)
			pos = UP;
		else
			pos = DOWN;
	}
	else if (mlx->enemies[enemy_num].col != last->content.value.col)
	{
		if (mlx->enemies[enemy_num].col > last->content.value.col)
			pos = LEFT;
		else
			pos = RIGHT;
	}
	mlx->enemies[enemy_num].row = last->content.value.row;
	mlx->enemies[enemy_num].col = last->content.value.col;
	redraw_map_enemy(pos, *mlx, mlx->enemies[enemy_num].row, mlx->enemies[enemy_num].col);
	ft_lstdellast(&enemy_path);
	if (hit_enemy(mlx))
		on_exit("You lost!");
}

void	switch_places(int pos, t_mlx *mlx, int row, int col)
{
	mlx->char_mat[row][col] = '0';
	if (pos == UP)
	{
		mlx->char_mat[row - 1][col] = 'P';
		mlx->p_xy.row = row - 1;
	}
	else if (pos == DOWN)
	{
		mlx->char_mat[row + 1][col] = 'P';
		mlx->p_xy.row = row + 1;
	}
	else if (pos == LEFT)
	{
		mlx->char_mat[row][col - 1] = 'P';
		mlx->p_xy.col = col - 1;
	}
	else if (pos == RIGHT)
	{
		mlx->char_mat[row][col + 1] = 'P';
		mlx->p_xy.col = col + 1;
	}
	mlx->coin_count = get_coin_count(mlx->char_mat, mlx->dims);
	if (mlx->coin_count == 0)
		mlx->door_closed = mlx->door_open;
	if (mlx->coin_count == 0 && mlx->p_xy.row == mlx->e_xy.row \
	&& mlx->p_xy.col == mlx->e_xy.col)
		on_exit("Good job!");
	redraw_map(pos, *mlx, mlx->p_xy.row, mlx->p_xy.col);
}

void	assign_cell(int k, t_xy *child_cell, t_xy *curr_cell)
{
	if (k == 0)
	{
		child_cell->row = curr_cell->row - 1;
		child_cell->col = curr_cell->col;
	}
	else if (k == 1)
	{
		child_cell->row = curr_cell->row + 1;
		child_cell->col = curr_cell->col;
	}
	else if (k == 2)
	{
		child_cell->row = curr_cell->row;
		child_cell->col = curr_cell->col + 1;
	}
	else if (k == 3)
	{
		child_cell->row = curr_cell->row;
		child_cell->col = curr_cell->col - 1;
	}
}

void	fix_coordinates(int k, t_xy *child_cell, t_xy curr_cell)
{
	if (k == 0)
	{
		child_cell->row = curr_cell.row - 1;
		child_cell->col = curr_cell.col;
	}
	else if (k == 1)
	{
		child_cell->row = curr_cell.row + 1;
		child_cell->col = curr_cell.col;
	}
	else if (k == 2)
	{
		child_cell->row = curr_cell.row;
		child_cell->col = curr_cell.col + 1;
	}
	else if (k == 3)
	{
		child_cell->row = curr_cell.row;
		child_cell->col = curr_cell.col - 1;
	}
}
