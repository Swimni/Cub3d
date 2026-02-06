# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbuisson <mbuisson@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/22 11:37:36 by nguinot-          #+#    #+#              #
#    Updated: 2026/02/03 10:33:13 by mbuisson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -Iincludes -Iminilibx
MLX_DIR = ./minilibx/minilibx-linux
SRC     = $(wildcard src/*.c src/movement/*.c src/rendering/*.c src/utils/*.c src/mlx/*.c src/main/*.c src/textures/*.c src/parsing/*.c src/GNL/*.c)
OBJ     = $(SRC:.c=.o)

MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(MLX_FLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
