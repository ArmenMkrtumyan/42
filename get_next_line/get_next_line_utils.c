/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 14:10:41 by amkrtumy          #+#    #+#             */
/*   Updated: 2023/03/12 14:10:58 by amkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *word)
{
	size_t	size;

	if (!word)
		return (0);
	size = 0;
	while (word[size] != '\0')
	{
		size++;
	}
	return (size);
}

char	*ft_strjoin(char  *s1, char  *s2)
{
	char	*s3;
	size_t	i;
	size_t	j;
    
	if (!s1 || !s2)
		return (NULL);
	s3 = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s3)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		s3[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < ft_strlen(s2))
	{
		s3[i] = s2[j];
		j++;
		i++;
	}
	s3[i] = '\0';
	free(s1);
	return (s3);
}

char	*ft_substr(char const *s_1, unsigned int start, size_t len)
{
	char	*s_2;
	size_t	i;

	if (len < ft_strlen(s_1))
		s_2 = malloc((len + 1) * sizeof(char));
	else
		s_2 = malloc(ft_strlen(s_1) * sizeof(char));
	if (!s_2)
		return (NULL);
	i = 0;
	while (i < len && i < ft_strlen(s_1) && start < ft_strlen(s_1))
	{
		s_2[i] = s_1[start];
		i++;
		start++;
	}
	s_2[i] = '\0';
	return (s_2);
}

int	check_line_buffer(char **line,char **returnable, char *buffer)
{
	int	i;

	i = 0;
	while((*line) && (*line)[i] != '\0')
	{
		if((*line)[i] == '\n')
		{
			*returnable = ft_substr(*line, 0, i+1);
			*line = ft_substr(*line, i+1, ft_strlen(*line) - i);
			return (-10);
		}
		i++;
	}
	i = 0;
	if(buffer[0] == '\0')
		return (-3);
	while(buffer[i] != '\0')
	{
		if(buffer[i] == '\n')
			return (i+1);
		i++;
	}
	return (-1);
}

char    *result_checker(char **line, char**returnable, char *buffer, int result)
{
	if (result == -3)
	{
		if(!(*line))
			return (NULL);
		*returnable = ft_substr(*line, 0, ft_strlen(*line));
		*line = NULL;
		return(*returnable);
	}
	else if (result == -10)
		return(*returnable);
	else
	{
		if(*line)
			*line = ft_strjoin(*line, ft_substr(buffer, 0, result));
		else
			*line = ft_substr(buffer, 0, result);
		*returnable = ft_substr(*line, 0, ft_strlen(*line));
		*line = ft_substr(buffer, result, ft_strlen(buffer) - result);
		return (*returnable);
	}
}