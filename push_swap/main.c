/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:56:42 by amkrtumy          #+#    #+#             */
/*   Updated: 2023/11/01 16:56:44 by amkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	on_exit(char *message)
{
	int	len;

	len = ft_strlen(message);
	write(2, message, len);
	exit(1);
}

void	create_a(t_node **stack_a, int argc, char **argv)
{
	int		argument;
	char	**answer;
	int		element;
	t_node	*node;

	argument = 0;
	while (++argument < argc)
	{
		element = -1;
		answer = check_parsing(argv[argument]);
		while (answer[++element])
		{
			node = ft_lstnew(ft_atoi(answer[element]));
			if (!node)
				on_exit("Couldn't allocate element\n");
			check_duplicates(*stack_a, ft_atoi(answer[element]));
			ft_lstadd_back(stack_a, node);
		}
		element = 0;
		while (answer[element])
			free(answer[element++]);
		free(answer);
	}
	assign_indeces(stack_a);
}

void	sort_three(t_node **stack)
{
	int		max;
	t_node	*tmp;
	int		curr_index;

	max = get_max_top(*stack, 4);
	tmp = *stack;
	curr_index = 0;
	while (tmp)
	{
		if (tmp->data == max && curr_index == 0)
			ra(stack);
		if (tmp->data == max && curr_index == 1)
		{
			ra(stack);
			ra(stack);
		}
		if ((tmp->data == max && curr_index == 0) \
			|| (tmp->data == max && curr_index == 1))
			break ;
		tmp = tmp->next;
		curr_index ++;
	}
	if ((*stack)->data > (*stack)->next->data)
		sa(stack);
}

void	fast_sort_a(t_node **stack_a, t_node **stack_b)
{
	int		min_index;
	int		min;
	int		len_a;

	min_index = 0;
	len_a = ft_lstsize(*stack_a);
	if (len_a < 4)
		sort_three(stack_a);
	else
	{
		while (len_a != 3)
		{
			min = get_min(*stack_a, len_a, &min_index);
			up_or_down(min_index, min, stack_a);
			pb(stack_b, stack_a);
			len_a --;
		}
		sort_three(stack_a);
		while (*stack_b)
			pa(stack_a, stack_b);
	}
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		stack_len;

	if (argc <= 1)
		on_exit("No stack A received\n");
	stack_a = NULL;
	stack_b = NULL;
	create_a(&stack_a, argc, argv);
	stack_len = ft_lstsize(stack_a);
	check_if_sorted(stack_a);
	if (!stack_a)
		on_exit("No stack A received\n");
	if (stack_len == 2)
		sa(&stack_a);
	else if (stack_len <= 12)
		fast_sort_a(&stack_a, &stack_b);
	else
		sort_a(&stack_a, &stack_b);
}
// ft_printf("\n\n\n\n\nAFTER\n");

// t_node	*node;
// node = stack_a;
// while (node)
// {
// 	ft_printf("Data: %d Index: %d \n", node->data, node->index);
// 	node = node->next;
// }

// SA/SB TEST
// sa(&stack_a);
// ft_printf("\n\nAfter SA\n\n");
// node = stack_a;
// while (node)
// {
// 	ft_printf("Data: %d\n", node->data);
// 	node = node->next;
// }

// PA/PB TEST
// pa(&stack_a, &stack_b);
// ft_printf("\n\nMoving first element of b to a\n\n");
// ft_printf("\n\nStack A\n\n");
// node = stack_a;
// while (node)
// {
// 	ft_printf("Data: %d\n", node->data);
// 	node = node->next;
// }
// printf("-----------------------\n");
// ft_printf("\n\nStack B\n\n");
// node = stack_b;
// while (node)
// {
// 	ft_printf("Data: %d\n", node->data);
// 	node = node->next;
// }

// RA/RB TEST
// ft_printf("\n\nMoving first element of a to the end of a\n\n");
// ra(&stack_a);
// ft_printf("\n\nStack A\n\n");
// node = stack_a;
// while (node)
// {
// 	ft_printf("Data: %d\n", node->data);
// 	node = node->next;
// }
// printf("-----------------------\n");

// RRA/RRB TEST
// ft_printf("\n\nMoving last element of a to the beginning of a\n\n");
// rra(&stack_a);
// ft_printf("\n\nStack A\n\n");
// node = stack_a;
// while (node)
// {
// 	ft_printf("Data: %d\n", node->data);
// 	node = node->next;
// }

// ft_printf("-----------------------\n");
// ft_printf("\n\nReverse printing A\n\n");
// node = ft_lstlast(stack_a);
// while (node)
// {
// 	ft_printf("Data: %d\n", node->data);
// 	node = node->prev;
// }
// ft_printf("\n\nReverse printing B\n\n");
// node = ft_lstlast(stack_b);
// while (node)
// {
// 	ft_printf("Data: %d\n", node->data);
// 	node = node->prev;
// }
