// C program to illustrate
// read system Call
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include <string.h>

char *read_file(char *file_name)
{
	 FILE	*file;

	 file = fopen(file_name, "r");

	 if (file == NULL)
		 return (NULL);

	 fseek(file, 0, SEEK_END);

	 int length = ftell(file);

	 printf("LENGTH IS: %d\n", length);

	 fseek(file, 0, SEEK_SET);

	 char	*string = malloc(sizeof(char) * (length + 1)); 

	char c;
	int i = 0;
	while((c = fgetc(file)) != EOF)
	{
		string[i] = c;
		i++;
	}
	string[i] = '\0';
	fclose(file);
	return (string);
}

int main()
{
	char filename[1024];

	printf("File: ");
	scanf("%s", filename);

	//char *file_contents = read_file(filename);
	int file_contents = read(0, filename, 1024);

	if(file_contents == NULL)
	{
		printf("Erorr reading file.\n");
		return (1);
	}

	printf("FILE CONTENTS: \n\n%s\n", file_contents);

	free(file_contents);
	return (1);

}

