NAME = so_long

CC = cc

CFLAGS = -fsanitize=address -g -ggdb3#-Wall -Wextra -Werror

RM = rm -f

SRCS	=	check_file.c	\
			mlx.c			\
			path_check.c

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
