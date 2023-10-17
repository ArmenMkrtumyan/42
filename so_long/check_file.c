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

int	check_letters(char letter, char *array, t_coordinate *e, t_coordinate *i_k)
{
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
	if (letter == 'C' || letter == 'E' || letter == 'P')
		return (1);
	return (0);
}

void	count_check(t_matrices *matrices, t_coordinate dims, t_inside *insides)
{
	char			letters[4];
	t_coordinate	e;
	t_coordinate	i_k;
	char			element;

	letters_initializer(letters);
	i_k.row = -1;
	while (++i_k.row < dims.row)
	{
		i_k.column = 0;
		while (++i_k.column < dims.column)
		{
			element = matrices->passed_matrix[i_k.row][i_k.column];
			if(check_letters(element, letters, &e, &i_k))
				continue;
			else if (((element != '1') && (i_k.column == 0 || i_k.column == dims.column - 1 \
			|| i_k.row == 0 || i_k.row == dims.row-1)) || element != '1' && element != '0')
				free_matrix(matrices, dims.row, insides);
		}
	}
	if (letters[0] == '0' || letters[1] != '1' || letters[2] != '1')
		return (free_matrix(matrices, dims.row, insides));
	initialize_insides(insides, matrices, dims, e);
}

void	fill_matrices(t_matrices* matrices, t_coordinate* dimensions, t_fileRead* file_read_info)
{
	file_read_info->sz = 1;
	while (file_read_info->sz != 0)
	{
		file_read_info->sz = read(file_read_info->fd, file_read_info->symbol, 1);
		file_read_info->symbol[file_read_info->sz] = '\0';
		if (file_read_info->sz == 0)
			matrices->passed_matrix[dimensions->row][dimensions->column] = '\0';
		else
		{
			matrices->passed_matrix[dimensions->row][dimensions->column] = file_read_info->symbol[0];
			matrices->full_matrix[dimensions->row][dimensions->column].cost = INT_MAX - 1;
			(matrices->full_matrix[dimensions->row][dimensions->column]).visited = 1;
			if (file_read_info->symbol[0] == 'P')
				(matrices->full_matrix[dimensions->row][dimensions->column]).cost = 0;
		}
		printf ("%c", file_read_info->symbol[0]);
		dimensions->column++;
		if (file_read_info->symbol[0] == '\n' || file_read_info->sz == 0)
		{
			dimensions->row		+=	1;
			dimensions->column	=	0;
		}
	}
}

void	create_matrices(t_coordinate dimensions, t_matrices* matrices)
{
	int	k;

	matrices->passed_matrix = (char **)malloc((dimensions.row + 1) * sizeof(char*));
	if (!(matrices->passed_matrix))
	{
		printf("Memory allocation failed");
		exit (1);
	}
	matrices->full_matrix = (t_position **)malloc((dimensions.row + 1) * sizeof(t_position));
	if (!(matrices->full_matrix))
	{
		printf("Memory allocation failed");
		exit(1);
	}
	k = 0;
	while (k < dimensions.row)
	{
		matrices->full_matrix[k] = (t_position *)malloc((dimensions.column + 1) * sizeof(t_position));
		matrices->passed_matrix[k] = (char *)malloc((dimensions.column + 1) * sizeof(char));
		k++;
	}
}

int	check_insides_map(int fd, t_coordinate dimensions, t_inside* insides)
{
	t_coordinate	temp_dimensions;
	t_matrices		matrices;
	t_fileRead		file_read_info;

	file_read_info.fd = fd;
	temp_dimensions.row = 0;
	temp_dimensions.column = 0;
	create_matrices(dimensions, &matrices);
	fill_matrices(&matrices, &temp_dimensions, &file_read_info);
	count_check(&matrices, dimensions, insides);
	return (insides->freed);
}

//letters[0] - C
//letters[1] - E
//letters[2] - P