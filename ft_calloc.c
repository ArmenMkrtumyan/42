/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:18:06 by amkrtumy          #+#    #+#             */
/*   Updated: 2023/02/06 16:56:01 by amkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*storage;
	size_t	i;

	storage = (void *)malloc(count * size);
	if (!storage)
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		((char *)storage)[i] = '\0';
		i++;
	}
	return (storage);
}
