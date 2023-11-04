/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:52:21 by amkrtumy          #+#    #+#             */
/*   Updated: 2023/11/01 20:20:09 by amkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s_1, unsigned int start, size_t len)
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
