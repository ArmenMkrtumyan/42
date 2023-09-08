#include "mlx.h"
#include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
#include <stdio.h>

#define PROGRAM_ERROR	1
// #define WIDTH			400
// #define HEIGHT			400

int count_checker(char symbol)
{
	
}

int check_insides_map(int fd, int row, int column)
{
	int changing_rows;
	int changing_columns;
	char matrix[row+1][column+1];
	int sz;
	char symbol[2];

	changing_rows = 0;
	changing_columns = 0;

	sz = 1;
	while(sz != 0)
	{
		sz = read(fd, symbol, 1);
		if(symbol[0] == '\n' || sz == 0)
		{
			changing_rows+=1;
			changing_columns = 0;
		}
		symbol[sz] = '\0';
		if(sz == 0)
			matrix[changing_rows][changing_columns] = '\0';
		else
			matrix[changing_rows][changing_columns] = symbol[0];
		printf("%c", matrix[changing_rows][changing_columns]);
		changing_columns++;
	}
	changing_rows = 0;
	changing_columns = 0;
	printf("\n\n\n\n\n\n");
	while(changing_rows < row)
	{
		while(changing_columns <= column)
		{
			count_checker(matrix[changing_rows][changing_columns]);
			write(1, &matrix[changing_rows][changing_columns], 1);
			changing_columns++;
		}
		changing_columns = 0;
		changing_rows ++;
	}
	return (1);
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
			printf("\nCORRECT MAP INSIDES, LOADING THE GAME...");

	}
	else
		printf("\nWRONG MAP\n");

}