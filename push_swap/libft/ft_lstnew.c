/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:51:37 by amkrtumy          #+#    #+#             */
/*   Updated: 2023/02/17 18:55:59 by amkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_node	*ft_lstnew(int data)
{
	t_node	*target;

	target = (t_node *)malloc(sizeof(t_node));
	if (!target)
		return (NULL);
	(*target).data = data;
	target->next = NULL;
	target->prev = NULL;
	target->index = 0;
	return (target);
}
