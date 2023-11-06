/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:07:34 by amkrtumy          #+#    #+#             */
/*   Updated: 2023/11/06 19:07:37 by amkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_node **stack_a)
{
	t_node	*tmp;
	t_node	*last;

	if (ft_lstsize(*stack_a) > 1)
	{
		tmp = (*stack_a)->next;
		last = ft_lstlast(*stack_a);
		last->next = (*stack_a);
		(*stack_a)->next = NULL;
		(*stack_a)->prev = last;
		if (tmp)
			tmp->prev = NULL;
		(*stack_a) = tmp;
		ft_printf("ra\n");
	}
}

void	rb(t_node **stack_b)
{
	t_node	*tmp;
	t_node	*last;

	if (ft_lstsize(*stack_b) > 1)
	{
		tmp = (*stack_b)->next;
		last = ft_lstlast(*stack_b);
		last->next = (*stack_b);
		(*stack_b)->next = NULL;
		(*stack_b)->prev = last;
		if (tmp)
			tmp->prev = NULL;
		(*stack_b) = tmp;
		ft_printf("rb\n");
	}
}

void	rra(t_node **stack_a)
{
	t_node	*last;

	if (ft_lstsize(*stack_a) > 1)
	{
		last = ft_lstlast(*stack_a);
		if (last->prev)
			last->prev->next = NULL;
		(*stack_a)->prev = last;
		last->next = (*stack_a);
		last->prev = NULL;
		(*stack_a) = last;
		ft_printf("rra\n");
	}
}

void	rrb(t_node **stack_b)
{
	t_node	*last;

	if (ft_lstsize(*stack_b) > 1)
	{
		last = ft_lstlast(*stack_b);
		if (last->prev)
			last->prev->next = NULL;
		(*stack_b)->prev = last;
		last->next = (*stack_b);
		last->prev = NULL;
		(*stack_b) = last;
		ft_printf("rrb\n");
	}
}
