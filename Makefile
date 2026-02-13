# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: coholbur <coholbur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/21 14:56:50 by coholbur          #+#    #+#              #
#    Updated: 2025/04/21 14:57:26 by coholbur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
INC			= so_long.h

LIBFT_DIR   = ./libft
LIBFT       = $(LIBFT_DIR)/libft.a

MLX_DIR     = ./minilibx-linux
MLX         = $(MLX_DIR)/libmlx.a 

OBJ_DIR     = obj/
SRC         = build_map.c \
              check_arg.c \
			  get_moves2.c\
			  get_moves1.c\
			  free_game.c\
			  init.c\
              check_first.c \
              check_second.c \
			  check_third.c\
			  diff.c\
			  free_map.c\
			  errors_1.c\
			  errors_2.c\
              get_image.c\
              main.c\

OBJ         = $(patsubst %.c, $(OBJ_DIR)%.o, $(SRC))

CC          = cc
CFLAGS      = -Wall -Werror -Wextra -g3 
RM          = rm -f

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR) > /dev/null 

$(MLX):
	@make -C $(MLX_DIR) > /dev/null 

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(MLX) -lX11 -lXext > /dev/null 
	@echo "\033[1;35m--------------------------\033[0m"
	@echo "\033[1;35m√ Compilation successful √\033[0m"
	@echo "\033[1;35m--------------------------\033[0m"

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(OBJ_DIR)  
	@$(CC) $(CFLAGS) -c $< -o $@ > /dev/null 

clean:
	@make clean -C $(LIBFT_DIR) > /dev/null 
	@make clean -C $(MLX_DIR) > /dev/null 
	@rm -rf $(OBJ_DIR) 
	@echo "\033[1;35m--------------------------\033[0m"
	@echo "\033[1;35m√ Clean done √\033[0m"
	@echo "\033[1;35m--------------------------\033[0m"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR) > /dev/null
	@echo "\033[1;35m√ ${NAME} deleted √\033[0m"
	@echo "\033[1;35m--------------------------\033[0m"

re: fclean all

lib:
	@make -C $(LIBFT_DIR) > /dev/null 
	@make -C $(MLX_DIR) > /dev/null 

.PHONY: all clean fclean re lib



