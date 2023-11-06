/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:07:24 by amkrtumy          #+#    #+#             */
/*   Updated: 2023/11/06 19:07:26 by amkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **stack_a)
{
	t_node	*tmp;

	if (ft_lstsize(*stack_a) > 1)
	{
		tmp = (*stack_a)->next;
		(*stack_a)->next = tmp->next;
		(*stack_a)->prev = tmp;
		tmp->next = *stack_a;
		tmp->prev = NULL;
		*stack_a = tmp;
		ft_printf("sa\n");
	}
}

void	sb(t_node **stack_b)
{
	t_node	*tmp;

	if (ft_lstsize(*stack_b) > 1)
	{
		tmp = (*stack_b)->next;
		(*stack_b)->next = tmp->next;
		(*stack_b)->prev = tmp;
		tmp->next = *stack_b;
		tmp->prev = NULL;
		*stack_b = tmp;
		ft_printf("sb\n");
	}
}

void	pa(t_node **stack_a, t_node **stack_b)
{
	int	value;
	t_node	*first_element;
	int index;

	if ((*stack_b))
	{
		index = (*stack_b)->index;
		value = pop(stack_b);
		first_element = ft_lstnew(value);
		first_element->next = *stack_a;
		first_element->prev = NULL;
		first_element->index = index;
		*stack_a = first_element;
		ft_printf("pa\n");
	}
}

void	pb(t_node **stack_b, t_node **stack_a)
{
	int	value;
	t_node	*first_element;
	int	index;

	if ((*stack_a))
	{
		index = (*stack_a)->index;
		value = pop(stack_a);
		first_element = ft_lstnew(value);
		first_element->next = *stack_b;
		first_element->prev = NULL;
		first_element->index = index;
		*stack_b = first_element;
		ft_printf("pb\n");

	}
}

// sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.
// sb (swap b): Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.
// ss : sa and sb at the same time.
// pa (push a): Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.
// pb (push b): Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.
// ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.
// rb (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one.
// rr : ra and rb at the same time.
// pa (push a): Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.
// pb (push b): Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.
// rra (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one.
// rrb (reverse rotate b): Shift down all elements of stack b by 1.
// The last element becomes the first one.
// rrr : rra and rrb at the same time
