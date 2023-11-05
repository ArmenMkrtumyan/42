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

// void	ft_split_boosted(char *string)
// {
// 	int	start;
// 	int	end;
// 	int	item_count;
// 	int	on_text;

// 	start = 0;
// 	end = 0;
// 	item_count = 0;]
// 	on_text = 0;
// 	while (string[start])
// 	{
// 		if (string[start] == 45)

// 		if (!on_text && ((string[start] > 47 && string[start] < 58)))
// 		{
// 			item_count ++;
// 			on_text = 1;
// 		}
// 		if (on_text && ((string[start] > 8 && string[start] < 12) || (string[start] > 28 && string[start] < 33)))
// 			on_text = 0;
// 		start ++;
// 	}
// 	ft_printf("\nCounted items: %d\n", item_count);

// }

// void	check_argument(char *string)
// {
// 	int	i;

// 	//ft_split_boosted(string);

// 	i = -1;
// 	// while (answer[++i])
// 	// 	ft_printf("\nElement %d: %s\n", i, answer[i]);
// }

int	check_if_number(char *element)
{
	int	i;
	int	minus_count;

	minus_count = 0;
	i = 0;
	if (element[0] == '0' && ft_strlen(element) != 1)
		on_exit("Nobody writes numbers like that\n");
	if (element[0] == '-' && ft_strlen(element) == 1)
		on_exit("Minus is not a number\n");

	while (element[i])
	{
		if (element[i] == 45)
			minus_count += 1;
		else if (element[i] != 45 && (element[i] < 48 || element[i] > 57))
			on_exit("Inputs must be all numbers\n");
		i++;
	}
	if (minus_count > 1)
		on_exit("It's not okay to have more than one - sign\n");
	return (minus_count != 1);
}

int	check_parsing(char *element)
{
	int	sign;

	// check_argument(element);

	sign = check_if_number(element);
	if (sign && (check_min_max(element, "2147483647") == -1))
		on_exit("One of the numbers is greater than INT_MAX\n");
	else if(!sign && check_min_max(&element[1], "2147483648") == -1)
		on_exit("One of the numbers is smaller than INT_MIN\n");


	return (ft_atoi(element));
}

void	on_exit(char* message)
{
	ft_printf(message);
	exit(1);
}

void	check_duplicates(t_node *stack_a, int element)
{
	while (stack_a)
	{
		if (stack_a->data == element)
			on_exit("You have duplicates\n");
		stack_a = stack_a->next;
	}
}

int	has_index(t_node **stack_a)
{
	t_node	*tmp;

	tmp = *stack_a;
	while(tmp)
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

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	int		element;
	int		argument;
	t_node	*node;
	t_node	*stack_b;
	int		next_index;

	if (argc <= 1)
		on_exit("No stack A received\n");
	argument = 0;
	stack_a = NULL;
	while (++argument < argc)
	{
		element = check_parsing(argv[argument]);
		node = ft_lstnew(element);
		if (!node)
			on_exit("Couldn't allocate element\n");
		check_duplicates(stack_a, element);
		ft_lstadd_back(&stack_a, node);
	}
	ft_printf("\n\nStack A\n\n");
	stack_b = NULL;
	next_index = 0;
	while(!has_index(&stack_a))
	{
		assign_index(&stack_a, next_index);
		next_index ++;
	}
	// print indeces
	// node = stack_a;
	// while (node)
	// {
	// 	ft_printf("Data: %d Index: %d \n", node->data, node->index);
	// 	node = node->next;
	// }

	sort_a(&stack_a, &stack_b);

	// //Creating random stack_b

	// ft_printf("\n\nGenerating random stack _b\n\n");
	// stack_b = NULL;
	// node = stack_a;
	// while (node)
	// {
	// 	ft_lstadd_back(&stack_b, ft_lstnew((node->data) + 5));
	// 	node = node->next;
	// }
	// node = stack_b;
	// while (node)
	// {
	// 	ft_printf("Data: %d\n", node->data);
	// 	node = node->next;
	// }
	// ft_printf("-----------------------\n");

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

}
