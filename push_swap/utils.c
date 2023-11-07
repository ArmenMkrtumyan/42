/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:08:54 by amkrtumy          #+#    #+#             */
/*   Updated: 2023/11/06 19:09:07 by amkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_index(t_node **stack_a)
{
	t_node	*tmp;

	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->index == -1)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	assign_index(t_node **stack_a, int next_index)
{
	int		min;
	t_node	*tmp;

	tmp = *stack_a;
	min = INT_MAX;
	while (tmp)
	{
		if (tmp->data <= min && tmp->index == -1)
			min = tmp->data;
		tmp = tmp->next;
	}
	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->data == min)
			tmp->index = next_index;
		tmp = tmp->next;
	}
}

void	assign_indeces(t_node **stack_a)
{
	int	next_index;

	next_index = 0;
	while (!has_index(stack_a))
	{
		assign_index(stack_a, next_index);
		next_index ++;
	}
}

void	up_or_down(int min_index, int min, t_node **stack_a)
{
	t_node	*tmp;

	if (min_index == 1)
	{
		tmp = *stack_a;
		while (tmp->data != min)
		{
			ra(stack_a);
			tmp = *stack_a;
		}
	}
	if (min_index == 2)
	{
		tmp = ft_lstlast(*stack_a);
		while (tmp->data != min)
		{
			rra(stack_a);
			tmp = ft_lstlast(*stack_a);
		}
		rra(stack_a);
	}
}

int	get_min(t_node *stack, int lst_len, int *dummy)
{
	int	min;
	int	counter;

	min = stack->data;
	counter = 0;
	while (stack)
	{
		if (stack->data < min)
		{
			min = stack->data;
			if (counter < lst_len / 2)
				*dummy = 1;
			else
				*dummy = 2;
		}
		stack = stack->next;
		counter ++;
	}
	return (min);
}
