/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:20:25 by amkrtumy          #+#    #+#             */
/*   Updated: 2023/11/07 17:20:46 by amkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_malloc(char *answer)
{
	if (!answer)
		on_exit("Malloc Error\n");
}

void	count_items(char *string, int *item_count)
{
	t_split_var	vars;

	vars.start = 0;
	vars.end = 0;
	vars.text = 0;
	*item_count = 0;
	while (string[vars.start])
	{
		if (!vars.text && (string[vars.start] > 32 && string[vars.start] < 127))
		{
			(*item_count)++;
			vars.text = 1;
		}
		if (vars.text && ((string[vars.start] > 8 && string[vars.start] < 12) \
			|| (string[vars.start] > 28 && string[vars.start] < 33)))
			vars.text = 0;
		vars.start ++;
	}
}

void	fill_answer(char **answer, char *str, t_split_var var, int index)
{
	while (str[var.end])
	{
		if ((var.text == 1) && ((str[var.end] > 8 && str[var.end] < 12) || \
			(str[var.end] > 28 && str[var.end] < 33)))
		{
			answer[index] = ft_substr(str, var.start, \
				var.end - var.start);
			check_malloc(answer[index]);
			index ++;
			var.text = 0;
		}
		else if ((var.text == 0) && (str[var.end] > 32 && str[var.end] < 127))
		{
			var.start = var.end;
			var.text = 1;
		}
		var.end ++;
		if (var.text == 1 && !str[var.end])
		{
			answer[index] = ft_substr(str, var.start, var.end - var.start);
			check_malloc(answer[index]);
			index ++;
		}
	}
	answer[index] = NULL;
}

char	**ft_split_boosted(char *string)
{
	int			item_count;
	char		**answer;
	int			index;
	t_split_var	vars;

	count_items(string, &item_count);
	answer = (char **)malloc((item_count + 1) * sizeof(char *));
	if (!answer)
		on_exit("Malloc Error\n");
	vars.start = 0;
	vars.text = 0;
	vars.end = 0;
	index = 0;
	fill_answer(answer, string, vars, index);
	return (answer);
}
