/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:23:12 by amkrtumy          #+#    #+#             */
/*   Updated: 2023/02/15 19:15:05 by amkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*word;

	i = ft_strlen(s);
	word = (char *)s;
	if (!s)
		return (NULL);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return (&word[i]);
		i--;
	}
	return (NULL);
}
