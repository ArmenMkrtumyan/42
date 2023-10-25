NAME = so_long

CC = cc

CFLAGS = -g -ggdb3 -fsanitize=address #-Wall -Wextra -Werror

RM = rm -f

SRCS	=	check_file.c		\
			mlx.c				\
			path_check.c		\
			util_initializers.c	\
			util_updaters_1.c	\
			util_checkers.c		\
			util_getters.c		\
			util_print_draw.c	\
			util_updaters_2.c	\
			util_updaters_3.c	\
			util_list.c			\
			util_for_mlx.c		\
			util_print_draw_2.c	\

OBJS = $(SRCS:.c=.o)

all:	mlx_run	$(NAME)

mlx_run:
	make -C mlx

%.o: %.c Makefile so_long.h
	$(CC) $(CFLAGS) -I mlx -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -I mlx -L mlx -lmlx -lm -framework OpenGL -framework AppKit -o $(NAME)

clean:
			make clean -C mlx
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY: 	all clean fclean re
