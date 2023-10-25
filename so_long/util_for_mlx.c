/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:19:14 by amkrtumy          #+#    #+#             */
/*   Updated: 2023/10/06 16:19:15 by amkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	pacman_animate(t_mlx *mlx)
{
	static unsigned int	timer = 0;
	static unsigned int	timer_dead = 0;
	char				*texture;

	if (mlx->is_dead)
	{
		timer_dead++;
		if (timer_dead == 10000)
			on_exit("Game Over");
		return (1);
	}
	if (hit_enemy(mlx))
		on_exit("You lost!");
	if (timer % 2000 == 0 || timer % 3000 == 0)
	{
		if (timer % 2000 == 0)
			texture = mlx->pacman_eating;
		else if (timer % 3000 == 0)
			texture = mlx->pacman_ate;
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, mlx->empty_space, \
		mlx->xy * mlx->p_xy.col, mlx->xy * mlx->p_xy.row);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, texture, \
		mlx->xy * mlx->p_xy.col, mlx->xy * mlx->p_xy.row);
	}
	if (timer % 8000 == 0)
		update_weights_after_move(mlx);
	timer ++;
	return (1);
}

int	key_hook(int key_code, void *mlx_ptr)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)mlx_ptr;
	if (key_code == ESC)
	{
		on_exit("\nClosing the game");
	}
	if (mlx->is_dead)
		return (0);
	if ((key_code == UP || key_code == UP_A) && \
	mlx->char_mat[mlx->p_xy.row - 1][mlx->p_xy.col] != '1')
		switch_places(UP, mlx, mlx->p_xy.row, mlx->p_xy.col);
	else if ((key_code == DOWN || key_code == DOWN_A) && \
	mlx->char_mat[mlx->p_xy.row + 1][mlx->p_xy.col] != '1')
		switch_places(DOWN, mlx, mlx->p_xy.row, mlx->p_xy.col);
	else if ((key_code == LEFT || key_code == LEFT_A) && \
	mlx->char_mat[mlx->p_xy.row][mlx->p_xy.col - 1] != '1')
		switch_places(LEFT, mlx, mlx->p_xy.row, mlx->p_xy.col);
	else if ((key_code == RIGHT || key_code == RIGHT_A) && \
	mlx->char_mat[mlx->p_xy.row][mlx->p_xy.col + 1] != '1')
		switch_places(RIGHT, mlx, mlx->p_xy.row, mlx->p_xy.col);
	return (1);
}
