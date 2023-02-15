/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:09:07 by amkrtumy          #+#    #+#             */
/*   Updated: 2023/01/18 18:09:09 by amkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(char letter)
{
	if ((letter > 64 && letter < 91) || (letter > 96 && letter < 123))
	{
		return (1);
	}
	return (0);
}
