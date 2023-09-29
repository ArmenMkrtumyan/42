#include "so_long.h"

int count_checker(t_matrices *matrices, int row, int column)
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
	dimensions.row = row;
	dimensions.column = column;
	i = -1;
	while (++i < row)
	{
		k = 0;
		while (++k < column)
		{
			if ((matrices->passed_matrix[i][k] != '1') && (k==0 || k==column-1 || i==0 || i == row-1))
				return (free_matrix(matrices, row));
			else if (matrices->passed_matrix[i][k] == 'C')
				letters[0] ++;
			else if (matrices->passed_matrix[i][k] == 'E')
			{
				letters[1] ++;
				E_coordinate.row	= i;
				E_coordinate.column	= k;
			}
			else if (matrices->passed_matrix[i][k] == 'P')
				letters[2] ++;
			else if (matrices->passed_matrix[i][k] != '1' && matrices->passed_matrix[i][k] != '0' )
					return (free_matrix(matrices, row));
		}
	}
	if (letters[0] == 0 || letters[1] != 1 || letters[2] != 1)
		return (free_matrix(matrices, row));
	check_path(matrices->full_matrix, matrices->passed_matrix, dimensions, E_coordinate);
	return (1);
}

int check_dimensions_map(int fd, t_coordinate *dimensions)
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
		if ((dimensions->row) - 1 == 0)
			fix_columns++;
		(dimensions->column)++;
		if (symbol[0] == '\n')
		{
			(dimensions->row)++;
			if (dimensions->column != fix_columns)
				return(0);
			dimensions->column = -1;
		}
	}
	if (dimensions->column != fix_columns || dimensions->row < 3)
		return (0);
	dimensions->column = fix_columns;
	return (1);
}

t_matrices	create_matrices(t_coordinate dimensions)
{
	t_matrices	matrices;
	int			k;

	matrices.passed_matrix = (char **)malloc((dimensions.row + 1) * sizeof(char*));
	if (!(matrices.passed_matrix))
	{
		printf("Memory allocation failed");
		exit(1);
	}
	matrices.full_matrix = (t_position **)malloc((dimensions.row + 1) * sizeof(t_position));
	if (!(matrices.full_matrix))
	{
		printf("Memory allocation failed");
		exit(1);
	}
	k = 0;
	while (k < dimensions.row)
	{
		matrices.full_matrix[k] = (t_position *)malloc((dimensions.column + 1) * sizeof(t_position));
		matrices.passed_matrix[k] = (char *)malloc((dimensions.column + 1) * sizeof(char));
		k++;
	}
	return (matrices);
}

void	fill_matrices(t_matrices *matrices, t_coordinate *dimensions, t_fileRead *file_read_info)//int *fd, int *sz, char *symbol)
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
			dimensions->row+=1;
			dimensions->column = 0;
		}
	}
}

int	check_insides_map(int fd, t_coordinate dimensions)
{
	t_coordinate	temp_dimensions;
	t_matrices		matrices;
	t_fileRead		file_read_info;

	file_read_info.fd = fd;
	matrices = create_matrices(dimensions);
	temp_dimensions.row = 0;
	temp_dimensions.column = 0;
	fill_matrices(&matrices, &temp_dimensions, &file_read_info);

	if (count_checker(&matrices, dimensions.row, dimensions.column))
		return (1);
	return (0);
}
