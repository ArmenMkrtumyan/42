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

void	redraw_map(int pos, t_mlx mlx, int row, int column)
{
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, mlx.pacman_eating, column * mlx.p_xy.column, row * mlx.p_xy.row);
	if (pos == UP)
		mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, mlx.empty_space, column * (mlx.xy - 1), row * mlx.xy);
	else if (pos == DOWN)
		mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, mlx.empty_space, column * (mlx.xy + 1), row * mlx.xy);
	else if (pos == LEFT)
		mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, mlx.empty_space, column * mlx.xy, row * (mlx.xy + 1));
	else if (pos == RIGHT)
		mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, mlx.empty_space, column * mlx.xy, row * (mlx.xy - 1));
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
	redraw_map(pos, *mlx, row, column);
}

int key_hook(int key_code, void *mlx_struct)
{
	t_mlx	mlx;

	mlx = *(t_mlx *)mlx_struct;
	printf("Key is: %d\n", key_code);

	if ((key_code == UP || key_code == UP_A) && \
	mlx.char_mat[mlx.p_xy.row - 1][mlx.p_xy.column] != '1')
		switch_places(UP, &mlx, mlx.p_xy.row, mlx.p_xy.column);
	else if ((key_code == DOWN || key_code == DOWN_A) && \
	mlx.char_mat[mlx.p_xy.row + 1][mlx.p_xy.column] != '1')
		switch_places(DOWN, &mlx, mlx.p_xy.row, mlx.p_xy.column);
	else if ((key_code == LEFT || key_code == LEFT_A) && \
	mlx.char_mat[mlx.p_xy.row][mlx.p_xy.column - 1] != '1')
		switch_places(LEFT, &mlx, mlx.p_xy.row, mlx.p_xy.column);
	else if ((key_code == RIGHT || key_code == RIGHT_A) &&\
	mlx.char_mat[mlx.p_xy.row][mlx.p_xy.column - 1] != '1')
		switch_places(RIGHT, &mlx, mlx.p_xy.row, mlx.p_xy.column);
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

int	main(int argc, char	*argv[])
{
	int			fd1;
	int			fd2;
	t_xy		dims;
	void		*mlx_ptr;
	void		*mlx_win;
	t_mlx		mlx;
	t_inside	mat_info;
	char		**char_matrix;

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

	printf("\nPlayer position: %d %d\n", mlx.p_xy.row, mlx.p_xy.column);

	// mlx.mlx_ptr = mlx_init();
	// mlx.door_open = mlx_xpm_file_to_image(mlx.mlx_ptr, "open_door.xpm", &mlx.xy, &mlx.xy);
	// mlx.door_closed = mlx_xpm_file_to_image(mlx.mlx_ptr, "closed_door.xpm", &mlx.xy, &mlx.xy);
	// mlx.enemy = mlx_xpm_file_to_image(mlx.mlx_ptr, "enemy.xpm", &mlx.xy, &mlx.xy);
	// mlx.coin = mlx_xpm_file_to_image(mlx.mlx_ptr, "coin.xpm", &mlx.xy, &mlx.xy);
	// mlx.pacman_ate = mlx_xpm_file_to_image(mlx.mlx_ptr, "pacman_ate.xpm", &mlx.xy, &mlx.xy);
	// mlx.pacman_eating = mlx_xpm_file_to_image(mlx.mlx_ptr, "pacman_eating.xpm", &mlx.xy, &mlx.xy);
	// mlx.wall = mlx_xpm_file_to_image(mlx.mlx_ptr, "wall.xpm", &mlx.xy, &mlx.xy);
	// mlx.empty_space = mlx_xpm_file_to_image(mlx.mlx_ptr, "empty_space.xpm", &mlx.xy, &mlx.xy);
	// mlx.mlx_win = mlx_new_window(mlx.mlx_ptr, mlx.dims.column * mlx.xy, mlx.dims.row * mlx.xy, "Pacman");

	// int k;
	// int i;

	// k = 0;
	// i = 0;
	// printf("\nDIMS ARE: %d, %d\n", mlx.dims.row, mlx.dims.column);
	// while(mlx.char_mat[k])
	// {
	// 	i = 0;
	// 	while(mlx.char_mat[k][i])
	// 	{
	// 		if (mlx.char_mat[k][i] == '0')
	// 			mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, mlx.empty_space,  i*mlx.xy, k*mlx.xy);
	// 		else if (mlx.char_mat[k][i] == '1')
	// 			mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, mlx.wall, i*mlx.xy, k*mlx.xy);
	// 		else if (mlx.char_mat[k][i] == 'C')
	// 			mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, mlx.coin, i*mlx.xy, k*mlx.xy);
	// 		else if (mlx.char_mat[k][i] == 'M')
	// 			mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, mlx.enemy, i*mlx.xy, k*mlx.xy);
	// 		else if (mlx.char_mat[k][i] == 'P')
	// 			mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, mlx.pacman_eating, i*mlx.xy, k*mlx.xy);

	// 		printf("%c", mlx.char_mat[k][i]);
	// 		i++;
	// 	}
	// 	printf("\n");
	// 	k++;
	// }
	// mlx_hook(mlx.mlx_win, 2, 0, key_hook, &mlx);

	// mlx_loop(mlx_ptr);
}