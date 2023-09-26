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

int		check_visited(t_position **matrix, t_coordinate dimensions)
{
	int	i;
	int	k;

	i = -1;
	while (++i < dimensions.row)
	{
		k = -1;
		while (++k < dimensions.column)
		{
			if(matrix[i][k].visited == 1)
				return (1);
		}
	}
	return (0);
}

t_coordinate get_minimum(t_position **node, t_coordinate dimensions, char **matrix)
{
	int				i;
	int				k;
	int				min;
	t_coordinate	min_coordinates;

	min = INT_MAX;
	i = 0;
	min_coordinates.wall = 0;
	i = 0;
	while (i < dimensions.row)
	{
		k = 0;
		while (k < dimensions.column)
		{
			if (node[i][k].visited == 1 && node[i][k].cost < min)
			{
				min = node[i][k].cost;
				min_coordinates.row = i;
				min_coordinates.column = k;
			}
			k++;
		}
		i++;
	}
	//printf ("minimum is %d when indexs are %d %d\n", min, min_coordinates.row, min_coordinates.column);
	// if (matrix[min_coordinates.row][min_coordinates.column].cost == INT_MAX - 1)
	// {
	// 	printf("\nFOUND A WALL in coor %d %d\n", min_coordinates.row, min_coordinates.column);
	// 	min_coordinates.wall = 1;
	// }
	if (matrix[min_coordinates.row][min_coordinates.column] == '1')
		min_coordinates.wall = 1;
	return (min_coordinates);
}

int	get_coin_count(char **matrix, t_coordinate dimensions)
{
	int	i;
	int	k;
	int	coin_count;

	i = -1;
	coin_count = 0;
	while (++i < dimensions.row)
	{
		k = -1;
		while (++k < dimensions.column)
		{
			if(matrix[i][k] == 'C')
				coin_count ++;
		}
	}
	return (coin_count);
}

