/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 17:28:31 by amkrtumy          #+#    #+#             */
/*   Updated: 2023/02/15 18:27:57 by amkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*sentence;

	sentence = (unsigned char *)s;
	i = 0;
	while (i < n && (sentence[i] != '\0' || sentence[i] == 0))
	{
		if (sentence[i] == (unsigned char)c)
			return (&sentence[i]);
		i++;
	}
	return (NULL);
}
