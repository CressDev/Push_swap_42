# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cress <cress@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/04 19:47:37 by cress             #+#    #+#              #
#    Updated: 2025/07/18 18:38:54 by cress            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

NAME_S = push_swap
SRC_S = push_swap.c push_swap_init.c push_swap_index.c push_swap_radix_sort.c push_swap_push.c push_swap_swap.c push_swap_rotate.c error_handler.c error_handler_2.c
OBJ_S = $(SRC_S:.c=.o)

all: $(NAME_S)

$(NAME_S): $(LIBFT) $(OBJ_S)
	@echo "Creando $(NAME_S)"
	$(CC) $(CFLAGS) $(OBJ_S) $(LIBFT) -o $(NAME_S)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(NAME_C) $(NAME_S) $(OBJ_S)
	make -C $(LIBFT_DIR) clean
##@echo "Archivos printf .o eliminados"

fclean: clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME_C) $(NAME_S) $(OBJ_S)
##@echo "$(NAME) eliminada"

re: fclean all
