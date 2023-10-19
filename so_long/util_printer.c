#include "so_long.h"

// void wrong_dimensions()
// {
//     if (exitCode == 99) {
//     	printf("\n\nWRONG INSIDES\n\n");
//         // Add your custom code here to handle the special exit condition.
//     }
// }

void on_exit(char *error_message)
{
    printf("\n\n%s\n\n", error_message);
    exit(1);
}