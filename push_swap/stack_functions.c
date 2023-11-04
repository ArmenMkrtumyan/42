/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:38:51 by amkrtumy          #+#    #+#             */
/*   Updated: 2023/11/04 16:38:54 by amkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.
// sb (swap b): Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.
// ss : sa and sb at the same time.

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
	}
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

// pa (push a): Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.
// pb (push b): Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.

int	pop(t_node **stack)
{
	t_node	*tmp;
	int		value;

	tmp = (*stack);
	*stack = (*stack)->next;
	if (*stack)
		(*stack)->prev = NULL;
	value = tmp->data;
	free(tmp);
	return (value);
}

void	pa(t_node **stack_a, t_node **stack_b)
{
	int	value;
	t_node	*first_element;

	if ((*stack_b))
	{
		value = pop(stack_b);
		first_element = ft_lstnew(value);
		first_element->next = *stack_a;
		first_element->prev = NULL;
		*stack_a = first_element;
	}
}

void	pb(t_node **stack_b, t_node **stack_a)
{
	int	value;
	t_node	*first_element;

	if ((*stack_a))
	{
		value = pop(stack_a);
		first_element = ft_lstnew(value);
		first_element->next = *stack_b;
		first_element->prev = NULL;
		*stack_b = first_element;
	}
}

// ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.
// rb (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one.
// rr : ra and rb at the same time.

void	ra(t_node **stack_a)
{
	t_node	*tmp;
	t_node	*last;

	tmp = (*stack_a)->next;
	last = ft_lstlast(*stack_a);
	last->next = (*stack_a);
	(*stack_a)->next = NULL;
	(*stack_a)->prev = last;
	tmp->prev = NULL;
	(*stack_a) = tmp;
}

void	rb(t_node **stack_b)
{
	t_node	*tmp;
	t_node	*last;

	tmp = (*stack_b)->next;
	last = ft_lstlast(*stack_b);
	last->next = (*stack_b);
	(*stack_b)->next = NULL;
	(*stack_b)->prev = last;
	tmp->prev = NULL;
	(*stack_b) = tmp;
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}

// rra (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one.
// rrb (reverse rotate b): Shift down all elements of stack b by 1.
// The last element becomes the first one.
// rrr : rra and rrb at the same time

void	rra(t_node **stack_a)
{
	t_node	*last;

	last = ft_lstlast(*stack_a);
	last->prev->next = NULL;
	(*stack_a)->prev = last;
	last->next = (*stack_a);
	last->prev = NULL;
	(*stack_a) = last;
}

void	rrb(t_node **stack_b)
{
	t_node	*last;

	last = ft_lstlast(*stack_b);
	last->prev->next = NULL;
	(*stack_b)->prev = last;
	last->next = (*stack_b);
	last->prev = NULL;
	(*stack_b) = last;
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
