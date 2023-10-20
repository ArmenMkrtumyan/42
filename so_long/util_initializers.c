#include "so_long.h"

void	letters_init(char *letters)
{
	letters[0] = '0';
	letters[1] = '0';
	letters[2] = '0';
	letters[3] = '0';
	letters[4] = '\0';
}

void	init_directions(int *directions, t_matrices *matrices, t_xy curr_cell)
{
	directions[0] = matrices->pos_info[curr_cell.row][curr_cell.column].n;
	directions[1] = matrices->pos_info[curr_cell.row][curr_cell.column].s;
	directions[2] = matrices->pos_info[curr_cell.row][curr_cell.column].e;
	directions[3] = matrices->pos_info[curr_cell.row][curr_cell.column].w;
	directions[4] = '\0';
}

void	direction_init(char **maze, t_pos **matrix, int row, int col)
{
	if (maze[row + 1][col] != '1')
		(matrix[row][col]).s = 1;
	if (maze[row - 1][col] != '1')
		(matrix[row][col]).n = 1;
	if (maze[row][col + 1] != '1')
		(matrix[row][col]).e = 1;
	if (maze[row][col - 1] != '1')
		(matrix[row][col]).w = 1;
}

void	init_NSEW(t_matrices *matrices, t_xy dims, t_xy e)
{
	t_xy	i_k;

	i_k.row = -1;
	while (++i_k.row < dims.row)
	{
		i_k.column = -1;
		while (++i_k.column < dims.column)
		{
			(matrices->pos_info[i_k.row][i_k.column]).n = 0;
			(matrices->pos_info[i_k.row][i_k.column]).s = 0;
			(matrices->pos_info[i_k.row][i_k.column]).e = 0;
			(matrices->pos_info[i_k.row][i_k.column]).w = 0;
			if (i_k.row == 0)
				matrices->pos_info[i_k.row][i_k.column].n = 0;
			else if (i_k.row == dims.row - 1)
				matrices->pos_info[i_k.row][i_k.column].s = 0;
			else if (i_k.column == 0)
				matrices->pos_info[i_k.row][i_k.column].w = 0;
			else if (i_k.column == dims.column - 1)
				matrices->pos_info[i_k.row][i_k.column].e = 0;
			else
				direction_init(matrices->char_info, matrices->pos_info, i_k.row, i_k.column);
		}
	}
}

void init_insides(t_inside *insides, t_matrices *matrices, t_xy dims, t_xy e)
{
	insides->matrices = *matrices;
	insides->dims = dims;
	insides->e_xy = e;
	insides->freed = 0;
}
