/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:05:20 by amkrtumy          #+#    #+#             */
/*   Updated: 2023/02/06 16:58:14 by amkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *word)
{
	size_t	size;

	if (!word)
		return (0);
	size = 0;
	while (word[size] != '\0')
	{
		size++;
	}
	return (size);
}
