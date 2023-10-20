#include "so_long.h"

void	on_exit(char *error_message)
{
	printf("\n\n%s\n\n", error_message);
	exit(1);
}
