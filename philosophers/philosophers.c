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

int get_time(struct timeval start_time)
{
	struct timeval te;
	int milliseconds;
	gettimeofday(&te, NULL);
	milliseconds = te.tv_sec * 1000LL + te.tv_usec / 1000
		- (start_time.tv_sec * 1000LL + start_time.tv_usec / 1000);
	return milliseconds;
}

void *initalizer(void *packed)
{
	t_philos	*pack;
	int			current;
	int			time_passed;

	pack = (t_philos *)packed;
	if (pack->index % 2 == 0)
		usleep(1500);
	while (1)
	{
		int a = 0;
		time_passed = get_time(pack->start_time);
		if ((a = pthread_mutex_lock(&(pack->forks[pack->index - 1 % pack->num_of_philo])) != 0))
			strerror(a);
		// printf("The address %p is locked\n", &(pack->forks[pack->index - 1 % pack->num_of_philo]));
		printf("%d ms N%d has taken a fork\n", time_passed, pack->index);
		time_passed = get_time(pack->start_time);
		pthread_mutex_lock(&(pack->forks[pack->index + 1 % pack->num_of_philo]));
		// printf("The address %p is locked\n", &(pack->forks[pack->index + 1 % pack->num_of_philo]));
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
		// printf("The address %p is unlocked\n", &(pack->forks[pack->index - 1 % pack->num_of_philo]));
		// printf("The address %p is unlocked\n", &(pack->forks[pack->index + 1 % pack->num_of_philo]));
		current = get_time(pack->start_time);
		printf("%d ms N%d is sleeping\n", current, pack->index);
		while (time_passed - current < pack->philosopher.time_to_sleep)
			time_passed = get_time(pack->start_time);
		printf("%d ms N%d is thinking\n", time_passed, pack->index);
	}

	return (NULL);
}

t_philosopher get_values_from_argv(char **argv)
{
	t_philosopher	philo;

	// philo.index = index;
	philo.time_to_die = ft_atoi(argv[2]);
	philo.time_to_eat = ft_atoi(argv[3]);
	philo.time_to_sleep = ft_atoi(argv[4]);
	philo.eat_count = ft_atoi(argv[5]);
	// printf("Creating a philo with index %d\n time_to_die: %d\n time_to_eat: %d\n time_to_sleep: %d\n eat_count: %d\n", philo.index, philo.time_to_die, philo.time_to_eat, philo.time_to_sleep, philo.eat_count);
	return (philo);
}

int	on_exit(char *message)
{
	printf("%s", message);
	return (0);
}

int main(int argc, char *argv[])
{
	int				num_of_philosophers;
	int				i;
	t_philosopher	philosopher;
	pthread_mutex_t	*forks;
	int				start_time;
	t_philos		*array_of_philos;

	struct timeval	te;
	struct timeval current;

	// struct timeval te;
	gettimeofday(&te, NULL);// get current time

	start_time = get_time(te);
	if (argc != 6 && argc != 5)
		return (on_exit("Invalid number of arguments. Expected 4 or 5 arguments.\n"));
	if (argc == 5)
		philosopher.eat_count = -1;
	i = 1;
	while (i < argc)
	{
		if (check_parsing(argv[i]) == -1)
			on_exit("Invalid argument.\n");
		i++;
	}
	num_of_philosophers = ft_atoi(argv[1]);
	array_of_philos = malloc(sizeof(t_philos) * num_of_philosophers);
	forks = malloc(sizeof(pthread_mutex_t) * num_of_philosophers);
	i = -1;
	while (++i < num_of_philosophers)
	{
		array_of_philos[i].last_time_eaten = 0;
		pthread_mutex_init(&forks[i], NULL);
		pthread_mutex_init(&(array_of_philos[i].last_time_mutex), NULL);
	}
	i = 0;
	// printf("%d\n", array_of_philos[0].last_time_eaten);
	while (i < num_of_philosophers)
	{
		philosopher = get_values_from_argv(argv);
		array_of_philos[i].philosopher = philosopher;
		array_of_philos[i].forks = forks;
		array_of_philos[i].num_of_philo = num_of_philosophers;
		array_of_philos[i].start_time = te;
		array_of_philos[i].index = i;
		if (pthread_create(&array_of_philos[i].thread_id, NULL, &initalizer, &array_of_philos[i]) != 0)
			perror("Failed to created thread");
		i++;
	}
	int num = 0;
	while (1)
	{
		// gettimeofday(&current, NULL);
		// current = get_time(te.tv_sec * 1000LL + te.tv_usec / 1000);
		pthread_mutex_lock(&(array_of_philos[num].last_time_mutex));
		// printf("The last time eaten by %d\n", get_time(te) - array_of_philos[num].last_time_eaten);
		if (get_time(te) - array_of_philos[num].last_time_eaten > array_of_philos[num].philosopher.time_to_die)
		{
			printf("philosopher N%d died\n", array_of_philos[num].index);
			break;
		}
		pthread_mutex_unlock(&(array_of_philos[num].last_time_mutex));
		num++;
		if (num == num_of_philosophers)
			num = 0;
	}
	return 0;

	// for (i = 0; i < 10; i++)
	// {
	// 	if (pthread_join(array_of_philos[i], NULL) != 0)
	// 	{
	// 		perror("Failed to join thread");
	// 	}
	// }
}
