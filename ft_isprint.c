/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:04:55 by amkrtumy          #+#    #+#             */
/*   Updated: 2023/01/18 18:05:00 by amkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(char printable)
{
	if (printable >= 32 && printable <= 126)
	{
		return (1);
	}
	return (0);
}
