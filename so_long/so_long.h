#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

# define ESC 53
# define UP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2
# define UP_A 126
# define DOWN_A 125
# define LEFT_A 123
# define RIGHT_A 124

typedef struct s_placement
{
	int	n;
	int	s;
	int	e;
	int	w;
	int	cost;
	int	visited;
}	t_pos;

typedef struct s_list t_list;

typedef struct s_coordinates
{
	int		row;
	int		col;
	int		wall;
	t_list	*enemy_path;
}	t_xy;

typedef struct s_key_value
{
	t_xy	key;
	t_xy	value;
}			t_key_value;

typedef struct s_list
{
	t_key_value		content;
	struct s_list	*next;
}	t_list;

typedef struct s_matrices
{
	char		**char_info;
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
}			t_xys;

typedef struct s_inside_checked
{
	t_matrices		matrices;
	t_xy			dims;
	t_xy			e_xy;
	int				freed;
}					t_inside;

typedef struct s_constants
{
	int		coin_count;
	int		exit_exists;
	int		temp_dist;
}			t_const;

typedef struct s_mlx
{
	int		xy;
	int		is_dead;
	int		coin_count;
	int		enemy_count;
	int		enemy_perspective;
	void	*mlx_ptr;
	void	*mlx_win;
	void	*door_open;
	void 	*door_closed;
	void	*enemy;
	void	*coin;
	void 	*pacman_ate;
	void	*pacman_eating;
	void	*wall;
	void	*empty_space;
	void	*boom;
	char	**char_mat;
	t_xy	p_xy;
	t_xy	e_xy;
	t_xy	dims;
	t_xy	*enemies;
	t_xy	start_xy;
	t_pos	**pos_mat;
	t_list	*lst;
	t_xy	dest_xy;
	t_xy	last_xy;
	int		path_exists;
}			t_mlx;


// MAIN FUNCTIONS
//void			free_matrix(t_matrices *matrices, int row, t_inside *insides);
int		hit_enemy(t_mlx *mlx);
void	checkings(int fd1, int fd2, t_xy dims, t_mlx *mlx);
int		check_file_name(char *file_name);
void	ft_lstdellast(t_list **list);

// FILE CHECKER
int		check_letters(char letter, char *letters, t_xy *e, t_xy *i_k);
void	count_check(t_matrices *matrices, t_xy dims, t_inside *insides, t_mlx *mlx);
void	fill_matrices(t_matrices *matrices, t_xy *dims, t_fileRead *fd, t_mlx *mlx);
void	create_matrices(t_xy dim, t_matrices *matrix, t_mlx *mlx);
int		check_insides_map(int fd, t_xy dims, t_inside *insides, t_mlx *mlx);

// PATH CHECKER
void	check_path(t_xy dims, t_xy e, t_mlx *mlx, int enemy_num);

// CHECKER UTILS
int		check_dimensions_map(int fd, t_xy *dims);
int		check_visited(t_pos **matrix, t_xy dims);
void	check_exit(t_xys *coords, t_const *constants);
int		check_wall(int wall, t_const *constants, t_mlx *mlx);

// GETTER UTILS
int		get_fd(char *file);
int		get_coin_count(char **matrix, t_xy dims);
t_xy	get_min(t_pos **node, t_xy dims, char **matrix);
int		get_len(char *sentence);
int		ft_strncmp(char *str1, char *str2, int n);

// INITIALIZE UTILS
void	letters_init(char *letters);
void	init_directions(int *dir, t_mlx *mlx, t_xy curr_cell);
void	direction_init(char **maze, t_pos **matrix, int row, int col);
void	init_nsew(t_mlx *mlx, t_xy dims, t_xy e);
void	init_inside(t_inside *ins, t_matrices *matx, t_xy dims, t_xy e);
void	init_enemies(t_mlx *mlx);
void	init_mlx(t_mlx *mlx);


// UPDATER UTILS
void	change_weights(t_xys *coords, t_const *constants, t_mlx *mlx);
void	fix_coordinates(int k, t_xy *child_cell, t_xy curr_cell);
void	update_weights(t_xys *coords, t_const *constants, t_mlx *mlx);
void	assign_cell(int k, t_xy *child_cell, t_xy *curr_cell);
void	switch_places(int pos, t_mlx *mlx, int row, int col);
void	update_weights_after_move(t_mlx *mlx);
void	update_visited_and_costs(t_mlx *mlx, t_xy zero_position);
void	move_enemy(t_list *enemy_path, t_mlx *mlx, int enemy_num);

// PRINT/DRAW UTILS
void	on_exit(char *error_message);
void	redraw_map(int pos, t_mlx mlx, int p_row, int p_col);
void	redraw_map_enemy(int pos, t_mlx mlx, int e_row, int e_col);
void	draw_map(t_mlx *mlx);


// PACK UTILS
t_xys	pack_coorniates(t_xy dims, t_xy *curr, t_xy *child, t_xy e_xy);

// LIST UTILS
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);
void	ft_lstdelone(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(t_key_value content);

// MLX UTILS

int	pacman_animate(t_mlx *mlx);
int key_hook(int key_code, void *mlx_ptr);


#endif