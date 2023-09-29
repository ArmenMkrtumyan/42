#include "so_long.h"

int free_matrix(t_matrices *matrices, int row)
{
	int	i;

	i = 0;
	while(i < row)
		free(matrices->passed_matrix[i++]);
	free(matrices->passed_matrix);
	i = 0;
	while(i < row)
		free(matrices->full_matrix[i++]);
	free(matrices->full_matrix);
	return (0);
}

int	main()
{
	int				fd1;
	int				fd2;
	t_coordinate	dimensions;

	dimensions.row = 1;
	dimensions.column = -1;
	fd1 = open("map.ber", O_RDONLY);
	if (fd1 < 0)
		return 0;
	fd2 = open("map.ber", O_RDONLY);
	if (fd2 < 0)
		return 0;
	if (check_dimensions_map(fd1, &dimensions))
	{
		printf("\n\nCORRECT MAP DIMENSIONS(%d,%d), CHECKING THE INSIDE...\n\n", dimensions.row, dimensions.column);

		if (check_insides_map(fd2, dimensions))
			printf("\n\nCORRECT MAP INSIDES (%d, %d), LOADING THE GAME...", dimensions.row, dimensions.column);
		else
			printf("\n\nWRONG INSIDES\n\n");
	}
	else
		printf("\n\nWRONG DIMENSIONS\n\n");

	// while(1)
	// 	;
}