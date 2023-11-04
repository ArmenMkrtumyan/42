/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 20:23:20 by amkrtumy          #+#    #+#             */
/*   Updated: 2023/11/01 20:35:28 by amkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_min_max(char *string, char *critical_value)
{
	size_t	k;
	size_t	str_len;

	str_len = ft_strlen(string);
	if (ft_strlen(string) > ft_strlen(critical_value))
		return (-1);
	if (ft_strlen(string) < ft_strlen(critical_value))
		return (1);
	k = -1;
	while (++k < str_len)
	{
		if (string[k] > critical_value[k])
			return (-1);
	}
	return (1);
}