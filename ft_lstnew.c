/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:51:37 by amkrtumy          #+#    #+#             */
/*   Updated: 2023/02/06 16:52:02 by amkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*target;

	target = (t_list *)malloc(sizeof(t_list));
	if (!target)
		return (NULL);
	(*target).content = content;
	target->next = NULL;
	return (target);
}
