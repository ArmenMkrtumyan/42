/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:16:34 by amkrtumy          #+#    #+#             */
/*   Updated: 2023/01/30 18:54:27 by amkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*itoa_minus(int len, int n, char sign)
{
	char	*i_to_string;
	int		i;

	i_to_string = (char *)malloc(sizeof(char) * (len + 2));
	if (!i_to_string)
		return (NULL);
	i = len + 1;
	while (n > 0)
	{
		i_to_string[i - 1] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	i_to_string[len + 1] = '\0';
	i_to_string[0] = sign;
	return (i_to_string);
}

static char	*itoa_plus(int len, int n)
{
	char	*i_to_string;
	int		i;

	i_to_string = (char *)malloc(sizeof(char) * (len + 1));
	if (!i_to_string)
		return (NULL);
	i = len;
	while (n > 0)
	{
		i_to_string[i - 1] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	i_to_string[len] = '\0';
	return (i_to_string);
}

char	*ft_itoa(int n)
{
	int		copy_n;
	int		len;
	char	*i_to_string;
	char	sign;

	copy_n = n;
	len = 0;
	if (copy_n < 0)
	{
		sign = '-';
		copy_n *= -1;
		n *= -1;
	}
	else
		sign = '+';
	while (copy_n > 0)
	{
		len++;
		copy_n /= 10;
	}
	if (sign == '-' )
		i_to_string = itoa_minus(len, n, sign);
	else
		i_to_string = itoa_plus(len, n);
	return (i_to_string);
}
