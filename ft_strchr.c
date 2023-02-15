/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:05:44 by amkrtumy          #+#    #+#             */
/*   Updated: 2023/02/06 15:43:00 by amkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
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
	i = 0;
	while (word[i] != '\0')
	{
		if (word[i] == (char) c)
			return (&word[i]);
	}
	return (NULL);
}
