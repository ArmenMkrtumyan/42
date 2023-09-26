#include "so_long.h"

#define PROGRAM_ERROR	1

void free_matrix(char **matrix, int row)
{
	int	i;

	i = 0;
	while(i < row)
		free(matrix[i++]);
	free(matrix);
}

int	main()
{
	int fd1;
	int fd2;
	int row;
	int column;

	fd1 = open("map.ber", O_RDONLY);
	if (fd1 < 0)
		return 0;
	fd2 = open("map.ber", O_RDONLY);
	if (fd2 < 0)
		return 0;

	row = 1;
	column = -1;

	if(check_dimensions_map(fd1, &row, &column))
	{
		printf("\nCORRECT MAP DIMENSIONS(%d,%d), CHECKING THE INSIDE...\n", row, column);

		if(check_insides_map(fd2, row, column))
			printf("\nCORRECT MAP INSIDES (%d, %d), LOADING THE GAME...", row, column);
		else
				printf("\nWRONG MAP\n");
	}
	else
		printf("\nWRONG MAP\n");

	while(1)
		;
}