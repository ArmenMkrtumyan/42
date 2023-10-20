NAME = so_long

CC = cc

CFLAGS = -g -ggdb3 #-fsanitize=address #-Wall -Wextra -Werror

RM = rm -f

SRCS	=	check_file.c	\
			mlx.c			\
			path_check.c	\
			util_initializers.c	\
			util_updater.c	\
			util_checkers.c	\
			util_getters.c	\
			util_printer.c	\
			util_packers.c	\

OBJS = $(SRCS:.c=.o)

all:	mlx	$(NAME)

mlx:
	make -C mlx

%.o: %.c Makefile so_long.h
	$(CC) $(CFLAGS) -I mlx -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -I mlx -L mlx -lmlx -lm -framework OpenGL -framework AppKit -o $(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY: 	all clean fclean re
