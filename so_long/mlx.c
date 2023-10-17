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

void	free_matrix(t_matrices *matrices, int row, t_insides *insides)
{
	int	i;

	i = 0;
	while (i < row)
		free(matrices->passed_matrix[i++]);
	free(matrices->passed_matrix);
	i = 0;
	while (i < row)
		free(matrices->full_matrix[i++]);
	free(matrices->full_matrix);
	insides->freed = 1;
}

int	main(int argc, char	*argv[])
{
	int				fd1;
	int				fd2;
	t_coordinate	dimensions;
	t_insides		insides;

	(void) argc;
	(void) argv;
	dimensions.row = 1;
	dimensions.column = -1;
	fd1 = get_fd("map.ber");
	fd2 = get_fd("map.ber");
	if (check_dimensions_map(fd1, &dimensions))
	{
		printf("\n\nCORRECT DIMENSIONS(%d, %d),CHECKING THE INSIDE...\n\n", \
		dimensions.row, dimensions.column);
		if (check_insides_map(fd2, dimensions, &insides) == 0)
		{
			printf("\n\nCORRECT MAP INSIDES (%d, %d),CHECKING PATHS...", \
			dimensions.row, dimensions.column);
			check_path(&insides.matrices, insides.dimensions, insides.E_coordinates);
			if (insides.matrices.path_exists == 1)
				printf("\n\nCORRECT PATHS...Launching the game\n\n");
			else
			{
				printf("\n\nISSUE WITH PATHS\n\n");
				free_matrix(&insides.matrices, dimensions.row, &insides);
			}
		}
		else
			printf("\n\nWRONG INSIDES\n\n");
	}
	else
		printf("\n\nWRONG DIMENSIONS\n\n");
	while (1)
		{}
}
