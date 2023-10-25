#include "so_long.h"

void	letters_init(char *letters)
{
	letters[0] = '0';
	letters[1] = '0';
	letters[2] = '0';
	letters[3] = '0';
	letters[4] = '\0';
}

void	init_directions(int *dir, t_mlx *mlx, t_xy curr_cell)
{
	dir[0] = mlx->pos_mat[curr_cell.row][curr_cell.col].n;
	dir[1] = mlx->pos_mat[curr_cell.row][curr_cell.col].s;
	dir[2] = mlx->pos_mat[curr_cell.row][curr_cell.col].e;
	dir[3] = mlx->pos_mat[curr_cell.row][curr_cell.col].w;
	dir[4] = '\0';
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

void	init_nsew(t_mlx *mlx, t_xy dims, t_xy e)
{
	t_xy	i_k;

	(void)e;
	i_k.row = -1;
	while (++i_k.row < dims.row)
	{
		i_k.col = -1;
		while (++i_k.col < dims.col)
		{
			(mlx->pos_mat[i_k.row][i_k.col]).n = 0;
			(mlx->pos_mat[i_k.row][i_k.col]).s = 0;
			(mlx->pos_mat[i_k.row][i_k.col]).e = 0;
			(mlx->pos_mat[i_k.row][i_k.col]).w = 0;
			if (i_k.row == 0)
				mlx->pos_mat[i_k.row][i_k.col].n = 0;
			else if (i_k.row == dims.row - 1)
				mlx->pos_mat[i_k.row][i_k.col].s = 0;
			else if (i_k.col == 0)
				mlx->pos_mat[i_k.row][i_k.col].w = 0;
			else if (i_k.col == dims.col - 1)
				mlx->pos_mat[i_k.row][i_k.col].e = 0;
			else
				direction_init(mlx->char_mat, mlx->pos_mat, \
				i_k.row, i_k.col);
		}
	}
}

void	init_inside(t_inside *insides, t_mlx *mlx, t_xy dims, t_xy e)
{
	mlx->matrices.pos_info = mlx->pos_mat;
	mlx->matrices.char_info = mlx->char_mat;
	mlx->matrices.path_exists = mlx->path_exists;
	insides->matrices = mlx->matrices;
	insides->dims = dims;
	insides->e_xy = e;
	insides->freed = 0;
}

void	init_enemies(t_mlx *mlx)
{
	t_xy	*enemies;
	int		i;
	int		k;
	int		count;

	count = 0;
	i = -1;
	enemies = malloc(sizeof(t_xy) * mlx->enemy_count);
	while (++i < mlx->dims.row)
	{
		k = -1;
		while (++k < mlx->dims.col)
		{
			if (mlx->char_mat[i][k] == 'M')
			{
				enemies[count].row = i;
				enemies[count].col = k;
				enemies[count].enemy_path = NULL;
				count ++;
			}
		}
	}
	mlx->enemies = enemies;
}

void	init_mlx(t_mlx *mlx)
{
	mlx->is_dead = 0;
	mlx->lst = NULL;
	mlx->mlx_ptr = mlx_init();
	mlx->door_open = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"pictures/open_door.xpm", &mlx->xy, &mlx->xy);
	mlx->door_closed = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"pictures/closed_door.xpm", &mlx->xy, &mlx->xy);
	mlx->enemy = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"pictures/enemy.xpm", &mlx->xy, &mlx->xy);
	mlx->coin = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"pictures/coin.xpm", &mlx->xy, &mlx->xy);
	mlx->pacman_ate = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"pictures/pacman_ate.xpm", &mlx->xy, &mlx->xy);
	mlx->pacman_eating = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"pictures/pacman_eating.xpm", &mlx->xy, &mlx->xy);
	mlx->wall = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"pictures/wall.xpm", &mlx->xy, &mlx->xy);
	mlx->empty_space = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"pictures/empty_space.xpm", &mlx->xy, &mlx->xy);
	mlx->boom = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"pictures/boom.xpm", &mlx->xy, &mlx->xy);
	mlx->mlx_win = mlx_new_window(mlx->mlx_ptr, mlx->dims.col * mlx->xy,
			mlx->dims.row * mlx->xy, "Armenian Pacman");
	mlx->door_cur = mlx->door_closed;
}
