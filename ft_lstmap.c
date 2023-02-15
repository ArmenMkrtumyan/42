/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:25:12 by amkrtumy          #+#    #+#             */
/*   Updated: 2023/02/06 17:48:58 by amkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*new_node;
	t_list	*start_node;

	if (!lst)
		return (NULL);
	temp = lst;
	start_node = ft_lstnew(f(temp->content));
	if (!start_node)
	{
		ft_lstclear(&start_node, del);
		return (NULL);
	}
	while (temp != NULL)
	{
		temp = temp->next;
		new_node = ft_lstnew(f(temp->content));
		if (!new_node)
		{
			ft_lstclear(&new_node, del);
			return (NULL);
		}
		start_node->next = new_node;
	}
	return (start_node);
}
