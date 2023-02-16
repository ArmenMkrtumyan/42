/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:18:06 by amkrtumy          #+#    #+#             */
/*   Updated: 2023/02/16 18:45:49 by amkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*storage;
	size_t	i;

	storage = (void *)malloc(count * size);
	if (!storage || \
			(count == SIZE_MAX && size > 1) || (size == SIZE_MAX && count > 1))
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		((char *)storage)[i] = '\0';
		i++;
	}
	return (storage);
}
