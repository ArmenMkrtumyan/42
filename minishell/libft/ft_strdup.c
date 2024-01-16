/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:40:25 by amkrtumy          #+#    #+#             */
/*   Updated: 2023/02/20 13:47:26 by amkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *string_1)
{
	char			*string_2;
	unsigned long	i;

	string_2 = malloc(ft_strlen(string_1) * sizeof(char) + 1);
	if (!string_2)
		return (NULL);
	i = 0;
	while (i < ft_strlen(string_1))
	{
		string_2[i] = string_1[i];
		i++;
	}
	string_2[i] = '\0';
	return (string_2);
}
