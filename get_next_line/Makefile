# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amkrtumy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 14:04:16 by amkrtumy          #+#    #+#              #
#    Updated: 2023/02/20 13:48:44 by amkrtumy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRCS = get_next_line.c get_next_line_utils.c

BSRCS = get_next_line_bonus.c get_next_line_utils_bonus.c

OBJS = $(SRCS:.c=.o)

BOBJS = $(BSRCS:.c=.o)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus:		$(BOBJS)
	ar rcs $(NAME) $(BOBJS)

clean:
			$(RM) $(OBJS)
			$(RM) $(BOBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY: 	all bouns clean fclean re
