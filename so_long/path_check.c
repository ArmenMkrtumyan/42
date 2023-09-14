#include "so_long.h"

void	direction_init(char **maze, t_position **matrix, int row, int col)
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

// void	visited_loop(char **matrix, t_position **node, int row, int col)
// {
// 	int	i;
// 	int	k;
// 	int	exit_exist;

// 	i = -1;
// 	exit_exist = 0;
// 	while (++i < row)
// 	{
// 		k = -1;
// 		while (++k < col)
// 		{
// 			if (node[i][k].unvisited == 1)
// 				;
// 		}
// 	}
// 	if (exit_exist == 0 || )
// 		;// error
// }

int check_path(t_position **full_matrix, char **matrix, int row, int col)
{
	int i = -1;
	int k = -1;

	while (++i < row)
	{
		k = -1;
		while (++k < col)
		{

			(full_matrix[i][k]).N = 0;
			(full_matrix[i][k]).S = 0;
			(full_matrix[i][k]).E = 0;
			(full_matrix[i][k]).W = 0;
			if (i == 0)
				full_matrix[i][k].N = 0;
			else if (i == row - 1)
				full_matrix[i][k].S = 0;
			else if (k == 0)
				full_matrix[i][k].W = 0;
			else if (k == col - 1)
				full_matrix[i][k].E = 0;
			else
				direction_init(matrix, full_matrix, i, k);
		}
	}
	//visited_loop(matrix, full_matrix, row, col);
	i = -1;k = -1;

	while (++i < row)
	{
		k = -1;
		while (++k < col)
		{
			printf ("int this elem: '%c', indexs: %d %d\n", matrix[i][k], i, k);
			printf ("N: %d\n", full_matrix[i][k].N);
			printf ("S: %d\n", full_matrix[i][k].S);
			printf ("E: %d\n", full_matrix[i][k].E);
			printf ("W: %d\n", full_matrix[i][k].W);
			printf ("cost %d\n", full_matrix[i][k].cost);
			printf ("visited %d\n", full_matrix[i][k].visited);
		}
		printf ("\n");
	}
	return (1);
}
