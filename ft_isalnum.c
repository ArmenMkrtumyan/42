/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:01:26 by amkrtumy          #+#    #+#             */
/*   Updated: 2023/01/18 18:03:40 by amkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(char al_num)
{
	if (al_num >= 48 && al_num <= 57)
	{
		return (1);
	}
	if (al_num >= 65 && al_num <= 90)
	{
		return (1);
	}
	if (al_num >= 97 && al_num <= 122)
	{
		return (1);
	}
	return (0);
}
