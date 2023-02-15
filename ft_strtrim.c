/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:42:08 by amkrtumy          #+#    #+#             */
/*   Updated: 2023/02/06 17:01:44 by amkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	startpoint(int s1_len, int set_len, char const *s1, char const *set)
{
	int	start;
	int	found;
	int	i;
	int	j;

	i = -1;
	start = 0;
	while (++i < s1_len)
	{
		found = 0;
		j = 0;
		while (j < set_len)
		{
			if (s1[i] == set[j])
			{
				found++;
				start = i + 1;
				break ;
			}
			j++;
		}
		if (found == 0)
			break ;
	}
	return (start);
}

static int	endpoint(char const *s1, char const *set, int start)
{
	int		end;
	int		found;
	int		i;
	size_t	j;

	i = ft_strlen(s1) - 1;
	end = i;
	while (i >= 0 && end > start)
	{
		found = 0;
		j = -1;
		while (++j < ft_strlen(set))
		{
			if (s1[i] == set[j])
			{
				found++;
				end = i - 1;
				break ;
			}
		}
		if (found == 0)
			break ;
		i--;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s3;
	int		start;
	int		end;
	int		i;

	if (!s1 || !set)
		return (NULL);
	start = startpoint(ft_strlen(s1), ft_strlen(set), s1, set);
	end = endpoint(s1, set, start);
	if (start > end)
		return (NULL);
	s3 = malloc(end - start + 1 + 1);
	if (!s3)
		return (NULL);
	i = 0;
	while (start <= end)
		s3[i++] = s1[start++];
	s3[i] = '\0';
	return (s3);
}
