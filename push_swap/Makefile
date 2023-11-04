CC = cc
CFLAGS = -Wall -Wextra -g -fsanitize=address #-Werror
NAME = push_swap
SOURCES = $(wildcard *.c)
O_SOURCES = $(subst .c,.o, $(SOURCES))
OBJ_DIRECTORY = object_dir
DIR_O_SOURCES = $(addprefix $(OBJ_DIRECTORY)/,$(O_SOURCES))
PRINTF_DIR = ft_printf
LIBFT_DIR = libft
HEADERS = -I$(PRINTF_DIR) -I$(LIBFT_DIR)
LINK_LIBRARIES = -lft -L$(LIBFT_DIR) -lftprintf -L$(PRINTF_DIR)

all: mkdir call_printf call_libft $(NAME)

mkdir:
	@mkdir -p $(OBJ_DIRECTORY)

call_printf:
	@make -C $(PRINTF_DIR)

call_libft:
	@make -C $(LIBFT_DIR)

$(OBJ_DIRECTORY)/%.o: %.c
	$(CC) $(HEADERS) -c $(CFLAGS) $< -o $@

$(NAME): $(DIR_O_SOURCES)
	$(CC) $(CFLAGS) $(DIR_O_SOURCES) $(LINK_LIBRARIES) -o $(NAME)

clean:
	rm -rf $(OBJ_DIRECTORY)
	make clean -C $(LIBFT_DIR)
	make clean -C $(PRINTF_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re mkdir call_printf call_libft