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

int    check_buffer(char *buffer)
{
    int i;

    i = 0;
    while(buffer[i] != '\0')
    {
        if(buffer[i] == '\n')
            return (i+1);
        i++;
    }
	if(ft_strlen(buffer) != i)
	{
		return (-2);
	}
	return (-1);
}

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

char	*ft_strdup(char *string_1)
{
	char			*string_2;
	unsigned long	i;

	string_2 = malloc(ft_strlen(string_1) * sizeof(char) + 1);
	if (!string_2)
		return (NULL);
	i = 0;
	while (i < ft_strlen(string_1))
	{
		string_2[i] = string_1[i];
		i++;
	}
	string_2[i] = '\0';
	return (string_2);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*storage;
	size_t	i;

	storage = (void *)malloc(count * size);
	if (!storage || \
			(count == SIZE_MAX && size > 1) || (size == SIZE_MAX && count > 1))
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		((char *)storage)[i] = '\0';
		i++;
	}
	return (storage);
}

char	*ft_strjoin(char  *s1, char  *s2)
{

	char	*s3;
	size_t	i;
	size_t	j;
    
	if (!s1 || !s2)
		return (NULL);
	s3 = ft_calloc(1,ft_strlen(s1) + ft_strlen(s2) + 1);
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

int get_the_end(char *buffer)
{
	int i;

	i = 0;
	while(buffer[i] != '\0')
	{
		i++;
	}
	return (i);
}

//int buffer_cut(line, buffer)
