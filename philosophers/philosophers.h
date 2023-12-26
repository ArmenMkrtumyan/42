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

// # include "libft.h"
// # include "ft_printf.h"
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>

typedef struct s_philosopher
{
	int		index;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		eat_count;
	int		last_time_eaten;
}			t_philosopher;

typedef struct s_fork_plus_philosopher
{
	t_philosopher		philosopher;
	pthread_mutex_t*	forks;
	int					num_of_philo;
}						t_fork_plus_philosopher;

// MAIN FUNCTION


# endif