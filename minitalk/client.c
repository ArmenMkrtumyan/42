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

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

//Volatile
//is for variables which can be changed from
//external function, whereas global variables still have
//to be assigned inside the program, such as a=42
//
//sig_atomic_t is data type which ensures safe use inside
//the signal handler
//


// Handling with signal function

// // Custom signal handler function
// void handle_sigint(int signum) {
//     printf("Received SIGINT signal (%d). Exiting...\n", signum);
//     // You can perform cleanup or other tasks here if needed
//     exit(signum);
// }

// int main() {
//     // Registering the custom handler for SIGINT


// 	// void (*signal(int signum, void (*handler)(int)))(int);
//     signal(SIGINT, handle_sigint);

//     printf("Press Ctrl+C to trigger the SIGINT signal.\n");

//     // A loop to keep the program running until the signal is received
//     while (1) {
//         // Your program's main logic goes here
//     }

//     return 0;
// }


// Sig empty set example
// int sigemptyset(sigset_t *set);

// int main() {
//     sigset_t my_set;
//     sigemptyset(&my_set); // Initialize an empty signal set

//     // Now 'my_set' is an empty signal set
//     return 0;
// }

// Sig add set example
// int sigaddset(sigset_t *set, int signum);

// int main() {
//     sigset_t my_set;
//     sigemptyset(&my_set);

//     sigaddset(&my_set, SIGINT); // Add SIGINT signal to 'my_set'

//     // Now 'my_set' contains the SIGINT signal
//     return 0;
// }


// To see a list of available signals and their corresponding numbers, you can use the kill -l option.

// 1. PAUSE

void signal_handler(int signum) {
    printf("Signal %d received. Resuming...\n", signum);
}


int main(int argc, char *argv[]) {
	char	*text;
	int		pid;

	if(argc != 3)
		printf("%s", "Invalid number of arguments");
	else
	{
		pid = atoi(argv[1]);
		text = argv[2];

		//signal(SIGUSR1, signal_handler);
		printf("Resumed.\n");

		printf("The pid is: %d and the text is - %s\n", pid, text);
		//pause(); // Program waits here until a signal is received
		//printf("Resumed.\n");

		int i = 0;
		char letter;
		int signal_result;
		int counter;
		while(text[i] != 0)
		{
			letter = text[i];
			counter=-1;
			while(letter != 0)
			{
				if(letter % 2 == 0)
				{
					signal_result = kill(pid, SIGUSR2);
					if (signal_result == 0)
						printf("SIGUSR2 signal sent successfully.\n");
					else
						printf("Error sending signal");
				}
				else
				{
					signal_result = kill(pid, SIGUSR1);
					if (signal_result == 0)
						printf("SIGUSR1 signal sent successfully.\n");
					else
						printf("Error sending signal");
				}
				usleep(100);
				counter++;
				letter = letter / 2;
			}
			i++;
			//Addding the extra zeros to make it 1 byte
			while(counter != 8)
			{
				signal_result = kill(pid, SIGUSR2);
				if (signal_result == 0)
					printf("SIGUSR2 signal sent successfully.\n");
				else
					printf("Error sending signal");
				counter++;
			}
		}
	}
    return 0;
}


// 2. SLEEP

// int main() {
//     printf("Sleeping for 5 seconds...\n");
//     sleep(5); // Program pauses for 5 seconds
//     printf("Awake!\n");

//     return 0;
// }

// 3. USLEEP - same but for microseconds

// 4.