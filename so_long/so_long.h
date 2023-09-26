#ifndef SO_LONG_H
# define SO_LONG_H

#include "mlx.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

typedef struct	s_placement
{
	int	N;
	int	S;
	int	E;
	int	W;
	int	cost;
	int	visited;
}	t_position;

typedef struct	s_coordinates
{
	int	row;
	int	column;
	int wall;
}	t_coordinate;

int count_checker(char **matrix, t_position **full_matrix, int row, int column);
void free_matrix(char **matrix, int row);
int check_path(t_position **full_matrix, char **matrix, t_coordinate dimensions, t_coordinate E_coordinate);
int check_dimensions_map(int fd, int *row, int *column);
int	check_insides_map(int fd, int row, int column);
int	check_visited(t_position **matrix, t_coordinate dimensions);
void	direction_init(char **maze, t_position **matrix, int row, int col);
t_coordinate get_minimum(t_position **node, t_coordinate dimensions, char **matrix);
int	get_coin_count(char **matrix, t_coordinate dimensions);
void	visited_loop(char **matrix, t_position **node, t_coordinate dimensions, t_coordinate E_coordinates);

#endif