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

char    *ft_strdup(char *string_1)
{
        char                    *string_2;
        unsigned long   i;

        string_2 = malloc(ft_strlen(string_1) * sizeof(char) + 1);
        if (!string_2)
                return (NULL);
        i = 0;
        while (i < ft_strlen(string_1))
        {
                string_2[i] = string_1[i];
                i++;
        }
        string_2[i] = '\0';
        return (string_2);
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
void handle_sigusr1(int signum, siginfo_t *info, void *context)
{
	static int	byte_counter = -1;
	if (signum == 30)
	{
		printf("Received SIGUSR1 signal(1)\n");
		byte_counter ++;
		((char*)context)[byte_counter] = pow(2, byte_counter);
		printf("\n\nThe received letter is %c\n\n", ((char*)context)[byte_counter]);
	}
	if (signum == 31)
	{
		printf("Received SIGUSR2 signal(0)\n");
		byte_counter ++;
		((char*)context)[byte_counter] = pow(2, byte_counter);
		printf("\n\nThe received letter is %c\n\n", ((char*)context)[byte_counter]);

	}
	if(byte_counter == 7)
	{
		printf("\n\nThe received letter is %s\n\n", (char*)context);
		byte_counter = -1;
	}
	// You can perform cleanup or other tasks here if needed

//	exit(signum);
}
//int kill(pid_t pid, int signal);
int main()
{
	int word[9];
	int serverPid;
	char *str_to_send = ft_strdup("HEYYYYYY!!!!!");

	word[8] = '\0';
	serverPid = getpid();
	printf("\nThis is PID: %d\n", serverPid);
	//client(serverPid,
    //signal(SIGINT, handle_sigint);

	void* word_pointer = word;

	struct sigaction sa;
    sa.sa_sigaction = handle_sigusr1;

    sa.sa_flags = SA_SIGINFO; //The SA_SIGINFO flag is used to indicate
	// that the sa_sigaction field should be used as the handler function

	// int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);

	// signum: This is the signal number you want to handle, similar to the signum parameter in the signal function.
	// act: This is a pointer to a struct sigaction that specifies the new signal handling behavior you want to set. This structure contains information about the new signal handler function, signal mask, and other options.
	// oldact: This is an optional parameter that allows you to retrieve the previous signal handling behavior for the specified signal. If you're not interested in preserving the old behavior, you can pass NULL.

	sigaction(SIGUSR1, &sa, word_pointer);
	sigaction(SIGUSR2, &sa, word_pointer);
    while (1)
    {
        //printf("waiting\n");
        sleep(1);
    }
    return 0;
}
