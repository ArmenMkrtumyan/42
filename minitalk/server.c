/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:11:19 by amkrtumy          #+#    #+#             */
/*   Updated: 2023/06/13 15:18:18 by amkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <signal.h>

#include "ft_printf.h"

// void handle_sigusr1(int signum, siginfo_t *info, char *word)
// {
// 	static int	byte_counter = -1;

// 	if (signum == 30)
// 	{
// 		printf("Received SIGUSR1 signal(1)\n");
// 		byte_counter ++;
// 		word[byte_counter] = pow(2, byte_counter);
// 	}
// 	if (signum == 31)
// 	{
// 		printf("Received SIGUSR2 signal(0)\n");
// 		byte_counter ++;
// 		word[byte_counter] = pow(2, byte_counter);
// 	}

	// if(byte_counter == 7)
	// {
	// 	printf("\n%s\n", word);
	// 	byte_counter = -1;
	// }
// }

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

int	main(void)
{
	int					server_pid;
	struct sigaction	sa;

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
