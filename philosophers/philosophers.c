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

long long get_time()
{
	struct timeval te;
	long long milliseconds;

	gettimeofday(&te, NULL);
	milliseconds = te.tv_sec * 1000LL + te.tv_usec / 1000;
	return milliseconds;
}

void *initalizer(void *pack)
{
	t_fork_plus_philosopher* fork_philo;
	fork_philo = (t_fork_plus_philosopher *)pack;
	long long current;
	long long time_passed;

	if (fork_philo->philosopher.index % 2 == 0)
		usleep(1000);
	while (1)
	{
		time_passed = get_time();
		pthread_mutex_lock(&(fork_philo->forks[fork_philo->philosopher.index - 1 % fork_philo->num_of_philo]));
		printf("%lld N%d has taken a fork\n", time_passed, fork_philo->philosopher.index);
		time_passed = get_time();
		pthread_mutex_lock(&(fork_philo->forks[fork_philo->philosopher.index + 1 % fork_philo->num_of_philo]));
		printf("%lld N%d has taken a fork\n", time_passed, fork_philo->philosopher.index);
		printf("%lld N%d is eating\n", time_passed, fork_philo->philosopher.index);
		current = get_time();
		while (time_passed - current < fork_philo->philosopher.time_to_eat)
			time_passed = get_time();
		fork_philo->philosopher.last_time_eaten = time_passed;
		pthread_mutex_unlock(&(fork_philo->forks[fork_philo->philosopher.index - 1 % fork_philo->num_of_philo]));
		pthread_mutex_unlock(&(fork_philo->forks[fork_philo->philosopher.index + 1 % fork_philo->num_of_philo]));
		current = get_time();
		printf("%lld N%d is sleeping\n", current, fork_philo->philosopher.index);
		while (time_passed - current < fork_philo->philosopher.time_to_sleep)
			time_passed = get_time();
		printf("%lld N%d is thinkig\n", time_passed, fork_philo->philosopher.index);
	}
	pthread_exit(NULL);
}

t_philosopher get_values_from_argv(char *argv, int index)
{
	t_philosopher philo;

	philo.index = index;
	philo.time_to_die = ft_atoi(&argv[0]);
	philo.time_to_eat = ft_atoi(&argv[1]);
	philo.time_to_sleep = ft_atoi(&argv[2]);
	philo.eat_count = ft_atoi(&argv[3]);

	return (philo);
}

int main(int argc, char *argv[])
{

	int num_of_philosophers;
	pthread_t *array_of_philos;
	int i;
	// struct timeval te;
	// gettimeofday(&te, NULL); // get current time
	// long long current;
	t_philosopher philosopher;
	pthread_mutex_t *forks;
	t_fork_plus_philosopher combo;

	if (argc != 6 && argc != 5)
	{
		printf("Invalid number of arguments. Expected 4 or 5 arguments.\n");
		return 0;
	}
	if (argc == 5)
		philosopher.eat_count = -1;
	i = 1;
	while (i < argc)
	{
		if (check_parsing(argv[i]) == -1)
		{
			printf("Invalid argument. Expected a number.\n");
			return 0;
		}
		i++;
	}

	num_of_philosophers = ft_atoi(argv[1]);
	array_of_philos = malloc(sizeof(pthread_t) * num_of_philosophers);
	forks = malloc(sizeof(pthread_mutex_t) * num_of_philosophers);
	i = 0;
	while (i < num_of_philosophers)
	{
		philosopher = get_values_from_argv(*argv, i);
		combo.philosopher = philosopher;
		combo.forks = forks;
		combo.num_of_philo = num_of_philosophers;
		if (pthread_create(&array_of_philos[i], NULL, &initalizer, &combo) != 0)
			perror("Failed to created thread");
		i++;
	}
	// int num = 0;

	// gettimeofday(&te, NULL);
	// current = te.tv_sec * 1000LL + te.tv_usec / 1000;
	// while (1)
	// {
	// 	if (array_of_philos[num]->philosopher.last_time_eaten - current > array_of_philos[num]->philosopher.time_to_die)
	// 	{
	// 		printf("philosopher N%d died\n", array_of_philos[num]->philosopher.index);
	// 		break;
	// 	}
	// 	gettimeofday(&te, NULL);
	// 	current = te.tv_sec * 1000LL + te.tv_usec / 1000;
	// 	num++;
	// 	if (num == num_of_philosophers)
	// 		num = 0;
	// }
	return 0;
	// for (i = 0; i < 10; i++)
	// {
	// 	if (pthread_join(th[i], NULL) != 0)
	// 	{
	// 		perror("Failed to join thread");
	// 	}
	// }
	// return 0;
}
