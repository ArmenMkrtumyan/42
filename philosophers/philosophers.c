#include "philosophers.h"

void *initalizer(void *pack)
{
	t_fork_plus_philosopher fork_philo;
	fork_philo = *(t_fork_plus_philosopher *)pack;
	struct timeval te;
	long long current;
	long long time_passed;
	if (fork_philo.philosopher.index % 2 == 0)
		usleep(1000);
	while (1)
	{
		pthread_mutex_lock(fork_philo.forks[fork_philo.index - 1 % fork_philo.num_of_philo]);
		printf("philosopher N%d has taken a fork\n", fork_philo.philosopher.index);
		pthread_mutex_lock(fork_philo.forks[fork_philo.index + 1 % fork_philo.num_of_philo]);
		printf("philosopher N%d has taken a fork\n", fork_philo.philosopher.index);
		printf("philosopher N%d is eating\n", fork_philo.philosopher.index);
		gettimeofday(&te, NULL);
		current = te.tv_sec * 1000LL + te.tv_usec / 1000;
		while (time_passed - current < fork_philo.philosopher.time_to_eat)
		{
			gettimeofday(&te, NULL);
			time_passed = te.tv_sec * 1000LL + te.tv_usec / 1000;
		}
		fork_philo.philosopher.last_time_eaten = time_passed;
		pthread_mutex_unlock(fork_philo.forks[fork_philo.index - 1 % fork_philo.num_of_philo]);
		pthread_mutex_unlock(fork_philo.forks[fork_philo.index + 1 % fork_philo.num_of_philo])
			gettimeofday(&te, NULL);
		current = te.tv_sec * 1000LL + te.tv_usec / 1000;
		printf("philosopher N%d is sleeping\n", fork_philo.philosopher.index);
		while (time_passed - current < fork_philo.philosopher.time_to_sleep)
		{
			gettimeofday(&te, NULL);
			time_passed = te.tv_sec * 1000LL + te.tv_usec / 1000;
		}
		printf("philosopher N%d is thinkig\n", fork_philo.philosopher.index);
	}

	pthread_exit(NULL);
}

t_philosopher get_values_from_argv(char *argv, int index)
{
	t_philosopher philo;

	philo.index = index;
	philo.time_to_die = atoi(argv[0]);
	philo.time_to_eat = atoi(argv[1]);
	philo.time_to_sleep = atoi(argv[2]);
	philo.eat_count = atoi(argv[3]);

	return (philo);
}

int main(int argc, char *argv[])
{

	int num_of_philosophers;
	pthread_t *array_of_philos;
	int i;
	struct timeval te;
	gettimeofday(&te, NULL); // get current time
	long long current;
	t_philosopher philosopher;
	pthread_mutex_t *forks;
	t_fork_plus_philosopher combo;

	if (argc != 5 && argc != 4)
	{
		printf("Invalid number of arguments. Expected 5 arguments.\n");
		return 0;
	}
	if (argc == 4)
	{
		philosopher.eat_count = -1;
	}

	// for (int i = 1; i < argc; i++) {
	//     printf("Input %d: %s\n", i, argv[i]);
	// }

	num_of_philosophers = atoi(argv[1]);
	array_of_philos = malloc(sizeof(pthread_t) * num_of_philosophers);
	forks = malloc(sizeof(pthread_mutex_t) * num_of_philosophers);
	i = 0;
	while (i < num_of_philosophers)
	{
		philosopher = get_values_from_argv(argv, i);
		combo.philosopher = philosopher;
		combo.forks = forks;
		combo.num_of_philo = num_of_philosophers;
		if (pthread_create(&array_of_philos[i], NULL, &initalizer, &combo) != 0)
			perror("Failed to created thread");
		i++;
	}
	int num = 0;

	gettimeofday(&te, NULL);
	current = te.tv_sec * 1000LL + te.tv_usec / 1000;
	while (1)
	{
		if (array_of_philos[num].philosopher.last_time_eaten - current > array_of_philos[num].philosopher.time_to_die)
		{
			printf("philosopher N%d died\n", array_of_philos[num].philosopher.index);
			break;
		}
		gettimeofday(&te, NULL);
		current = te.tv_sec * 1000LL + te.tv_usec / 1000;
		num++;
		if (num == num_of_philosophers)
			num = 0;
	}
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
