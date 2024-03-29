/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:07:34 by amkrtumy          #+#    #+#             */
/*   Updated: 2023/02/06 17:07:49 by amkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_node **lst)
{
	t_node	*temp;

	temp = *lst;
	if (!(*lst))
		return ;
	while (temp != NULL)
	{
		temp = (*lst)->next;
		free(*lst);
		*lst = NULL;
		*lst = temp;
	}
	lst = NULL;
}
