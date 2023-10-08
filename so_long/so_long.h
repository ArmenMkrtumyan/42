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

typedef struct	s_matrices
{
	char **passed_matrix;;
	t_position **full_matrix;
}	t_matrices;

typedef struct	s_fileRead
{
	int		fd;
	int		sz;
	char	symbol[2];
}	t_fileRead;

typedef struct s_group_of_coordinates
{
	t_coordinate	current_cell;
	t_coordinate	child_cell;
	t_coordinate	E_coordinates;
}	t_struct_of_coordinates;

int				count_checker(t_matrices *matrices, t_coordinate dimensions);
int				free_matrix(t_matrices *matrices, int row);
int				assign_NSEW(t_matrices *matrices, t_coordinate dimensions, t_coordinate E_coordinate);
int				check_dimensions_map(int fd, t_coordinate *dimensions);
int				check_insides_map(int fd, t_coordinate dimensions);
int				check_visited(t_position **matrix, t_coordinate dimensions);
void			direction_init(char **maze, t_position **matrix, int row, int col);
t_coordinate	get_minimum(t_position **node, t_coordinate dimensions, char **matrix);
int				get_coin_count(char **matrix, t_coordinate dimensions);
void			check_path(t_matrices *matrices, t_coordinate dimensions, t_coordinate E_coordinates);

#endif