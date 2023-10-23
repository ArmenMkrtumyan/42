/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:18:57 by amkrtumy          #+#    #+#             */
/*   Updated: 2023/10/06 16:19:02 by amkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	free_matrix(t_matrices *matrices, int row, t_inside *insides)
// {
// 	int	i;

// 	i = 0;
// 	while (i < row)
// 		free(matrices->char_info[i++]);
// 	free(matrices->char_info);
// 	i = 0;
// 	while (i < row)
// 		free(matrices->pos_info[i++]);
// 	free(matrices->pos_info);
// 	insides->freed = 1;
// }

void	redraw_map(int pos, t_mlx mlx, int p_row, int p_column)
{
	if (!(p_row == mlx.e_xy.row && p_column == mlx.e_xy.column))
	{
		mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, mlx.empty_space, mlx.xy * mlx.e_xy.column, mlx.xy * mlx.e_xy.row);
		mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, mlx.door_closed, mlx.xy * mlx.e_xy.column, mlx.xy * mlx.e_xy.row);
		mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, mlx.empty_space, mlx.xy * p_column, mlx.xy * p_row);
		mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, mlx.pacman_eating, mlx.xy * p_column, mlx.xy * p_row);
	}
	else
		mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, mlx.pacman_eating, mlx.xy * p_column, mlx.xy * p_row);
	if (pos == UP && !(p_column == mlx.e_xy.column && p_row + 1 == mlx.e_xy.row))
		mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, mlx.empty_space, p_column * mlx.xy, (p_row + 1) * mlx.xy);
	else if (pos == DOWN && !(p_column == mlx.e_xy.column && p_row -1 == mlx.e_xy.row))
		mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, mlx.empty_space, p_column * mlx.xy, (p_row - 1) * mlx.xy);
	else if (pos == LEFT && !(p_column + 1 == mlx.e_xy.column && p_row == mlx.e_xy.row))
		mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, mlx.empty_space, (p_column + 1) * mlx.xy, p_row * mlx.xy);
	else if (pos == RIGHT && !(p_column - 1 == mlx.e_xy.column && p_row == mlx.e_xy.row))
		mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, mlx.empty_space, (p_column - 1) * mlx.xy, p_row * mlx.xy);
}

void	update_visited_and_costs(t_mlx *mlx, t_xy zero_position)
{
	int	k2;
	int	i2;
	i2 = -1;
	while (++i2 < mlx->dims.row)
	{
		k2 = -1;
		while (++k2 < mlx->dims.column)
		{
			mlx->pos_mat[i2][k2].cost = INT_MAX - 1;
			mlx->pos_mat[i2][k2].visited = 1;
		}
	}
	mlx->pos_mat[zero_position.row][zero_position.column].cost = 0;
}

// void	move_enemy(t_mlx *mlx, t_xy enemy_pos)
// {
// 	int	costs[4];
// 	int	i;
// 	int	min;

// 	costs[0] = mlx->pos_mat[enemy_pos.row - 1][enemy_pos.column].cost;
// 	costs[1] = mlx->pos_mat[enemy_pos.row + 1][enemy_pos.column].cost;
// 	costs[2] = mlx->pos_mat[enemy_pos.row][enemy_pos.column + 1].cost;
// 	costs[3] = mlx->pos_mat[enemy_pos.row][enemy_pos.column - 1].cost;
// 	i = 0;
// 	min = costs[0];
// 	while (i < 4)
// 	{
// 		if (costs[i] < min)
// 			min = costs[i];
// 		i++;
// 	}
// 	i = 0;
// 	while (i < 4)
// 	{
// 		if ( [enemy_pos.column] != '1')
// 			break ;
// 		i++;
// 	}

// }

void	update_weights_after_move(t_mlx *mlx)
{
	t_matrices	matrix;

	// printf("\n\nEnemy 0: %d %d\n", mlx->enemies[0].row, mlx->enemies[0].column);
	mlx->enemy_perspective = 0;
	matrix.char_info = mlx->char_mat;
	matrix.pos_info = mlx->pos_mat;
	printf("\n\nWeights from Players perspective\n\n");
	update_visited_and_costs(mlx, mlx->p_xy);
	check_path(&matrix, mlx->dims, mlx->e_xy, mlx);
	printf("\n\nWeights from Enemies perspective\n\n");
	mlx->enemy_perspective = 1;
	update_visited_and_costs(mlx, mlx->enemies[0] );
	check_path(&matrix, mlx->dims, mlx->e_xy, mlx);
	//move_enemy(mlx, mlx->enemies[0]);
	// int k2, i2;
	// i2 = -1;
	// while (++i2 < mlx->dims.row)
	// {
	// 	k2 = -1;
	// 	while (++k2 < mlx->dims.column)
	// 	{
	// 		printf("    ");
	// 		if (mlx->pos_mat[i2][k2].cost == INT_MAX - 1)
	// 			printf("X");
	// 		else
	// 			printf("%d", mlx->pos_mat[i2][k2].cost);
	// 	}
	// 	printf("\n");
	// }
}

void	switch_places(int pos, t_mlx *mlx, int row, int column)
{
	if (pos == UP)
	{
		mlx->char_mat[row][column] = '0';
		mlx->char_mat[row - 1][column] = 'P';
		mlx->p_xy.row = row - 1;
	}
	else if (pos == DOWN)
	{
		mlx->char_mat[row][column] = '0';
		mlx->char_mat[row + 1][column] = 'P';
		mlx->p_xy.row = row + 1;
	}
	else if (pos == LEFT)
	{
		mlx->char_mat[row][column] = '0';
		mlx->char_mat[row][column - 1] = 'P';
		mlx->p_xy.column = column - 1;
	}
	else if (pos == RIGHT)
	{
		mlx->char_mat[row][column] = '0';
		mlx->char_mat[row][column + 1] = 'P';
		mlx->p_xy.column = column + 1;
	}
	mlx->coin_count = get_coin_count(mlx->char_mat, mlx->dims);
	//printf("Coin count is: %d\n", mlx->coin_count);
	if (mlx->coin_count == 0)
		mlx->door_closed = mlx->door_open;
	if (mlx->coin_count == 0 && mlx->p_xy.row == mlx->e_xy.row && mlx->p_xy.column == mlx->e_xy.column)
		on_exit("Good job!");
	redraw_map(pos, *mlx, mlx->p_xy.row, mlx->p_xy.column);
	update_weights_after_move(mlx);
}
int exit_program(void *mlx_ptr)
{
	on_exit("\nClosed the game\n");
	return (1);
}
int key_hook(int key_code, void *mlx_ptr)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)mlx_ptr;
	if ((key_code == UP || key_code == UP_A) && \
	mlx->char_mat[mlx->p_xy.row - 1][mlx->p_xy.column] != '1')
		switch_places(UP, mlx, mlx->p_xy.row, mlx->p_xy.column);
	else if ((key_code == DOWN || key_code == DOWN_A) && \
	mlx->char_mat[mlx->p_xy.row + 1][mlx->p_xy.column] != '1')
		switch_places(DOWN, mlx, mlx->p_xy.row, mlx->p_xy.column);
	else if ((key_code == LEFT || key_code == LEFT_A) && \
	mlx->char_mat[mlx->p_xy.row][mlx->p_xy.column - 1] != '1')
		switch_places(LEFT, mlx, mlx->p_xy.row, mlx->p_xy.column);
	else if ((key_code == RIGHT || key_code == RIGHT_A) &&\
	mlx->char_mat[mlx->p_xy.row][mlx->p_xy.column + 1] != '1')
		switch_places(RIGHT, mlx, mlx->p_xy.row, mlx->p_xy.column);
	else if (key_code == ESC)
	{
		on_exit("\nClosing the game");
	}

	return (1);
}

void	checkings(int fd1, int fd2, t_xy dims, t_mlx *mlx)
{
	t_inside		insides;

	if (check_dimensions_map(fd1, &dims))
	{
		printf("\n\nCORRECT DIMENSIONS(%d, %d),CHECKING THE INSIDE...\n\n", \
		dims.row, dims.column);
		if (check_insides_map(fd2, dims, &insides, mlx) == 0)
		{
			mlx->enemy_perspective = 0;
			printf("\n\nCORRECT MAP INSIDES, CHECKING PATHS...");
			check_path(&insides.matrices, insides.dims, \
			insides.e_xy, mlx);
			if (insides.matrices.path_exists == 1)
				printf("\n\nCORRECT PATHS...Launching the game\n\n");
			else
				on_exit("Issue with paths!");
		}
	}
	else
		on_exit("\n\nWRONG DIMENSIONS\n\n");
}

int	check_file_name(char *file_name)
{
	int	len;

	len = get_len(file_name);
	while (file_name[len] != '.')
		len--;
	if (len == 0)
	{
		printf("Error\nInput correct map name!\n");
		return (0);
	}
	if (ft_strncmp(&file_name[len], ".ber", 4) != 0)
	{
		printf("Error\nInput correct map name!\n");
		return (0);
	}
	return (1);
}

int	pacman_animate(t_mlx *mlx)
{
	static unsigned int	timer = 0;
	char				*texture;

	if (timer %  2000 == 0 || timer % 3000 == 0)
	{
		if(timer %  2000 == 0)
		{
			texture = mlx->pacman_eating;
		}
		else if (timer % 3000 == 0)
		{
			texture = mlx->pacman_ate;
		}
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, mlx->empty_space, \
		mlx->xy * mlx->p_xy.column, mlx->xy * mlx->p_xy.row);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, texture, \
		mlx->xy * mlx->p_xy.column, mlx->xy * mlx->p_xy.row);
	}
	timer ++;
	return (1);
}


void	init_enemies(t_mlx *mlx)
{
	t_xy	*enemies;
	int		i;
	int		k;
	int		count;

	count = 0;
	i = -1;
	printf("\nReceived enemy count is: %d\n", mlx->enemy_count);
	enemies = malloc(sizeof(t_xy) * mlx->enemy_count);
	while (++i < mlx->dims.row)
	{
		k = -1;
		while (++k < mlx->dims.column)
		{
			if (mlx->char_mat[i][k] == 'M')
			{
				enemies[count].row = i;
				enemies[count].column = k;
				count ++;
			}
		}
	}
	mlx->enemies = enemies;
	printf("Printing the coordinates of enemies");
	i = -1;
	while (++i < mlx->enemy_count)
		printf("\nEnemy %d: %d %d\n", i, mlx->enemies[i].row, mlx->enemies[i].column);

}

int	main(int argc, char	*argv[])
{
	int			fd1;
	int			fd2;
	t_xy		dims;
	t_mlx		mlx;

	mlx.lst = NULL;
	if (argc != 2)
	{
		printf("Error\nInput only map name!\n");
		return (0);
	}
	if (check_file_name(argv[1]) == 0)
		return (0);
	dims.row = 1;
	dims.column = -1;
	fd1 = get_fd(argv[1]);

	fd2 = get_fd(argv[1]);
	checkings(fd1, fd2, dims, &mlx);

	printf("\n\nPlayer position: %d %d\n", mlx.p_xy.row, mlx.p_xy.column);
	printf("Exit position: %d %d\n", mlx.e_xy.row, mlx.e_xy.column);

	init_enemies(&mlx);
	mlx.mlx_ptr = mlx_init();
	mlx.door_open = mlx_xpm_file_to_image(mlx.mlx_ptr, "open_door.xpm", &mlx.xy, &mlx.xy);
	mlx.door_closed = mlx_xpm_file_to_image(mlx.mlx_ptr, "closed_door.xpm", &mlx.xy, &mlx.xy);
	mlx.enemy = mlx_xpm_file_to_image(mlx.mlx_ptr, "enemy.xpm", &mlx.xy, &mlx.xy);
	mlx.coin = mlx_xpm_file_to_image(mlx.mlx_ptr, "coin.xpm", &mlx.xy, &mlx.xy);
	mlx.pacman_ate = mlx_xpm_file_to_image(mlx.mlx_ptr, "pacman_ate.xpm", &mlx.xy, &mlx.xy);
	mlx.pacman_eating = mlx_xpm_file_to_image(mlx.mlx_ptr, "pacman_eating.xpm", &mlx.xy, &mlx.xy);
	mlx.wall = mlx_xpm_file_to_image(mlx.mlx_ptr, "wall.xpm", &mlx.xy, &mlx.xy);
	mlx.empty_space = mlx_xpm_file_to_image(mlx.mlx_ptr, "empty_space.xpm", &mlx.xy, &mlx.xy);
	mlx.mlx_win = mlx_new_window(mlx.mlx_ptr, mlx.dims.column * mlx.xy, mlx.dims.row * mlx.xy, "Pacman");


	int k;
	int i;

	k = 0;
	i = 0;
	while(mlx.char_mat[k])
	{
		i = 0;
		while(mlx.char_mat[k][i])
		{
			if (mlx.char_mat[k][i] == '0')
				mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, mlx.empty_space,  i*mlx.xy, k*mlx.xy);
			else if (mlx.char_mat[k][i] == '1')
				mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, mlx.wall, i*mlx.xy, k*mlx.xy);
			else if (mlx.char_mat[k][i] == 'C')
				mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, mlx.coin, i*mlx.xy, k*mlx.xy);
			else if (mlx.char_mat[k][i] == 'M')
				mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, mlx.enemy, i*mlx.xy, k*mlx.xy);
			else if (mlx.char_mat[k][i] == 'P')
				mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, mlx.pacman_eating, i*mlx.xy, k*mlx.xy);
			else if (mlx.char_mat[k][i] == 'E')
				mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, mlx.door_closed, i*mlx.xy, k*mlx.xy);
			printf("%c", mlx.char_mat[k][i]);
			i++;
		}
		printf("\n");
		k++;
	}
	printf("Printing the coordinates of enemies");
	i = -1;
	printf("\n\nEnemy 0 %d %d\n\n", mlx.enemies[0].row, mlx.enemies[0].column);
	while (++i < mlx.enemy_count)
		printf("\nEnemy %d: %d %d\n", i, mlx.enemies[i].row, mlx.enemies[i].column);

	mlx_hook(mlx.mlx_win, 2, 0, key_hook, &mlx);
	mlx_hook(mlx.mlx_win, 17, 0, exit_program, &mlx);
	mlx_loop_hook(mlx.mlx_ptr, pacman_animate, &mlx);
	mlx_loop(mlx.mlx_ptr);
}