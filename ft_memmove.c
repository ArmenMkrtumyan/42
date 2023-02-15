/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 17:27:34 by amkrtumy          #+#    #+#             */
/*   Updated: 2023/02/15 17:55:46 by amkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void*src, size_t len)
{
	size_t	i;
	char	src_cpy[len];
	
	i = 0;
	if (!dst || !src)
		return (0);
	while(i < len)
	{
		src_cpy[i] = ((char *)src)[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		((char *)dst)[i] = src_cpy[i];
	//	printf("\nDST IS : %s, and src is %s\n", ((char *)dst), src_cpy);
		i++;
	}
	((char *)dst)[ft_strlen(dst)] = '\0';
	return (dst);
}
