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

int	go_to_sleep(t_philos *pack, t_constants_2 const2)
{
	printf("%d ms N%d is sleeping\n", const2.current, pack->index);
	while (const2.t_passed - const2.current < pack->philosopher.time_to_sleep)
		const2.t_passed = get_time(pack->start_time);
	printf("%d ms N%d is thinking\n", const2.t_passed, pack->index);
	return (const2.t_passed);
}

int	go_to_eat(t_philos *pack)
{
	int	current;
	int	t_passed;

	t_passed = get_time(pack->start_time);
	printf("%d ms N%d has taken a fork\n", t_passed, pack->index);
	printf("%d ms N%d is eating\n", t_passed, pack->index);
	current = get_time(pack->start_time);
	while (t_passed - current < pack->philosopher.time_to_eat)
		t_passed = get_time(pack->start_time);
	return (t_passed);
}

void	*start_threads(void *packed)
{
	t_philos		*pack;
	t_constants_2	const2;

	pack = (t_philos *)packed;
	if (pack->index % 2 == 0)
		usleep(1500);
	while (1)
	{
		const2.t_passed = get_time(pack->start_time);
		const2.index = pack->index - 1 % pack->philo_num;
		if (const2.index < 0)
			const2.index = pack->philo_num - 1;
		pthread_mutex_lock(&(pack->forks[const2.index]));
		printf("%d ms N%d has taken a fork\n", const2.t_passed, pack->index);
		pthread_mutex_lock(&(pack->forks[pack->index + 1 % pack->philo_num]));
		const2.t_passed = go_to_eat(pack);
		pthread_mutex_unlock(&(pack->forks[const2.index]));
		pthread_mutex_unlock(&(pack->forks[pack->index + 1 % pack->philo_num]));
		pthread_mutex_lock(&(pack->last_time_mutex));
		assign_pack(pack, const2);
		pthread_mutex_unlock(&(pack->last_time_mutex));
		const2.current = get_time(pack->start_time);
		const2.t_passed = go_to_sleep(pack, const2);
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
