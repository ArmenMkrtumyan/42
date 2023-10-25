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

void	on_exit(char *error_message)
{
	printf("\n\n%s\n\n", error_message);
	exit(1);
}

int	exit_program(void *mlx_ptr)
{
	on_exit("\nClosed the game\n");
	return (1);
}

int	hit_enemy(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < mlx->enemy_count)
	{
		if (mlx->enemies[i].row == mlx->p_xy.row
			&& mlx->enemies[i].col == mlx->p_xy.col)
		{
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win,
				mlx->empty_space, mlx->xy * mlx->p_xy.col,
				mlx->xy * mlx->p_xy.row);
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win,
				mlx->boom, mlx->xy * mlx->p_xy.col,
				mlx->xy * mlx->p_xy.row);
			mlx->is_dead = 1;
			return (0);
		}
		i++;
	}
	return (0);
}

void	ft_lstdellast(t_list **list)
{
	t_list	*prev;
	t_list	*initial;

	initial = *list;
	if (!(*list))
		return ;
	if ((*list)->next)
	{
		while ((*list)->next->next)
			*list = (*list)->next;
		ft_lstdelone((*list)->next);
		(*list)->next = NULL;
	}
	else
	{
		ft_lstdelone(*list);
		*list = NULL;
		return ;
	}
	*list = initial;
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
	dims.col = -1;
	fd1 = get_fd(argv[1]);
	fd2 = get_fd(argv[1]);
	checkings(fd1, fd2, dims, &mlx);
	init_enemies(&mlx);
	init_mlx(&mlx);
	draw_map(&mlx);
	mlx_hook(mlx.mlx_win, 2, 0, key_hook, &mlx);
	mlx_hook(mlx.mlx_win, 17, 0, exit_program, &mlx);
	mlx_loop_hook(mlx.mlx_ptr, pacman_animate, &mlx);
	mlx_loop(mlx.mlx_ptr);
}
