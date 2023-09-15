#include "so_long.h"

int count_checker(char **matrix, t_position **full_matrix, int row, int column)
{
	int				i = 0;
	int				k = 0;
	static	char	letters[4]; // CEP
	t_coordinate	E_coordinate;
	t_coordinate	dimensions;

	// letters[0] = 0; //C
	// letters[1] = 0; //E
	// letters[2] = 0; //P
	// letters[3] = '\0';
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
			{
				letters[1] ++;
				E_coordinate.row	= i;
				E_coordinate.column	= k;
			}
			else if(matrix[i][k] == 'P')
				letters[2] ++;
			else
			{
				if (matrix[i][k] != '1' && matrix[i][k] != '0' )
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
		return (0);
	}
	dimensions.row = row;
	dimensions.column = column;
	check_path(full_matrix, matrix, dimensions, E_coordinate);
	return (1);
}

int check_dimensions_map(int fd, int *row, int *column)
{
	int		sz;
	char	symbol[2];
	int		fix_columns;

	fix_columns = -1;
	sz = 1; //so that it will safely enter the loop
	while (sz != 0)
	{
		sz = read(fd, symbol, 1);
		symbol[sz] = '\0';
		if (*row-1 == 0)
			fix_columns++;
		(*column)++;
		if (symbol[0] == '\n')
		{
			(*row)++;
			if (*column != fix_columns)
				return(0);
			*column = -1;
		}
	}
	if (*column != fix_columns)
		return (0);
	*column = fix_columns;
	return (1);
}


int	check_insides_map(int fd, int row, int column)
{
	int changing_rows;
	int changing_columns;
	char **matrix;
	t_position **full_matrix;

	matrix = (char **)malloc((row+1) * sizeof(char*));

	full_matrix = (t_position **)malloc((row + 1) * sizeof(t_position));

	int k = 0;
	while(k < row)
	{
		full_matrix[k] = (t_position *)malloc((column + 1) * sizeof(t_position));
		matrix[k] = (char *)malloc((column + 1) * sizeof(char));
		k++;
	}
	int sz;
	char symbol[2];

	changing_rows = 0;
	changing_columns = 0;

	sz = 1;
	while (sz != 0)
	{
		sz = read(fd, symbol, 1);

		symbol[sz] = '\0';
		if (sz == 0)
			matrix[changing_rows][changing_columns] = '\0';
		else
		{
			matrix[changing_rows][changing_columns] = symbol[0];
			full_matrix[changing_rows][changing_columns].cost = INT_MAX - 1;
			full_matrix[changing_rows][changing_columns].visited = 1;
			if (symbol[0] == 'P')
				full_matrix[changing_rows][changing_columns].cost = 0;
		}
		printf ("%c", symbol[0]);
		changing_columns++;
		if (symbol[0] == '\n' || sz == 0)
		{
			changing_rows+=1;
			changing_columns = 0;
		}
	}
	if (count_checker(matrix, full_matrix, row, column))
		return (1);
	return (0);
}
