# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgu <rgu@student.42madrid.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/04 12:45:13 by rgu               #+#    #+#              #
#    Updated: 2025/05/04 12:48:55 by rgu              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	= push_swap
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
CC		= cc
CFLAGS	= -Werror -Wall -Wextra -g
AR		= ar rcs
RM		= rm -f
SRC_DIR = src
OBJ_DIR = obj
SRCS	= $(wildcard src/*.c)
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