/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:48:31 by amkrtumy          #+#    #+#             */
/*   Updated: 2023/02/17 14:53:30 by amkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	len_dst;
	size_t	j;

	i = ft_strlen(dst);
	len_dst = i;
	if (!src)
		return (ft_strlen(dst));
	j = 0;
	while (j < ft_strlen(src) && dstsize - i - 1 > 0
		&& dstsize != 0 && dstsize > i)
	{
		dst[i++] = src[j++];
	}
	if (dstsize != 0)
		dst[i] = '\0';
	if (dstsize < ft_strlen(dst))
		return (dstsize + ft_strlen(src));
	return (ft_strlen(src) + len_dst);
}
