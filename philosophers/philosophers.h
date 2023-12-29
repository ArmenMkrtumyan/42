/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:04:47 by amkrtumy          #+#    #+#             */
/*   Updated: 2023/11/01 17:04:50 by amkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

// INCLUDES

# include "ft_printf.h"
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <time.h>
# include <sys/time.h>

typedef struct s_philosopher
{
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					eat_count;
	int					last_time_eaten;
}						t_philosopher;

typedef struct s_array_of_philosophers
{
	int					philo_num;
	int					index;
	int					last_time_eaten;
	pthread_t			thread_id;
	t_philosopher		philosopher;
	struct timeval		start_time;
	pthread_mutex_t		last_time_mutex;
	pthread_mutex_t		*forks;
	int					num_of_times_eaten;
}						t_philos;

typedef struct constants
{
	int					philo_num;
	int					i;
	struct timeval		start_time;
}						t_constants;

typedef struct constants_2
{
	int					t_passed;
	int					current;
	int					index;
}						t_constants_2;

// PHILOSOPHERS

int				on_exit(char *message);
void			*start_threads(void *packed);
int				go_to_sleep(t_philos *pack, t_constants_2 const2);
int				go_to_eat(t_philos *pack);

// ATOI

int				check_emptyness(int i, const char *str);
void			check_sign(char str_i, int *sign, int *i);
int				ft_atoi(char *str);

// CHECKERS

void			assign_pack(t_philos *pack, t_constants_2 const2);
int				check_max(char *string, char *critical_value);
int				check_if_number(char *element);
int				check_parsing(char *element);
int				check_death(t_philos *array_of_philos, int num_of_philosophers,
					struct timeval start_time);
int				check_parsing_stuff(int argc, char **argv);

// INITIALIZERS_GETTERS

void			init_mutexes(t_philos *array_of_philos, pthread_mutex_t *forks,
					int num_of_philosophers);
t_philosopher	init_philo_1(int argc, char **argv);
void			init_philo_2(t_philos *philo, t_philosopher philosopher,
					pthread_mutex_t *forks, t_constants constants);
int				get_time(struct timeval given_time);
int				init_thread(t_philos *array_of_philos);

#endif
