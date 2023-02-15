/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:52:21 by amkrtumy          #+#    #+#             */
/*   Updated: 2023/02/06 17:03:39 by amkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s_1, unsigned int start, size_t len)
{
	char	*s_2;
	size_t	i;

	s_2 = malloc((len - start + 1) * sizeof(char));
	if (!s_2)
		return (NULL);
	i = 0;
	while (i < len)
	{
		s_2[i] = s_1[start];
		i++;
		start++;
	}
	s_2[start] = '\0';
	return (s_2);
}
