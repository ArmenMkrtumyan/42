/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:12:57 by amkrtumy          #+#    #+#             */
/*   Updated: 2023/12/28 16:13:09 by amkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_eaten(t_philos *array_of_philos, int num_of_philosophers,
		int *i, int *eaten_count)
{
	if (*i == num_of_philosophers)
	{
		if (*eaten_count == num_of_philosophers
			&& array_of_philos[*i - 1].philosopher.eat_count != -1)
			return (on_exit("All philosophers have eaten enough\n"));
		*i = 0;
		*eaten_count = 0;
	}
	return (1);
}

int	check_death(t_philos *array_of_philos, int num_of_philosophers,
		struct timeval start_time)
{
	int	i;
	int	eaten_count;

	i = 0;
	eaten_count = 0;
	while (i < num_of_philosophers)
	{
		pthread_mutex_lock(&(array_of_philos[i].last_time_mutex));
		if (get_time(start_time) - array_of_philos[i].last_time_eaten
			> array_of_philos[i].philosopher.time_to_die)
		{
			printf("philosopher N%d died\n", array_of_philos[i].index);
			break ;
		}
		if (array_of_philos[i].num_of_times_eaten
			>= array_of_philos[i].philosopher.eat_count)
			eaten_count += 1;
		pthread_mutex_unlock(&(array_of_philos[i].last_time_mutex));
		i ++;
		if (check_eaten(array_of_philos, num_of_philosophers,
				&i, &eaten_count) == 0)
			return (0);
	}
	return (0);
}
