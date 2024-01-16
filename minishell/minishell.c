#include <stdio.h>
#include <stdlib.h>
#include "minishell.h"

#include <readline/readline.h>
#include <readline/history.h>

void print_history()
{
	HIST_ENTRY *entry;
	int i = history_base;

	printf("History:\n");
	while ((entry = history_get(i++)) != NULL)
	{
		printf("%d: %s\n", i - 1, entry->line);
	}
}

char *get_last_dir(char *path)
{
	int 	len;
	char 	*last_dir;
	int		i;

	len = ft_strlen(path);
	while (path[len] != '/')
		--len;
	last_dir = malloc(len + 5);
	i = 0;
	len ++;
	while (path[len] != '\0')
		last_dir[i++] = path[len++];
	last_dir[i] = ':';
	last_dir[i + 1] = '~';
	last_dir[i + 2] = '$';
	last_dir[i + 3] = ' ';
	last_dir[i + 4] = '\0';
	return last_dir;
}

void on_exit(char *msg, int status)
{
	// Status has to be changed or configured better
	// Vabshe inch status axper?
	printf("%s\n", msg);
	exit(status);
}

void check_env(char *word)
{
	if (!word)
		on_exit("Not an environment variable", 1);
}

int main()
{
	char *inpt;
	char *last_dir;
	char *pwd;

	int i = 0;

	while (i < 5)
	{
		//getting current working directory using getcwd function
		//printf("The current working directory is %s\n", getcwd(NULL, 0));
		pwd = getenv("PWD");
		check_env(pwd); // If env variables dsnt exist, it will exit
		last_dir = get_last_dir(pwd);
		inpt = readline(last_dir);
		add_history(inpt);
		printf("%s", inpt);
		printf("\n");
		++i;
	}

	print_history();


	// char *user;
    // printf("%s\n",getenv("USER"));
    // printf("The current User Directory is\n");
    // printf("%s\n",getenv("PWD"));

	free(inpt);
	return 0;
}
