/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:48:31 by amkrtumy          #+#    #+#             */
/*   Updated: 2023/01/23 18:14:39 by amkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	len_1;
	size_t	len_2;
	size_t	j;

	i = 0;
	len_1 = 0;
	len_2 = 0;
	while (dst[i] != '\0')
	{
		i++;
		len_1++;
	}
	while (src[len_2] != '\0' )
		len_2++;
	j = 0;
	while (i < (dstsize - 1))
	{
		dst[i++] = src[j++];
	}
	dst[i] = '\0';
	if (dstsize < len_1)
		return (dstsize + len_2);
	return (len_2 + len_1);
}
