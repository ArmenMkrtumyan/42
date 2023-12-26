/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:08:55 by amkrtumy          #+#    #+#             */
/*   Updated: 2023/11/23 17:00:45 by amkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <sys/time.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

void	on_exit(char *message)
{
	printf("\n%s\n", message);
	exit(1);
}

void*	some_function()
{
	printf("\nTest from Threads\n");
	sleep(3);
	printf("\nEnding thread\n");
	return NULL;
}

int main() {

	struct timeval te;
	gettimeofday(&te, NULL); // get current time
	long long milliseconds = te.tv_sec*1000LL + te.tv_usec/1000; // calculate milliseconds
	printf("milliseconds: %lld\n", milliseconds);

	pthread_t thread_1, thread_2;
	if (pthread_create(&thread_1, NULL, &some_function, NULL))
		on_exit("Error during thread creation"); //THREAD PTR, CUSTOMIZATION, FUNCTION TO EXECUTE DURING CREATION, ARGUMENTS TO FUNCTION
	if (pthread_create(&thread_2, NULL, &some_function, NULL))
		on_exit("Error during thread creation");
	pthread_join(thread_1, NULL); //WAIT FOR THREADS// THREAD, RETURN FROM THREAD
	pthread_join(thread_2, NULL);
	gettimeofday(&te, NULL);
	milliseconds = te.tv_sec*1000LL + te.tv_usec/1000;
	printf("milliseconds: %lld\n", milliseconds);

  	return 0;
//   struct timeval tv;
//   time_t t;
//   struct tm *info;
//   char buffer[64];

//   gettimeofday(&tv, NULL);
//   t = tv.tv_sec;

//   info = localtime(&t);
//   printf("%s",asctime (info));
//   strftime (buffer, sizeof buffer, "Today is %A, %B %d.\n", info);
//   printf("%s",buffer);
//   strftime (buffer, sizeof buffer, "The time is %I:%M %p.\n", info);
//   printf("%s",buffer);


/* # PTHREAD_CREATE AND PTHREAD_JOIN
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 5

void *perform_work(void *arguments){
  int index = *((int *)arguments);
  int sleep_time = 1 + rand() % NUM_THREADS;
  printf("THREAD %d: Started.\n", index);
  printf("THREAD %d: Will be sleeping for %d seconds.\n", index, sleep_time);
  sleep(sleep_time);
  printf("THREAD %d: Ended.\n", index);
  return NULL;
}

int main(void) {
  pthread_t threads[NUM_THREADS];
  int thread_args[NUM_THREADS];
  int i;
  int result_code;

  //create all threads one by one
  for (i = 0; i < NUM_THREADS; i++) {
    printf("IN MAIN: Creating thread %d.\n", i);
    thread_args[i] = i;
    result_code = pthread_create(&threads[i], NULL, perform_work, &thread_args[i]);
    assert(!result_code);
  }

  printf("IN MAIN: All threads are created.\n");

  //wait for each thread to complete
  for (i = 0; i < NUM_THREADS; i++) {
    result_code = pthread_join(threads[i], NULL);
    assert(!result_code);
    printf("IN MAIN: Thread %d has ended.\n", i);
  }

  printf("MAIN program has ended.\n");
  return 0;
*/
}
