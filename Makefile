
NAME	= push_swap
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
CC		= cc
CFLAGS	= -Werror -Wall -Wextra -g
AR		= ar rcs
RM		= rm -f
SRC_DIR = src
OBJ_DIR = obj
SRCS	= src/init_stack.c src/operations.c src/operation2.c \
			src/push_swap.c src/sort_big.c src/sort_small.c \
			src/utils.c src/check_is_valid.c src/sort_big2.c
OBJS	= $(SRCS:src/%.c=obj/%.o)
INCLUDE = -I include
all: $(NAME)
$(LIBFT):
	@make -C $(LIBFT_DIR)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
%.o: src/%.c | $(LIBFT)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)
clean:
	@make clean -C $(LIBFT_DIR)
	$(RM) $(OBJS)
fclean: clean
	@make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)
re: fclean all
.PHONY: all clean fclean re