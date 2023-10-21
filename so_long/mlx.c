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

void	checkings(int fd1, int fd2, t_xy dims)
{
	t_inside		insides;

	if (check_dimensions_map(fd1, &dims))
	{
		printf("\n\nCORRECT DIMENSIONS(%d, %d),CHECKING THE INSIDE...\n\n", \
		dims.row, dims.column);
		if (check_insides_map(fd2, dims, &insides) == 0)
		{
			printf("\n\nCORRECT MAP INSIDES, CHECKING PATHS...");
			check_path(&insides.matrices, insides.dims, \
			insides.e_xy);
			if (insides.matrices.path_exists == 1)
				printf("\n\nCORRECT PATHS...Launching the game\n\n");
			else
				on_exit("Issue with paths!");
		}
	}
	else
		printf("\n\nWRONG DIMENSIONS\n\n");
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
	int		fd1;
	int		fd2;
	t_xy	dims;
	void	*mlx_ptr;
	void	*mlx_win;
	t_mlx	mlx;

	mlx_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_ptr, 512, 512, "Pacman");
	mlx.door_open = mlx_xpm_file_to_image(mlx_ptr, "open_door.xpm", &mlx.xy, &mlx.xy);
	mlx.door_closed = mlx_xpm_file_to_image(mlx_ptr, "closed_door.xpm", &mlx.xy, &mlx.xy);
	mlx.enemy = mlx_xpm_file_to_image(mlx_ptr, "enemy.xpm", &mlx.xy, &mlx.xy);
	mlx.coin = mlx_xpm_file_to_image(mlx_ptr, "coin.xpm", &mlx.xy, &mlx.xy);
	mlx.pacman_ate = mlx_xpm_file_to_image(mlx_ptr, "pacman_ate.xpm", &mlx.xy, &mlx.xy);
	mlx.pacman_eating = mlx_xpm_file_to_image(mlx_ptr, "pacman_eating.xpm", &mlx.xy, &mlx.xy);
	mlx.wall = mlx_xpm_file_to_image(mlx_ptr, "wall.xpm", &mlx.xy, &mlx.xy);
	mlx.empty_space = mlx_xpm_file_to_image(mlx_ptr, "empty_space.xpm", &mlx.xy, &mlx.xy);
	mlx_put_image_to_window(mlx_ptr, mlx_win, mlx.door_open, 0, 0);
	mlx_put_image_to_window(mlx_ptr, mlx_win, mlx.door_closed, 64, 0);
	mlx_put_image_to_window(mlx_ptr, mlx_win, mlx.enemy, 128, 0);
	mlx_put_image_to_window(mlx_ptr, mlx_win, mlx.coin, 192, 0);
	mlx_put_image_to_window(mlx_ptr, mlx_win, mlx.pacman_ate, 256, 0);
	mlx_put_image_to_window(mlx_ptr, mlx_win, mlx.pacman_eating, 320, 0);
	mlx_put_image_to_window(mlx_ptr, mlx_win, mlx.wall, 384, 0);
	mlx_put_image_to_window(mlx_ptr, mlx_win, mlx.empty_space, 448, 0);

	mlx_loop(mlx_ptr);

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
	checkings(fd1, fd2, dims);
}
// while (1)
// 	{}
