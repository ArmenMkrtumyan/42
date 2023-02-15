/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:23:12 by amkrtumy          #+#    #+#             */
/*   Updated: 2023/02/06 15:49:42 by amkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*word;

	i = 0;
	word = NULL;
	while (s[i] != '\0')
	{
		word[i] = s[i];
		i++;
	}
	while (i >= 0)
	{
		if (word[i] == (char)c)
			return (&word[i]);
		i--;
	}
	return (NULL);
}
