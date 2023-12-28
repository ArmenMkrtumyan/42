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

typedef struct			s_philosopher
{
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					eat_count;
	int					last_time_eaten;
}						t_philosopher;

typedef struct			s_array_of_philosophers
{
	int					num_of_philo;
	int					index;
	int					last_time_eaten;
	pthread_t			thread_id;
	t_philosopher		philosopher;
	struct timeval		start_time;
	pthread_mutex_t		last_time_mutex;
	pthread_mutex_t*	forks;
}						t_philos;

typedef struct			constants
{
	int					num_of_philo;
	int					i;
	struct timeval		start_time;
}						t_constants;



// PHILOSOPHERS

int						get_time();
void					*initalizer(void *pack);
t_philosopher			get_values_from_argv(char **argv);
int						on_exit(char *message);


// ATOI

int						check_emptyness(int i, const char *str);
void					check_sign(char str_i, int *sign, int *i);
int						ft_atoi(char *str);

// CHECKERS

int						check_max(char *string, char *critical_value);
int						check_if_number(char *element);
int						check_parsing(char *element);
int						check_death(t_philos *array_of_philos, int num_of_philosophers, struct timeval start_time);
int						check_parsing_stuff(int argc, char **argv);

// INITIALIZERS

void					init_mutexes(t_philos *array_of_philos, pthread_mutex_t *forks, int num_of_philosophers);
void					init_philo(t_philos *philo, t_philosopher philosopher, pthread_mutex_t *forks, t_constants constants);

# endif