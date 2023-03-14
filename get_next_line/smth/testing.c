// C program to illustrate
// open system call

#include "get_next_line.h"

extern int errno;



//-----------------------------------------------------------1
// READ OR CREATE IF NEEDED



// int main()
// {	
// 	// if file does not have in directory
// 	// then file foo.txt is created.
// 	int fd = open("foo.txt", O_RDONLY | O_CREAT);
	
// 	printf("fd = %d\n", fd);
	
// 	if (fd ==-1)
// 	{
// 		// print which type of error have in a code
// 		printf("Error Number % d\n", errno);
		
// 		// print program detail "Success or failure"
// 		perror("Program");				
// 	}
//     int close(int fd);
// 	return 0;
// }

// C program to illustrate close system Call



//---------------------------------------------------2
//OPENING AND READING FILE DESCRIPTORS



// int main()
// {
// 	// assume that foo.txt is already created
// 	int fd1 = open("foo.txt", O_RDONLY, 0);
// 	close(fd1);
	
// 	// assume that baz.tzt is already created
// 	int fd2 = open("baz.txt", O_RDONLY, 0);
	
// 	printf("fd2 = % d\n", fd2);
// 	exit(0);
// }



//-----------------------------------------------------------3
//OPENING AND READING AND PRINTING OUT


// C program to illustrate
// read system Call
// #include<stdio.h>
// #include <fcntl.h>
// int main()
// {
// int fd, sz;
// char *c = (char *) calloc(100, sizeof(char));

// fd = open("foo.txt", O_RDONLY);
// if (fd < 0) { perror("r1"); exit(1); }

// sz = read(fd, c, 10);
// printf("called read(% d, c, 10). returned that"
// 		" %d bytes were read.\n", fd, sz);
// c[sz] = '\0';
// printf("Those bytes are as follows: %s\n", c);
// }


//________________________________________________4


// #include<stdio.h>
// #include<unistd.h>
// #include<fcntl.h>
// #include<stdlib.h>

int main()
{
    char *c = (char *) malloc(100);	
    int fd1 = open("foo.txt", O_RDONLY, 0);
	int fd_2 = fd1;
	read(fd1, c, 2);
	printf("c = %s\n", c);
	read(fd_2, c, 2);
	printf("c = %s\n", c);
	read(fd1, c, 2);
	printf("c = %s\n", c);
	printf("c = %s\n", c);
	read(fd_2, c, 2);
	printf("c = %s\n", c);
	read(fd1, c, 2);
	printf("c = %s\n", c);
	read(fd1, c, 2);
	printf("c = %s\n", c);
	printf("c = %s\n", c);
	read(fd_2, c, 2);
	printf("c = %s\n", c);
	read(fd1, c, 2);
	printf("c = %s\n", c);
	//exit(0);
}

//______________________________________________5
// WRITING


// #include<stdio.h>
// #include <fcntl.h>
// int main()
// {
// int sz;

// int fd = open("foo.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
// if (fd < 0)
// {
// 	perror("r1");
// 	exit(1);
// }

// sz = write(fd, "hello geeks\n", strlen("hello geeks\n"));

// printf("called write(% d, \"hello geeks\\n\", %lu).\n It returned %d\n", fd, strlen("hello geeks\n"), sz);

// close(fd);
// }