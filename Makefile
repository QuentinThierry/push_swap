NAME = push_swap
NAMEC = checker
CFLAGS = -Wall -Wextra -Werror -g3
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
	utils2.c \
	checker.c \
	parsing_instructions.c \
	get_next_line.c \
	get_next_line_utils.c \
	pivot_finder.c \
	algo_operations.c \
	split_on_a.c \
	split_on_b.c \
	sort_at_3.c \
	sort_at_2.c \
	printer.c \
	merge_instruction.c \
	special_sort.c \
	list_utils.c \
	main.c)

SRC_C = $(addprefix $(SRC_DIR), \
	ft_split.c \
	internal_operations.c \
	list_operations.c \
	list_operations2.c \
	list_utils.c \
	parsing.c \
	utils.c \
	utils2.c \
	checker.c \
	parsing_instructions.c \
	get_next_line.c \
	get_next_line_utils.c \
	printer.c \
	merge_instruction.c \
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