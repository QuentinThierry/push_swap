NAME = push_swap
CFLAGS = -Wall -Wextra -Werror -g3
DEPS = $(INCLUDES)stack.h Makefile
INCLUDES = includes/
SRC_DIR = src/
OBJ_DIR = obj/

SRC_FILES = $(addprefix $(SRC_DIR), \
	ft_split.c \
	internal_operations.c \
	list_operations.c \
	main.c \
	parsing.c \
	utils.c \
	get_next_line.c \
	get_next_line_utils.c)

OBJ = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC_FILES))

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(DEPS)
	@if [ ! -d "$(OBJ_DIR)" ]; then mkdir $(OBJ_DIR); fi
	@if [ ! -d "$(dir $@)" ]; then mkdir $(dir $@); fi
	gcc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(DEPS)
	gcc $(CFLAGS) $(OBJ) -o $(NAME)

all : $(NAME)

clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re