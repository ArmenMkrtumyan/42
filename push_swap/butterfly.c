/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:32:26 by amkrtumy          #+#    #+#             */
/*   Updated: 2023/11/04 18:32:36 by amkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	sort_a(t_node **stack_a, t_node **stack_b)
{
	int	counter;
	t_node	*node;
	int	top;
	int	bottom;

	counter = 0;
	while (*stack_a)
	{
		if ((*stack_a)->data <= counter)
		{
			pb(stack_b, stack_a);
			rb(stack_b);
			counter ++;
		}
		else if ((*stack_a)->data <= counter + 1)
		{
			pb(stack_b, (stack_a));
			counter ++;
		}
		else
			ra(stack_a);
	}
	node = (*stack_b);
	while (node)
	{
		ft_printf("Data: %d\n", node->data);
		node = node->next;
	}
	ft_printf("-----------------------\n");
	while (*stack_b)
	{
		top = stack_b.data;
		bottom = ft_lstlast(stack_b)->data;

		
	}

}