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
	char		**passed_matrix;;
	t_position	**full_matrix;
	int			path_exists;
}	t_matrices;

typedef struct	s_fileRead
{
	int		fd;
	int		sz;
	char	symbol[2];
}	t_fileRead;

// typedef struct s_group_of_coordinates
// {
// 	t_coordinate	current_cell;
// 	t_coordinate	child_cell;
// 	t_coordinate	E_coordinates;
// }	t_struct_of_coordinates;

typedef struct	s_inside_checked
{
	t_matrices		matrices;
	t_coordinate	dimensions;
	t_coordinate	E_coordinates;
	int				freed;
}	t_insides;

// CHECKER UTILS
int				check_dimensions_map(int fd, t_coordinate *dimensions);
int				check_visited(t_position **matrix, t_coordinate dimensions);
void			check_exit(int child_row, int child_column, int E_row, int E_column, int *exit_exists);
int				check_wall(int wall, int exit_exists, int coin_count, t_matrices *matrices);

// GETTER UTILS
int				get_fd(char *file);
int				get_coin_count(char **matrix, t_coordinate dimensions);
t_coordinate	get_minimum(t_position **node, t_coordinate dimensions, char **matrix);

// INITIALIZE UTILS
void			letters_initializer(char *letters);
void			initialize_directions(int *directions, t_matrices *matrices, t_coordinate current_cell);
void			direction_init(char **maze, t_position **matrix, int row, int col);
void			initialize_NSEW(t_matrices *matrices, t_coordinate dimensions, t_coordinate E_coordinate);

// UPDATER UTILS
void			change_weights(t_matrices *matrices, t_coordinate dimensions, t_coordinate *current_cell, t_coordinate *E_coordinates, t_coordinate *child_cell, int *coin_count, int *exit_exists);
void			fix_coordinates(int k, t_coordinate *child_cell, t_coordinate current_cell);
void			update_weights(t_matrices *matrices, t_coordinate *current_cell, t_coordinate *child_cell, int *coin_count, int *temp_dist);
void			assign_cell(int k, t_coordinate *child_cell, t_coordinate *current_cell);

// MAIN FUNCTIONS
void			free_matrix(t_matrices *matrices, int row, t_insides *insides);

// FILE CHECKER
int				check_letters(char letter, char *letters, t_coordinate* E_coordinate, t_coordinate* i_k);
void			count_checker(t_matrices *matrices, t_coordinate dimensions, t_insides *insides);
void			fill_matrices(t_matrices *matrices, t_coordinate *dimensions, t_fileRead *file_read_info);
void			create_matrices(t_coordinate dimensions, t_matrices *matrices);
int				check_insides_map(int fd, t_coordinate dimensions, t_insides *insides);


// PATH CHECKER
int				check_path(t_matrices *matrices, t_coordinate dimensions, t_coordinate E_coordinates);

#endif