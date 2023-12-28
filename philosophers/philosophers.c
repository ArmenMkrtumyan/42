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
	return (-1);
}

// millisecond = current time - given_time
int	get_time(struct timeval given_time)
{
	struct timeval current_time;
	int milliseconds;
	gettimeofday(&current_time, NULL);
	milliseconds = current_time.tv_sec * 1000LL + current_time.tv_usec / 1000
		- (given_time.tv_sec * 1000LL + given_time.tv_usec / 1000);
	return milliseconds;
}

void	*initalizer(void *packed)
{
	t_philos	*pack;
	int			current;
	int			time_passed;

	pack = (t_philos *)packed;
	if (pack->index % 2 == 0)
		usleep(1500);
	while (1)
	{
		time_passed = get_time(pack->start_time);
		pthread_mutex_lock(&(pack->forks[pack->index - 1 % pack->num_of_philo]));
		printf("%d ms N%d has taken a fork\n", time_passed, pack->index);
		time_passed = get_time(pack->start_time);
		pthread_mutex_lock(&(pack->forks[pack->index + 1 % pack->num_of_philo]));
		printf("%d ms N%d has taken a fork\n", time_passed, pack->index);
		printf("%d ms N%d is eating\n", time_passed, pack->index);
		current = get_time(pack->start_time);
		while (time_passed - current < pack->philosopher.time_to_eat)
			time_passed = get_time(pack->start_time);
		pthread_mutex_unlock(&(pack->forks[pack->index - 1 % pack->num_of_philo]));
		pthread_mutex_unlock(&(pack->forks[pack->index + 1 % pack->num_of_philo]));
		pthread_mutex_lock(&(pack->last_time_mutex));
		pack->last_time_eaten = time_passed;
		pthread_mutex_unlock(&(pack->last_time_mutex));
		current = get_time(pack->start_time);
		printf("%d ms N%d is sleeping\n", current, pack->index);
		while (time_passed - current < pack->philosopher.time_to_sleep)
			time_passed = get_time(pack->start_time);
		printf("%d ms N%d is thinking\n", time_passed, pack->index);
	}
	return (NULL);
}

t_philosopher	get_values_from_argv(char **argv)
{
	t_philosopher	philo;

	philo.time_to_die = ft_atoi(argv[2]);
	philo.time_to_eat = ft_atoi(argv[3]);
	philo.time_to_sleep = ft_atoi(argv[4]);
	philo.eat_count = ft_atoi(argv[5]);
	return (philo);
}

int main(int argc, char *argv[])
{
	t_constants		constants;
	t_philosopher	philosopher;
	pthread_mutex_t	*forks;
	t_philos		*array_of_philos;

	gettimeofday(&constants.start_time, NULL);
	if (check_parsing_stuff(argc, argv) == -1)
		return (0);
	if (argc == 5)
		philosopher.eat_count = -1;
	constants.num_of_philo = ft_atoi(argv[1]);
	array_of_philos = malloc(sizeof(t_philos) * constants.num_of_philo);
	forks = malloc(sizeof(pthread_mutex_t) * constants.num_of_philo);
	init_mutexes(array_of_philos, forks, constants.num_of_philo);
	constants.i = 0;
	while (constants.i < constants.num_of_philo)
	{
		philosopher = get_values_from_argv(argv);
		init_philo(&array_of_philos[constants.i], philosopher, forks, constants);
		if (pthread_create(&array_of_philos[constants.i].thread_id, NULL, &initalizer, &array_of_philos[constants.i]) != 0)
			perror("Failed to created thread");
		constants.i++;
	}
	return (check_death(array_of_philos, constants.num_of_philo, constants.start_time));
}
// for (i = 0; i < 10; i++)
// {
// 	if (pthread_join(array_of_philos[i], NULL) != 0)
// 	{
// 		perror("Failed to join thread");
// 	}
// }
