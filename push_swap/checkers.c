/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:11:06 by amkrtumy          #+#    #+#             */
/*   Updated: 2023/11/06 19:11:20 by amkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_number(char *element)
{
	int	i;
	int	minus_count;

	minus_count = 0;
	i = -1;
	if ((element[0] == '0' && ft_strlen(element) != 1))
		on_exit("Nobody writes numbers like that\n");
	if (element[0] == '-' && ft_strlen(element) == 1)
		on_exit("Minus is not a number\n");
	if (ft_strlen(element) == 2 && element[0] == '-' && element[1] == '0')
		on_exit("Nobody writes numbers like that\n");
	while (element[++i])
	{
		if (element[i] == 45)
			minus_count += 1;
		if (element[i] == 45 && i != 0)
			on_exit("It's not okay to have a - sign in the middle of a number\n");
		else if (element[i] != 45 && (element[i] < 48 || element[i] > 57))
			on_exit("Inputs must be all numbers\n");
	}
	if (minus_count > 1)
		on_exit("It's not okay to have more than one - sign\n");
	return (minus_count != 1);
}

char	**check_parsing(char *element)
{
	int	sign;
	char	**answer;
	int i;

	answer = ft_split_boosted(element);
	i = -1;
	while (answer[++i])
	{
		sign = check_if_number(answer[i]);
		if (sign && (check_min_max(answer[i], "2147483647") == -1))
			on_exit("One of the numbers is greater than INT_MAX\n");
		else if(!sign && check_min_max(&answer[i][1], "2147483648") == -1)
			on_exit("One of the numbers is smaller than INT_MIN\n");
	}
	return (answer);
}

int	check_min_max(char *string, char *critical_value)
{
	size_t	k;
	size_t	str_len;

	str_len = ft_strlen(string);
	if (ft_strlen(string) > ft_strlen(critical_value))
		return (-1);
	if (ft_strlen(string) < ft_strlen(critical_value))
		return (1);
	k = -1;
	while (++k < str_len)
	{
		if (string[k] > critical_value[k])
			return (-1);
	}
	return (1);
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

void	check_if_sorted(t_node *stack_a)
{
	int	index;

	index = 0;
	while (stack_a)
	{
		if (stack_a->index != index)
			return ;
		index ++;
		stack_a = stack_a->next;
	}
	on_exit("Stack is already sorted\n");
}