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
	int	max;
	int	counter;
	t_node *tmp;

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

void	sort_a(t_node **stack_a, t_node **stack_b)
{
	int	counter;
	int	top;
	int	bottom;
	// int	len;
	int n;

	counter = 0;
	// t_node * node;

	// while (node)
	// {
	// 	ft_printf("Data: %d Index: %d \n", node->data, node->index);
	// 	node = node->next;
	// }
	n = ft_lstsize(*stack_a) * 0.0375 + 11.25;
	//n = 30;
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
	// ft_printf("\n\n\n\n\nStack B\n");
	// node = *stack_b;
	// while (node)
	// {
	// 	ft_printf("Data: %d Index: %d \n", node->data, node->index);
	// 	node = node->next;
	// }

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