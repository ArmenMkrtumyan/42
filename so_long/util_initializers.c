#include "so_long.h"

void	letters_initializer(char *letters)
{
	letters[0] = '0';
	letters[1] = '0';
	letters[2] = '0';
	letters[3] = '0';
	letters[4] = '\0';
}

void	initialize_directions(int *directions, t_matrices *matrices, t_coordinate curr_cell)
{
	directions[0] = matrices->pos_info[curr_cell.row][curr_cell.column].N;
	directions[1] = matrices->pos_info[curr_cell.row][curr_cell.column].S;
	directions[2] = matrices->pos_info[curr_cell.row][curr_cell.column].E;
	directions[3] = matrices->pos_info[curr_cell.row][curr_cell.column].W;
	directions[4] = '\0';
}

void	direction_init(char **maze, t_pos **matrix, int row, int col)
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

void	initialize_NSEW(t_matrices *matrices, t_coordinate dimensions, t_coordinate E)
{
	t_coordinate	i_k;

	i_k.row = -1;
	while (++i_k.row < dimensions.row)
	{
		i_k.column = -1;
		while (++i_k.column < dimensions.column)
		{
			(matrices->pos_info[i_k.row][i_k.column]).N = 0;
			(matrices->pos_info[i_k.row][i_k.column]).S = 0;
			(matrices->pos_info[i_k.row][i_k.column]).E = 0;
			(matrices->pos_info[i_k.row][i_k.column]).W = 0;
			if (i_k.row == 0)
				matrices->pos_info[i_k.row][i_k.column].N = 0;
			else if (i_k.row == dimensions.row - 1)
				matrices->pos_info[i_k.row][i_k.column].S = 0;
			else if (i_k.column == 0)
				matrices->pos_info[i_k.row][i_k.column].W = 0;
			else if (i_k.column == dimensions.column - 1)
				matrices->pos_info[i_k.row][i_k.column].E = 0;
			else
				direction_init(matrices->char_info, matrices->pos_info, i_k.row, i_k.column);
		}
	}
}

void initialize_insides(t_inside *insides, t_matrices *matrices, t_coordinate dims, t_coordinate e)
{
	insides->matrices = *matrices;
	insides->dimensions = dims;
	insides->Es = e;
	insides->freed = 0;
}
