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

#include "philosophers.h"

void	init_mutexes(t_philos *array_of_philos, pthread_mutex_t *forks,
			int num_of_philosophers)
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

t_philosopher	init_philo_1(int argc, char **argv)
{
	t_philosopher	philo;

	philo.time_to_die = ft_atoi(argv[2]);
	philo.time_to_eat = ft_atoi(argv[3]);
	philo.time_to_sleep = ft_atoi(argv[4]);
	philo.eat_count = ft_atoi(argv[5]);
	if (argc == 5)
		philo.eat_count = -1;
	return (philo);
}

void	init_philo_2(t_philos *philo, t_philosopher philosopher,
			pthread_mutex_t *forks, t_constants constants)
{
	philo->index = constants.i;
	philo->philosopher = philosopher;
	philo->forks = forks;
	philo->philo_num = constants.philo_num;
	philo->start_time = constants.start_time;
	philo->num_of_times_eaten = 0;
}

// millisecond = current time - given_time
int	get_time(struct timeval given_time)
{
	struct timeval	current_time;
	int				milliseconds;

	gettimeofday(&current_time, NULL);
	milliseconds = current_time.tv_sec * 1000LL + current_time.tv_usec / 1000
		- (given_time.tv_sec * 1000LL + given_time.tv_usec / 1000);
	return (milliseconds);
}
