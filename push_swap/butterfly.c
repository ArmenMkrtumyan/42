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

int	get_max_top(t_node *stack, int n)
{
	int	max;
	int	counter;

	max = stack->data;
	counter = 0;
	while (stack && counter < n)
	{
		if (stack->data > max)
			max = stack->data;
		stack = stack->next;
		counter ++;
	}
	return (max);
}

int	get_max_bottom(t_node *stack, int n)
{
	int		max;
	int		counter;
	t_node	*tmp;

	tmp = ft_lstlast(stack);
	max = ft_lstlast(stack)->data;
	counter = 0;
	while (tmp && counter < n)
	{
		if (tmp->data > max)
			max = tmp->data;
		tmp = tmp->prev;
		counter ++;
	}
	return (max);
}

void	from_a_to_b(t_node **stack_a, t_node **stack_b, int n)
{
	int	counter;

	counter = 0;
	while (*stack_a)
	{
		if ((*stack_a)->index <= counter)
		{
			pb(stack_b, stack_a);
			rb(stack_b);
			counter ++;
		}
		else if ((*stack_a)->index <= counter + n)
		{
			pb(stack_b, stack_a);
			counter ++;
		}
		else
			ra(stack_a);
	}
}

void	from_b_to_a(t_node **stack_a, t_node **stack_b, int n)
{
	int	top;
	int	bottom;

	while (*stack_b)
	{
		top = get_max_top(*stack_b, n);
		bottom = get_max_bottom(*stack_b, n);
		if (top >= bottom)
		{
			while ((*stack_b)->data != top)
				rb(stack_b);
			pa(stack_a, stack_b);
		}
		else if (top < bottom)
		{
			while ((*stack_b)->data != bottom)
				rrb(stack_b);
			pa(stack_a, stack_b);
		}
		else
		{
			rrb(stack_b);
			pa(stack_a, stack_b);
		}
	}
}

void	sort_a(t_node **stack_a, t_node **stack_b)
{
	int	n;

	n = ft_lstsize(*stack_a) * 0.0375 + 11.25;
	from_a_to_b(stack_a, stack_b, n);
	from_b_to_a(stack_a, stack_b, n);
}
