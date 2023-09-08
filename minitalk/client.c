/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:11:16 by amkrtumy          #+#    #+#             */
/*   Updated: 2023/06/13 16:01:09 by amkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "ft_printf.h"

int	ft_atoi(char *s);

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] && s2[i]) && s1[i] == s2[i])
		++i;
	return (s1[i] - s2[i]);
}

int	check_pid(char *pid)
{
	int	i;

	i = 0;
	while (pid[i])
	{
		if (pid[i] < '0' || pid[i] > '9')
		{
			ft_printf("invalid input");
			exit (1);
		}
		++i;
	}
	if (i >= 10 && ft_strcmp("2147483647", pid) < 0)
	{
		ft_printf("invalid input");
		exit (1);
	}
	return (0);
}

void	check_singal_result(int signal_result)
{
	if (signal_result != 0)
		ft_printf("Error sending signal");
}

void	send_signals(char *letter, int *signal_result, int *counter, int *pid)
{
	while (*letter != 0)
	{
		if (*letter % 2 == 0)
		{
			*signal_result = kill(*pid, SIGUSR2);
			check_singal_result(*signal_result);
		}
		else
		{
			*signal_result = kill(*pid, SIGUSR1);
			check_singal_result(*signal_result);
		}
		(*counter)++;
		usleep(20);
		*letter = *letter / 2;
	}
}

int	main(int argc, char *argv[])
{
	int		pid;
	int		i;
	char	letter;
	int		signal_result;
	int		counter;

	i = 0;
	if (argc != 3 || check_pid(argv[1]))
		return (ft_printf("%s", "Invalid number of arguments"));
	pid = ft_atoi(argv[1]);
	ft_printf("The pid is: %d and the text is - %s\n", pid, argv[2]);
	while (argv[2][i] != 0)
	{
		letter = argv[2][i++];
		counter = -1;
		send_signals(&letter, &signal_result, &counter, &pid);
		while (counter != 7)
		{
			signal_result = kill(pid, SIGUSR2);
			check_singal_result(signal_result);
			counter++;
			usleep(100);
		}
	}
	return (0);
}
