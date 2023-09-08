NAME = server

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRCS = client.c \
		server.c \
		ft_atoi.c

OBJS = $(SRCS:.c=.o)

all: PRINTF $(NAME)

PRINTF:
	make -C ft_printf

%.o: %.c
	$(CC) $(CFLAGS) -Ift_printf -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) client.o ft_atoi.o -lftprintf -Lft_printf -o client
	$(CC) $(CFLAGS) server.o -lftprintf -Lft_printf -o server

clean:
			make clean -C ft_printf
			$(RM) $(OBJS)

fclean:		clean
			make fclean -C ft_printf
			$(RM) $(NAME)

re:			fclean all

.PHONY: 	all clean fclean re
