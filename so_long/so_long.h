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

int count_checker(char **matrix, t_position **full_matrix, int row, int column);
void free_matrix(char **matrix, int row);
int check_path(t_position **full_matrix, char **matrix, int row, int col);
int check_dimensions_map(int fd, int *row, int *column);
int	check_insides_map(int fd, int row, int column);
int		check_visited(t_position **matrix, int row, int col);

#endif