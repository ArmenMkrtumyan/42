/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:04:47 by amkrtumy          #+#    #+#             */
/*   Updated: 2023/11/01 17:04:50 by amkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_split_values
{
	int		start;
	int		end;
	int		text;
}			t_split_var;

#include "libft.h"
#include "ft_printf.h"

// MAIN FUNCTION

char	**ft_split_boosted(char *string);
void	on_exit(char* message);
void	create_a(t_node **stack_a, int argc, char **argv);

// BUTTERFLY
int		get_max_top(t_node *stack, int n);
int		get_max_bottom(t_node *stack, int n);
void	sort_a(t_node **stack_a, t_node **stack_b);

// CHECKERS
int		check_if_number(char *element);
char	**check_parsing(char *element);
int		check_min_max(char *string, char *critical_value);
void	check_duplicates(t_node *stack_a, int element);
void	check_if_sorted(t_node *stack_a);

// STACK FUNCTIONS
void	sa(t_node **stack_a);
void	sb(t_node **stack_b);
void	ss(t_node **stack_a, t_node **stack_b);
void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_a, t_node **stack_b);
int		pop(t_node **stack);
void	ra(t_node **stack_a);
void	rb(t_node **stack_b);
void	rr(t_node **stack_a, t_node **stack_b);
void	rra(t_node **stack_a);
void	rrb(t_node **stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);
void	sort_a(t_node **stack_a, t_node **stack_b);

// UTILS

int		has_index(t_node **stack_a);
void	assign_index(t_node **stack_a, int next_index);
void	assign_indeces(t_node **stack_a);

#endif
