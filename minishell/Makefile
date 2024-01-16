CC = cc
CFLAGS =   -Wall -Wextra -Werror -g -fsanitize=address
NAME = minishell
SOURCES = $(wildcard *.c)
H_SOURCES = $(wildcard *.h)
O_SOURCES = $(subst .c,.o, $(SOURCES))
OBJ_DIRECTORY = object_dir
DIR_O_SOURCES = $(addprefix $(OBJ_DIRECTORY)/,$(O_SOURCES))
LIBFT_DIR = libft
HEADERS = -I$(LIBFT_DIR)
LINK_LIBRARIES = -lft -L$(LIBFT_DIR)

all: mkdir call_libft $(NAME)

mkdir:
	@mkdir -p $(OBJ_DIRECTORY)

call_libft:
	@make -C $(LIBFT_DIR)

$(OBJ_DIRECTORY)/%.o: %.c $(H_SOURCES)
	$(CC) $(HEADERS) -c $(CFLAGS) $< -o $@

$(NAME): $(DIR_O_SOURCES) Makefile
	$(CC) $(CFLAGS) $(DIR_O_SOURCES) -lreadline $(LINK_LIBRARIES) -o $(NAME)

clean:
	rm -rf $(OBJ_DIRECTORY)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re mkdir call_printf call_libft