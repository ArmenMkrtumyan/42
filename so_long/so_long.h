#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_placement
{
	int	n;
	int	s;
	int	e;
	int	w;
	int	cost;
	int	visited;
}	t_pos;

typedef struct s_coordinates
{
	int	row;
	int	column;
	int wall;
}	t_xy;

typedef struct s_matrices
{
	char		**char_info;;
	t_pos		**pos_info;
	int			path_exists;
}	t_matrices;

typedef struct s_fileRead
{
	int		fd;
	int		sz;
	char	symbol[2];
}	t_fileRead;

typedef struct s_group_of_coordinates
{
	t_xy	dims;
	t_xy	*curr_cell;
	t_xy	*child_cell;
	t_xy	e_xy;
}			t_coords;

typedef struct s_inside_checked
{
	t_matrices		matrices;
	t_xy			dims;
	t_xy			e_xy;
	int				freed;
}	t_inside;

// MAIN FUNCTIONS
//void			free_matrix(t_matrices *matrices, int row, t_inside *insides);
void		checkings(int fd1, int fd2, t_xy dims);
int			check_file_name(char *file_name);

// FILE CHECKER
int			check_letters(char letter, char *letters, t_xy* e, t_xy* i_k);
void		count_check(t_matrices *matrices, t_xy dims, t_inside *insides);
void		fill_matrices(t_matrices *matrices, t_xy *dims, t_fileRead *file_read_info);
void		create_matrices(t_xy dims, t_matrices *matrices);
int			check_insides_map(int fd, t_xy dims, t_inside *insides);

// PATH CHECKER
int			check_path(t_matrices *matrices, t_xy dims, t_xy e_xy);

// CHECKER UTILS
int			check_dimensions_map(int fd, t_xy *dims);
int			check_visited(t_pos **matrix, t_xy dims);
void		check_exit(t_coords *coords, int *exit_exists);
int			check_wall(int wall, int exit_exists, int coin_count, t_matrices *matrices);

// GETTER UTILS
int			get_fd(char *file);
int			get_coin_count(char **matrix, t_xy dims);
t_xy		get_min(t_pos **node, t_xy dims, char **matrix);
int			get_len(char *sentence);
int 		ft_strncmp(char *str1, char *str2, int n);

// INITIALIZE UTILS
void		letters_init(char *letters);
void		init_directions(int *directions, t_matrices *matrices, t_xy curr_cell);
void		direction_init(char **maze, t_pos **matrix, int row, int col);
void		init_NSEW(t_matrices *matrices, t_xy dims, t_xy e);
void		init_insides(t_inside *insides, t_matrices *matrices, t_xy dims, t_xy e);

// UPDATER UTILS
void		change_weights(t_matrices *matrices, t_coords *coords, int *coin_count, int *exit_exists);
void		fix_coordinates(int k, t_xy *child_cell, t_xy curr_cell);
void		update_weights(t_matrices *matrices, t_coords *coords, int *coin_count, int *temp_dist);
void		assign_cell(int k, t_xy *child_cell, t_xy *curr_cell);

// PRINT UTILS

void			on_exit(char *error_message);

// PACK UTILS

t_coords	pack_coorniates(t_xy dims, t_xy *curr, t_xy *child, t_xy e_xy);

#endif