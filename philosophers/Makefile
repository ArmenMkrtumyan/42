NAME = philosophers
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address -pthread
SOURCES = $(wildcard *.c)
H_SOURCES = $(wildcard *.h)
O_SOURCES = $(subst .c,.o, $(SOURCES))
OBJ_DIRECTORY = object_dir
DIR_O_SOURCES = $(addprefix $(OBJ_DIRECTORY)/,$(O_SOURCES))
PRINTF_DIR = ft_printf
HEADERS = -I$(PRINTF_DIR)
LINK_LIBRARIES = -lftprintf -L$(PRINTF_DIR)


all: mkdir call_printf $(NAME)

mkdir:
	@mkdir -p $(OBJ_DIRECTORY)

call_printf:
	@make -C $(PRINTF_DIR)

$(OBJ_DIRECTORY)/%.o: %.c $(H_SOURCES)
	$(CC) $(HEADERS) -c $(CFLAGS) $< -o $@

$(NAME): $(DIR_O_SOURCES)
	$(CC) $(CFLAGS) $(DIR_O_SOURCES) $(LINK_LIBRARIES) -o $(NAME)

clean:
	rm -rf $(OBJ_DIRECTORY)
	make clean -C $(PRINTF_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(PRINTF_DIR)

re: fclean all

.PHONY: all clean fclean re mkdir call_printf