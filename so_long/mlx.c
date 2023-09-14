#include "mlx.h"
#include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
#include <stdio.h>

#define PROGRAM_ERROR	1
// #define WIDTH			400
// #define HEIGHT			400

void free_matrix(char **matrix, int row)
{
	int	i;

	i = 0;
	while(i < row) {
    	free(matrix[i++]);
	}
	free(matrix);
}

int count_checker(char **matrix, int row, int column)
{
	int i = 0;
	int k = 0;
	char letters[4];

	letters[0] = 0; //C
	letters[1] = 0; //E
	letters[2] = 0; //P
	letters[3] = '\0';
	while(i < row)
	{
		while(k < column)
		{
			if((matrix[i][k] != '1') && (k==0 || k==column-1 || i==0 || i == row-1))
			{
				free_matrix(matrix, row);
				return (0);
			}

			if(matrix[i][k] == 'C')
				letters[0] ++;
			else if(matrix[i][k] == 'E')
				letters[1] ++;
			else if(matrix[i][k] == 'P')
				letters[2] ++;
			else
			{
				if(matrix[i][k] != '1' && matrix[i][k] != '0' )
				{
					free_matrix(matrix, row);
					return(0);
				}
			}
			k++;
		}
		i++;
		k = 0;
	}
	if (letters[0] == 0 || letters[1] != 1 || letters[2] != 1)
	{
		free_matrix(matrix, row);
		return(0);
	}
	free_matrix(matrix, row);
	return (1);
}

int check_insides_map(int fd, int row, int column)
{
	int changing_rows;
	int changing_columns;
	char **matrix;

	matrix = (char **)malloc((row+1) * sizeof(char*));
	int k = 0;
	while(k < row)
	{
		matrix[k] = (char *)malloc((column+1) * sizeof(char));
		k++;
	}
	int sz;
	char symbol[2];

	changing_rows = 0;
	changing_columns = 0;

	sz = 1;
	while(sz != 0)
	{
		sz = read(fd, symbol, 1);

		symbol[sz] = '\0';
		if(sz == 0)
			matrix[changing_rows][changing_columns] = '\0';
		else
			matrix[changing_rows][changing_columns] = symbol[0];
		printf("%c", symbol[0]);
		changing_columns++;
		if(symbol[0] == '\n' || sz == 0)
		{
			changing_rows+=1;
			changing_columns = 0;
		}
	}
	if(count_checker(matrix, row, column))
		return (1);
	return (0);
}

int check_dimensions_map(int fd, int *row, int *column)
{
	int sz;
	char symbol[2];
	int fix_columns;

	fix_columns = -1;
	sz = 1; //so that it will safely enter the loop
	while(sz != 0)
	{
		sz = read(fd, symbol, 1);
		symbol[sz] = '\0';
		if(*row-1 == 0)
			fix_columns++;
		(*column)++;
		if(symbol[0] == '\n')
		{
			(*row)++;
			if(*column != fix_columns)
				return(0);
			*column = -1;
		}
	}
	if(*column != fix_columns)
		return(0);
	*column = fix_columns;
	return(1);
}

int	main()
{
	int fd1;
	int fd2;
	int row;
	int column;
	char **matrix;

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

	// while(1)
	// 	;
}