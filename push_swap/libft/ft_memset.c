/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:07:56 by amkrtumy          #+#    #+#             */
/*   Updated: 2023/02/06 15:37:43 by amkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *address_of, int val_to_be_filled, size_t num_of_bytes)
{
	size_t	i;

	i = 0;
	while (i < num_of_bytes)
	{
		((char *)address_of)[i] = val_to_be_filled;
		i++;
	}
	return (address_of);
}
