#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

// INCLUDES

#include "libft.h"

// MINISHELL FUNCTIONS

void	print_history();
char	*get_last_dir(char *path);
void	on_exit(char *msg, int status);
void	check_env(char *word);
int		main();

#endif