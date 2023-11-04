/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:43:15 by amkrtumy          #+#    #+#             */
/*   Updated: 2023/02/06 17:43:23 by amkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_node	*ft_lstlast(t_node *lst)
{
	t_node	*temp;

	if (!lst)
		return (0);
	temp = lst;
	while (temp->next)
	{
		temp = temp->next;
	}
	return (temp);
}
