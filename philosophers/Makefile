NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror  #-fsanitize=thread -g
SOURCES = $(wildcard *.c)
H_SOURCES = $(wildcard *.h)
O_SOURCES = $(subst .c,.o, $(SOURCES))
OBJ_DIRECTORY = object_dir
DIR_O_SOURCES = $(addprefix $(OBJ_DIRECTORY)/,$(O_SOURCES))

all: mkdir $(NAME)

mkdir:
	@mkdir -p $(OBJ_DIRECTORY)

$(OBJ_DIRECTORY)/%.o: %.c $(H_SOURCES) Makefile
	$(CC) -c $(CFLAGS) $< -o $@

$(NAME): $(DIR_O_SOURCES)
	$(CC) $(CFLAGS) $(DIR_O_SOURCES) -o $(NAME)

clean:
	rm -rf $(OBJ_DIRECTORY)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re mkdir