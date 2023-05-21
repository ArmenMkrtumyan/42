/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:01:34 by amkrtumy          #+#    #+#             */
/*   Updated: 2023/04/29 18:24:37 by amkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	size_t	i;
	size_t	j;
	size_t	size;

	if (!s1 || !s2)
		return (NULL);
	s3 = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s3)
		return (NULL);
	i = -1;
	size = ft_strlen(s1);
	while (++i < size)
		s3[i] = s1[i];
	j = -1;
	size = ft_strlen(s2);
	while (++j < size)
		s3[i++] = s2[j];
	s3[i] = '\0';
	free(s1);
	return (s3);
}

char	*ft_substr(char *s_1, unsigned int start, size_t len)
{
	char	*s_2;
	size_t	i;

	if (len < ft_strlen(s_1))
		s_2 = malloc((len + 1) * sizeof(char));
	else
		s_2 = malloc((ft_strlen(s_1) + 1) * sizeof(char));
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

void	free_memory_1(char ***line)
{
	char	*freeable;

	freeable = **line;
	**line = NULL;
	free(freeable);
}

void	free_memory_2(char ***line, int i)
{
	char	*freeable;

	freeable = ft_substr(**line, i + 1, ft_strlen(**line) - i);
	free(**line);
	**line = freeable;
}
