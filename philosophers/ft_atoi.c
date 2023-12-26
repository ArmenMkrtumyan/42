/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:31:32 by amkrtumy          #+#    #+#             */
/*   Updated: 2023/02/01 16:21:59 by amkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_emptyness(int i, const char *str)
{
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 127 || str[i] == 32)
		i++;
	return (i);
}

void	check_sign(char str_i, int *sign, int *i)
{
	if (str_i == 43 || str_i == 45)
	{
		if (str_i == 45)
			*sign = -1;
		*i = *i + 1;
	}
}

int	ft_atoi(char *str)
{
	int	i;
	int	number;
	int	sign;
	int	initial_i;

	if (!str)
		return (0);
	i = 0;
	number = 0;
	sign = 1;
	i = check_emptyness(i, str);
	initial_i = i;
	while (str[i] != '\0')
	{
		if (initial_i == i)
			check_sign(str[i], &sign, &i);
		if ((str[i] < 48 || str[i] > 57))
			break ;
		number *= 10;
		number += (str[i] - '0');
		i++;
	}
	if (sign == -1)
		return (-1 * number);
	return (number);
}
