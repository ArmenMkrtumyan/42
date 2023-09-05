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

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <math.h>
size_t  ft_strlen(const char *word)
{
        size_t  size;

        if (!word)
                return (0);
        size = 0;
        while (word[size] != '\0')
        {
                size++;
        }
        return (size);
}

void handle_sigint(int sig)
{
    printf("\nCaught signal %d\n", sig);
}

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

int power_of_two(int count)
{
	int multiplication = 1;
	while(count > 0)
	{
		multiplication = multiplication * 2;
		count --;
	}
	return (multiplication);
}

void handle_sigusr1(int signum, siginfo_t *info, void *context)
{
	//MAKE EVERYTHING IN INTEGER
	int sum;
	int i;
	static int	byte_counter = -1;
	static int	letter[9];
	letter[8] = '\0';
	//SIGUSR1
	if (signum == 30)
	{
		//printf("1");
		byte_counter ++;
		letter[byte_counter] = power_of_two(byte_counter);
	}
	//SIGUSR2
	if (signum == 31)
	{
		//printf("0");
		byte_counter ++;
		letter[byte_counter] = 0;
	}

	if(byte_counter == 7)
	{
		sum = 0;
		i = 0;
		while(i<8)
		{
			sum = sum + letter[i];
			i++;
		}
		// printf("%c", (char)sum);
		write(1, &sum, 1);
		byte_counter = -1;
	}
	// You can perform cleanup or other tasks here if needed

	//exit(signum);
}
//int kill(pid_t pid, int signal);
int main()
{
	int serverPid;

	serverPid = getpid();
	printf("\nThis is PID: %d\n", serverPid);
	//client(serverPid,
    //signal(SIGINT, handle_sigint);

	struct sigaction sa;
    sa.sa_sigaction = handle_sigusr1;

    sa.sa_flags = SA_SIGINFO; //The SA_SIGINFO flag is used to indicate
	// that the sa_sigaction field should be used as the handler function

	// int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);

	// signum: This is the signal number you want to handle, similar to the signum parameter in the signal function.
	// act: This is a pointer to a struct sigaction that specifies the new signal handling behavior you want to set. This structure contains information about the new signal handler function, signal mask, and other options.
	// oldact: This is an optional parameter that allows you to retrieve the previous signal handling behavior for the specified signal. If you're not interested in preserving the old behavior, you can pass NULL.

	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
    while (1)
    {
        //printf("waiting\n");
        sleep(1);
    }
    return 0;
}
