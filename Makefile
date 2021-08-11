# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akliek <akliek@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/09 17:52:07 by akliek            #+#    #+#              #
#    Updated: 2021/08/11 12:57:34 by akliek           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc

LIBS = -lpthread -lmlx -Lmlx -framework OpenGL -framework AppKit

CFLAGS = -Wall -Werror -Wextra -O3

MLX_DIR = ./mlx

SRC = fract_ol.c	\
	init.c	\
	utils.c	\
	multithread.c	\
	draw.c	\
	algorithm.c	\
	hooks.c

OBJ :=  $(SRC:.c=.o)

all: $(NAME)

$(NAME):
		make -C $(MLX_DIR)
		$(CC) -c $(CFLAGS) $(SRC)
		$(CC) $(CFLAGS) $(LIBS) $(SRC) -o $(NAME)

bonus:
		make -C $(MLX_DIR)
		$(CC) -c $(CFLAGS) $(SRC)
		$(CC) $(CFLAGS) $(LIBS) $(SRC) -o $(NAME)

clean:
		rm -rf $(OBJ)
		rm -rf $(NAME)

fclean: clean
		make -C $(MLX_DIR) clean

re:		
		make fclean
		make all
