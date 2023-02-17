/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:25:12 by amkrtumy          #+#    #+#             */
/*   Updated: 2023/02/17 18:14:18 by amkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	t_list	*start_node;

	if (!lst)
		return (NULL);
	start_node = ft_lstnew(f(lst->content));
	if (!start_node)
	{
		ft_lstclear(&start_node, del);
		return (NULL);
	}
	lst = lst->next;
	while (lst != NULL)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
		{
			ft_lstclear(&new_node, del);
			return (NULL);
		}
		lst = lst->next;
		ft_lstadd_back(&start_node, new_node);
	}
	return (start_node);
}
