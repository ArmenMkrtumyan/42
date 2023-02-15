/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:40:25 by amkrtumy          #+#    #+#             */
/*   Updated: 2023/02/06 17:34:31 by amkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *string_1)
{
	char			*string_2;
	unsigned long	i;

	string_2 = malloc(sizeof(string_1) * sizeof(char));
	if (!string_2)
		return (NULL);
	i = 0;
	while (i < sizeof(string_1))
	{
		string_2[i] = string_1[i];
		i++;
	}
	return (string_2);
}
