/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 17:27:34 by amkrtumy          #+#    #+#             */
/*   Updated: 2023/02/17 15:26:40 by amkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void*src, size_t len)
{
	size_t	i;

	i = 0;
	if (!dst || !src)
		return (0);
	if (src > dst)
	{
		while (i < len)
		{
			((char *)dst)[i] = ((char *)src)[i];
			i++;
		}
	}
	else if (src < dst)
	{
		while (len-- > 0)
			((char *)dst)[len] = ((char *)src)[len];
	}
	((char *)dst)[ft_strlen(dst)] = '\0';
	return (dst);
}
