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
	int				fd1;
	int				fd2;
	t_xy	dims;

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
