NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -Imlx

RM = rm -f

SRCS = ft_printf.c		\
		ft_printf_utils_1.c		\
		ft_printf_utils_2.c		\

OBJS = $(SRCS:.c=.o)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

all:		$(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY: 	all clean fclean re
