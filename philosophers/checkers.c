/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 18:45:39 by amkrtumy          #+#    #+#             */
/*   Updated: 2023/12/26 18:45:56 by amkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_max(char *string, char *critical_value)
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

int	check_if_number(char *element)
{
	int	i;

	if (element[0] == '0')
	{
		printf("Invalid number\n");
		return (-1);
	}
	i = -1;
	while (element[++i])
	{
		if (element[i] < 48 || element[i] > 57)
		{
			printf("Invalid number\n");
			return (-1);
		}
	}
	return (1);
}

int		check_parsing(char *element)
{
	if (check_if_number(element) == -1)
		return (-1);
	if (check_max(element, "2147483647") == -1)
	{
		printf("One of the numbers is greater than INT_MAX\n");
		return (-1);
	}
	return (1);
}
