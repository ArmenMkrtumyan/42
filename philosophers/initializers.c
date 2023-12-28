/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 14:03:18 by amkrtumy          #+#    #+#             */
/*   Updated: 2023/12/28 14:03:20 by amkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philosophers.h"

void	init_mutexes(t_philos *array_of_philos, pthread_mutex_t *forks, int num_of_philosophers)
{
	int	i;

	i = -1;
	while (++i < num_of_philosophers)
	{
		array_of_philos[i].last_time_eaten = 0;
		pthread_mutex_init(&forks[i], NULL);
		pthread_mutex_init(&(array_of_philos[i].last_time_mutex), NULL);
	}
}

void	init_philo(t_philos *philo, t_philosopher philosopher, pthread_mutex_t *forks, t_constants constants)
{
	philo->index = constants.i;
	philo->philosopher = philosopher;
	philo->forks = forks;
	philo->num_of_philo = constants.num_of_philo;
	philo->start_time = constants.start_time;
}
