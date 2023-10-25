/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:19:29 by amkrtumy          #+#    #+#             */
/*   Updated: 2023/10/06 16:19:31 by amkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_letters(char letter, char *array, t_xy *e, t_xy *i_k)
{
	if (letter == '1' || letter == '0')
		return (1);
	if (letter == 'C')
		array[0]++;
	else if (letter == 'E')
	{
		array[1]++;
		e->row = i_k->row;
		e->column = i_k->column;
	}
	else if (letter == 'P')
		array[2]++;
	else if (letter == 'M')
		array[3]++;
	if (letter == 'C' || letter == 'E' || letter == 'P' || letter == 'M')
		return (1);
	return (0);
}

void	count_check(t_matrices *matrices, t_xy dims,
	t_inside *insides, t_mlx *mlx)
{
	char			letters[5];
	t_xy			e;
	t_xy			i_k;
	char			element;

	letters_init(letters);
	i_k.row = -1;
	while (++i_k.row < dims.row)
	{
		i_k.column = -1;
		while (++i_k.column < dims.column)
		{
			element = matrices->char_info[i_k.row][i_k.column];
			if ((element != '1') && (i_k.column == 0 || \
			i_k.column == dims.column - 1 || i_k.row == 0 || \
			i_k.row == dims.row - 1))
				on_exit("Wrong insides!");
			else if (check_letters(element, letters, &e, &i_k))
				continue ;
			else
				on_exit("Wrong insides!");
		}
	}
	mlx->enemy_count = letters[3] - '0';
	if (letters[0] == '0' || letters[1] != '1' || letters[2] != '1')
		on_exit("Wrong insides!");
	init_inside(insides, matrices, dims, e);
}

void	fill_matrices(t_matrices *matrices,
	t_xy *dims, t_fileRead *fd, t_mlx *mlx)
{
	fd->sz = 1;
	while (fd->sz != 0)
	{
		fd->sz = read(fd->fd, fd->symbol, 1);
		fd->symbol[fd->sz] = '\0';
		if (fd->sz == 0)
			matrices->char_info[dims->row][dims->column] = '\0';
		else
		{
			matrices->char_info[dims->row][dims->column] = fd->symbol[0];
			matrices->pos_info[dims->row][dims->column].cost = INT_MAX - 1;
			(matrices->pos_info[dims->row][dims->column]).visited = 1;
			if (fd->symbol[0] == 'E')
			{
				mlx->e_xy.row = dims->row;
				mlx->e_xy.column = dims->column;
			}
			if (fd->symbol[0] == 'P')
			{
				(matrices->pos_info[dims->row][dims->column]).cost = 0;
				mlx->p_xy.row = dims->row;
				mlx->p_xy.column = dims->column;
			}
		}
		dims->column++;
		if (fd->symbol[0] == '\n' || fd->sz == 0)
		{
			matrices->char_info[dims->row][dims->column - 1] = 0;
			dims->row += 1;
			dims->column = 0;
		}
	}
}

void	create_matrices(t_xy dim, t_matrices *matrix)
{
	int	k;

	matrix->char_info = malloc((dim.row + 1) * sizeof(char *));
	if (!(matrix->char_info))
	{
		printf("Memory allocation failed");
		exit (1);
	}
	matrix->char_info[dim.row] = NULL;
	matrix->pos_info = malloc((dim.row + 1) * sizeof(t_pos));
	if (!(matrix->pos_info))
	{
		printf("Memory allocation failed");
		exit(1);
	}
	k = 0;
	while (k < dim.row)
	{
		matrix->pos_info[k] = malloc((dim.column + 1) * sizeof(t_pos));
		matrix->char_info[k] = malloc((dim.column + 1) * sizeof(char));
		k++;
	}
}

int	check_insides_map(int fd, t_xy dims, t_inside *insides, t_mlx *mlx)
{
	t_xy			temp_dimensions;
	t_matrices		matrices;
	t_fileRead		file_read_info;

	file_read_info.fd = fd;
	temp_dimensions.row = 0;
	temp_dimensions.column = 0;
	create_matrices(dims, &matrices);
	fill_matrices(&matrices, &temp_dimensions, &file_read_info, mlx);
	count_check(&matrices, dims, insides, mlx);
	return (insides->freed);
}

//letters[0] - C
//letters[1] - E
//letters[2] - P
//letters[3] - M