NAME = push_swap
NAMEC = checker
CFLAGS = -Wall -Wextra -g3 #-Werror
DEPS = $(INCLUDES)stack.h $(INCLUDES)get_next_line.h Makefile
INCLUDES = includes/
SRC_DIR = src/
OBJ_DIR = obj/
CC = gcc

SRC_P = $(addprefix $(SRC_DIR), \
	ft_split.c \
	internal_operations.c \
	list_operations.c \
	list_operations2.c \
	parsing.c \
	utils.c \
	checker.c \
	instructions.c \
	get_next_line.c \
	get_next_line_utils.c \
	algo_operations.c \
	main.c)

SRC_C = $(addprefix $(SRC_DIR), \
	ft_split.c \
	internal_operations.c \
	list_operations.c \
	list_operations2.c \
	parsing.c \
	utils.c \
	checker.c \
	instructions.c \
	get_next_line.c \
	get_next_line_utils.c \
	checker_main.c)

OBJ_P = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC_P))
OBJ_C = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC_C))

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(DEPS)
	@if [ ! -d "$(OBJ_DIR)" ]; then mkdir $(OBJ_DIR); fi
	@if [ ! -d "$(dir $@)" ]; then mkdir $(dir $@); fi
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ_P) $(DEPS)
	$(CC) $(CFLAGS) $(OBJ_P) -o $(NAME)

$(NAMEC): $(OBJ_C) $(DEPS)
	$(CC) $(CFLAGS) $(OBJ_C) -o $(NAMEC)

all : $(NAME)

bonus : $(NAMEC)

clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -f $(NAME)
	rm -f $(NAMEC)

re : fclean all

.PHONY : all clean fclean re bonus