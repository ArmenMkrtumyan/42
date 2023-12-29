/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 18:59:35 by amkrtumy          #+#    #+#             */
/*   Updated: 2023/12/26 18:59:38 by amkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	on_exit(char *message)
{
	printf("%s", message);
	return (0);
}

int	go_to_sleep(t_philos *pack, int current, int time_passed)
{
	printf("%d ms N%d is sleeping\n", current, pack->index);
	while (time_passed - current < pack->philosopher.time_to_sleep)
		time_passed = get_time(pack->start_time);
	printf("%d ms N%d is thinking\n", time_passed, pack->index);
	return (time_passed);
}

int	go_to_eat(t_philos *pack)
{
	int	current;
	int	time_passed;

	time_passed = get_time(pack->start_time);
	printf("%d ms N%d has taken a fork\n", time_passed, pack->index);
	printf("%d ms N%d is eating\n", time_passed, pack->index);
	current = get_time(pack->start_time);
	while (time_passed - current < pack->philosopher.time_to_eat)
		time_passed = get_time(pack->start_time);
	return (time_passed);
}

void	*start_threads(void *packed)
{
	t_philos	*pack;
	int			time_passed;
	int			current;

	pack = (t_philos *)packed;
	if (pack->index % 2 == 0)
		usleep(1500);
	while (1)
	{
		time_passed = get_time(pack->start_time);
		pthread_mutex_lock(&(pack->forks[pack->index - 1 % pack->philo_num]));
		printf("%d ms N%d has taken a fork\n", time_passed, pack->index);
		pthread_mutex_lock(&(pack->forks[pack->index + 1 % pack->philo_num]));
		time_passed = go_to_eat(pack);
		pthread_mutex_unlock(&(pack->forks[pack->index - 1 % pack->philo_num]));
		pthread_mutex_unlock(&(pack->forks[pack->index + 1 % pack->philo_num]));
		pthread_mutex_lock(&(pack->last_time_mutex));
		pack->num_of_times_eaten++;
		pack->last_time_eaten = time_passed;
		pthread_mutex_unlock(&(pack->last_time_mutex));
		current = get_time(pack->start_time);
		time_passed = go_to_sleep(pack, current, time_passed);
	}
	return (NULL);
}

// int init_thread(t_philos *array_of_philos)
// {
// 	if (pthread_create(&(array_of_philos->thread_id), NULL,
// 			start_threads, array_of_philos) != 0)
// 	{
// 		perror("Failed to create thread");
// 		return (0);
// 	}

// 	return (1);
// }

int	main(int argc, char *argv[])
{
	t_constants		constants;
	t_philosopher	philosopher;
	pthread_mutex_t	*forks;
	t_philos		*array_of_philos;

	gettimeofday(&constants.start_time, NULL);
	if (!check_parsing_stuff(argc, argv))
		return (0);
	constants.philo_num = ft_atoi(argv[1]);
	array_of_philos = malloc(sizeof(t_philos) * constants.philo_num);
	forks = malloc(sizeof(pthread_mutex_t) * constants.philo_num);
	init_mutexes(array_of_philos, forks, constants.philo_num);
	constants.i = 0;
	while (constants.i < constants.philo_num)
	{
		philosopher = init_philo_1(argc, argv);
		init_philo_2(&array_of_philos[constants.i], philosopher,
			forks, constants);
		if (init_thread(&array_of_philos[constants.i]) == 0)
			return (0);
		constants.i++;
	}
	return (check_death(array_of_philos, constants.philo_num,
			constants.start_time));
}
// for (i = 0; i < 10; i++)
// {
// 	if (pthread_join(array_of_philos[i], NULL) != 0)
// 	{
// 		perror("Failed to join thread");
// 	}
// }
