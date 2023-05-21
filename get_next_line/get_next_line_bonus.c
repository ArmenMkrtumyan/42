/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:01:11 by amkrtumy          #+#    #+#             */
/*   Updated: 2023/04/03 17:50:37 by amkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

int	for_norminette(char ***line, char ***returnable, char *buffer, int result)
{
	if (**line)
	{
		**returnable = ft_substr(buffer, 0, result);
		**line = ft_strjoin(**line, **returnable);
		free(**returnable);
	}
	else
		**line = ft_substr(buffer, 0, result);
	**returnable = ft_substr(**line, 0, ft_strlen(**line));
	free(**line);
	**line = ft_substr(buffer, result, ft_strlen(buffer) - result);
	return (1);
}

int	result_checker(char **line, char **returnable, char *buffer, int result)
{
	if (result == -1)
	{
		if (!(*line))
			*line = ft_substr(buffer, 0, ft_strlen(buffer));
		else
			*line = ft_strjoin(*line, buffer);
		return (0);
	}
	else if (result == -3)
	{
		if (ft_strlen(*line) == 0)
		{
			free_memory_1(&(line));
			return (0);
		}
		*returnable = ft_substr(*line, 0, ft_strlen(*line));
		free_memory_1(&(line));
		return (1);
	}
	else
		return (for_norminette(&line, &returnable, buffer, result));
}

int	check_line(char **line, char **returnable)
{
	int		i;

	i = 0;
	while ((*line) && (*line)[i] != '\0')
	{
		if ((*line)[i] == '\n')
		{
			*returnable = ft_substr(*line, 0, i + 1);
			free_memory_2(&line, i);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_buffer(char *buffer)
{
	int		i;

	i = 0;
	if (buffer[0] == '\0')
		return (-3);
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
			return (i + 1);
		i++;
	}
	return (-1);
}

char	*get_next_line(int fd)
{
	int			sz;
	char		buffer[BUFFER_SIZE + 1];
	int			result;
	static char	*line[OPEN_MAX];
	char		*returnable;

	result = -1;
	sz = 0;
	returnable = NULL;
	while (++result < BUFFER_SIZE + 1)
		buffer[result] = '\0';
	while (result != -3)
	{
		if (check_line(&line[fd], &returnable) == 0)
			sz = read(fd, buffer, BUFFER_SIZE);
		buffer[sz] = '\0';
		if (returnable)
			return (returnable);
		result = check_buffer(buffer);
		if (result_checker(&line[fd], &returnable, buffer, result))
			return (returnable);
	}
	return (NULL);
}
/*int main()
{
     int fd;

     fd = open("gnlTester/files/big_line_no_nl", O_RDONLY);
     if (fd < 0)
         return 0;
     char *smth =  get_next_line(fd);
     while(smth)
     {
         printf("%s", smth);
         free(smth);
         smth = get_next_line(fd);
     }
     if(smth)
	    free(smth);
}*/
