/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 17:28:31 by amkrtumy          #+#    #+#             */
/*   Updated: 2023/02/09 19:56:51 by amkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned int	*sentence;

	sentence = (unsigned int *)s;
	i = 0;
	while (sentence[i] != '\0' && i < n)
	{
		if (sentence[i] == (unsigned int)c)
			return (&sentence[i]);
		i++;
	}
	return (NULL);
}
