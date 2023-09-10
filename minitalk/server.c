/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:11:19 by amkrtumy          #+#    #+#             */
/*   Updated: 2023/09/10 18:05:22 by amkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <signal.h>
#include "ft_printf.h"

int	power_of_two(int count)
{
	int	multiplication;

	multiplication = 1;
	while (count > 0)
	{
		multiplication = multiplication * 2;
		count --;
	}
	return (multiplication);
}

void	handle_sigusr1(int signum, siginfo_t *info, void *context)
{
	int			sum;
	int			i;
	static int	byte_counter = -1;
	static int	letter[9];

	(void)info;
	(void)context;
	letter[8] = '\0';
	if (signum == 30)
	{
		byte_counter++;
		letter[byte_counter] = power_of_two(byte_counter);
	}
	if (signum == 31)
		letter[++byte_counter] = 0;
	if (byte_counter == 7)
	{
		sum = 0;
		i = 0;
		while (i < 8)
			sum = sum + letter[i++];
		write(1, &sum, 1);
		byte_counter = -1;
	}
}

int	main(int argc, char *argv[])
{
	int					server_pid;
	struct sigaction	sa;

	(void)argv;
	if (argc != 1)
		return (ft_printf("%s", "Invalid number of arguments"));
	server_pid = getpid();
	ft_printf("\nThis is PID: %d\n", server_pid);
	sa.sa_sigaction = handle_sigusr1;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		sleep(1);
	}
	return (0);
}
