NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -Iinclude
RM          = rm -f

SRC_DIR     = src
OBJ_DIR     = obj

SRC_FILES   = main.c \
              utils/stack_utils.c \
              utils/parsing_utils.c \
              utils/algorithm_utils.c \
              parsing/check_errors.c \
              utils/validation.c \
              utils/disorder.c \
              algorithms/sort_simple.c \
              algorithms/sort_complex.c \
              algorithms/turk_utils.c \
              operations/push.c \
              operations/reverse_rotate.c \
              operations/rotate.c \
              operations/swap.c

SRCS        = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS        = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