void	visited_loop(char **matrix, t_position **node, t_coordinate dimensions, t_coordinate E_coordinates)
{
	int	i;
	int	k;
	t_coordinate current_cell;
	t_coordinate	child_cell;
	int	directions[5];
	int temp_dist;
	int coin_count;
	int exit_exists;
	// node[E_coordinates.row][E_coordinates.column].N = 0;
	// node[E_coordinates.row][E_coordinates.column].S = 0;
	// node[E_coordinates.row][E_coordinates.column].E = 0;
	// node[E_coordinates.row][E_coordinates.column].W = 0;

//EXIT INIT

	// printf ("exit row col: %d %d\n", E_coordinates.row, E_coordinates.column);
	// node[E_coordinates.row - 1][E_coordinates.column].S = 0;
	// printf ("poxum enq %d %d i N coord\n", E_coordinates.row - 1, E_coordinates.column);
	// node[E_coordinates.row + 1][E_coordinates.column].N = 0;
	// node[E_coordinates.row][E_coordinates.column + 1].W = 0;
	// node[E_coordinates.row][E_coordinates.column - 1].E = 0;


	// i = -1;
	// int i1 = -1, k1;
	// while (++i1 < dimensions.row)
	// {
	// 	k1 = -1;
	// 	while (++k1 < dimensions.column)
	// 	{
	// 		printf ("node %d %d: N: %d, S: %d, E: %d, W: %d\n", i1, k1, \
	// 		node[i1][k1].N, \
	// 		node[i1][k1].S, \
	// 		node[i1][k1].E, \
	// 		node[i1][k1].W);
	// 	}
	// }
	// printf ("\nCOIN COUNT: %d\n", coin_count);

	exit_exists = 0;
	coin_count = get_coin_count(matrix, dimensions);
	directions[4] = '\0';
	i = 0;
	while (check_visited(node, dimensions))
	{
		current_cell = get_minimum(node, dimensions, matrix);
		node[current_cell.row][current_cell.column].visited = 0;
		if (current_cell.wall)
			continue ;
		if (current_cell.row == E_coordinates.row && current_cell.column == E_coordinates.column && coin_count==0)
		{
			printf("\n\nEXIT EXISTS!!!!\n\n");
			exit_exists = 1;
			break ;
		}
		directions[0] = node[current_cell.row][current_cell.column].N;
		directions[1] = node[current_cell.row][current_cell.column].S;
		directions[2] = node[current_cell.row][current_cell.column].E;
		directions[3] = node[current_cell.row][current_cell.column].W;
		k = 0;
		//printf ("indexes: %d %d, N: %d, S: %d, E: %d, W: %d\n", current_cell.row, current_cell.column, directions[0], directions[1], directions[2], directions[3]);
		while (k < 4)
		{
			// printf ()
			if (directions[k] == 1)
			{
				temp_dist = 0;
				if (k == 0)
				{
					child_cell.row = current_cell.row - 1;
					child_cell.column = current_cell.column;
				}
				else if (k == 1)
				{
					child_cell.row = current_cell.row + 1;
					child_cell.column = current_cell.column;
				}
				else if (k == 2)
				{
					child_cell.row = current_cell.row;
					child_cell.column = current_cell.column + 1;
				}
				else if (k == 3)
				{
					child_cell.row = current_cell.row;
					child_cell.column = current_cell.column - 1;
				}
				if (coin_count != 0 && \
				child_cell.row == E_coordinates.row && child_cell.column == E_coordinates.column)
				{
					k++;
					continue ;
				}
				if (node[child_cell.row][child_cell.column].visited == 0 || \
				node[child_cell.row][child_cell.column].cost != INT_MAX -1
				)
				{
					k++;
					continue ;
				}
				// else
				// 	node[child_cell.row][child_cell.column].visited = 0;
				temp_dist = node[current_cell.row][current_cell.column].cost;

				if(matrix[child_cell.row][child_cell.column] == 'C')
				{
					temp_dist += 100;
					coin_count -= 1;
				}
				else
					temp_dist = node[current_cell.row][current_cell.column].cost + 1000;
				if (temp_dist < node[child_cell.row][child_cell.column].cost)
					node[child_cell.row][child_cell.column].cost = temp_dist;

			}
			k++;
		}
	}
	int i2 = -1, k2;
	printf ("\n");
	while (++i2 < dimensions.row)
	{
		k2 = -1;
		while (++k2 < dimensions.column)
			printf("%d", node[i2][k2].visited);
		printf ("\n");
	}
	printf("\n\n\nEXIT EXIST?: %d\nNumber of remaining coins to collect: %d\n\n",\
	 exit_exists, coin_count);
}

int check_path(t_position **full_matrix, char **matrix, t_coordinate dimensions, t_coordinate E_coordinate)
{
	int i = -1;
	int k = -1;

	while (++i < dimensions.row)
	{
		k = -1;
		while (++k < dimensions.column)
		{

			(full_matrix[i][k]).N = 0;
			(full_matrix[i][k]).S = 0;
			(full_matrix[i][k]).E = 0;
			(full_matrix[i][k]).W = 0;
			if (i == 0)
				full_matrix[i][k].N = 0;
			else if (i == dimensions.row - 1)
				full_matrix[i][k].S = 0;
			else if (k == 0)
				full_matrix[i][k].W = 0;
			else if (k == dimensions.column - 1)
				full_matrix[i][k].E = 0;
			else
				direction_init(matrix, full_matrix, i, k);
		}
	}
	visited_loop(matrix, full_matrix, dimensions, E_coordinate);
	// i = -1;k = -1;

	// while (++i < dimensions.row)
	// {
	// 	k = -1;
	// 	while (++k < dimensions.column)
	// 	{
	// 		printf ("int this elem: '%c', indexs: %d %d\n", matrix[i][k], i, k);
	// 		printf ("N: %d\n", full_matrix[i][k].N);
	// 		printf ("S: %d\n", full_matrix[i][k].S);
	// 		printf ("E: %d\n", full_matrix[i][k].E);
	// 		printf ("W: %d\n", full_matrix[i][k].W);
	// 		printf ("cost %d\n", full_matrix[i][k].cost);
	// 		printf ("visited %d\n", full_matrix[i][k].visited);
	// 	}
	// 	printf ("\n");
	// }
	return (1);
}
