# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/13 01:09:09 by snicolet          #+#    #+#              #
#    Updated: 2016/03/18 13:44:17 by snicolet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fractol
FLAGS=-Wall -Werror -Wextra -Weverything -Ofast -march=native -mtune=native -pipe -fomit-frame-pointer
CC=clang
OBJ=main.o events.o mandelbrot.o rainbow.o \
	julia.o sierpcarp.o sierptriangle.o defaults.o \
	fractal_loader.o stats.o colormap.o closer.o events_mouse.o \
	display.o burningship.o help.o burningjulia.o mandelthread.o
MLX_PATH=./libs/minilibx_macos
DRAW_PATH=./libs/draw/
DRAW=$(DRAW_PATH)libdraw.a
LIBFT_PATH=./libs/libft/
LIBFT=$(LIBFT_PATH)libft.a
LINKER=-L$(DRAW_PATH) -ldraw -lpthread -L$(LIBFT_PATH) -lft -lm -L$(MLX_PATH) -lmlx -framework AppKit -framework OpenGL

all: $(NAME)

$(NAME): $(OBJ) $(DRAW) $(LIBFT)
	$(CC) $(OBJ) -o $(NAME) $(LINKER) $(FLAGS)

%.o: %.c
	$(CC) $(FLAGS) -c $< -I $(DRAW_PATH) -I $(LIBFT_PATH) -I $(MLX_PATH) -I ./headers/

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

relibs: re
	make -C $(LIBFT_PATH) FLAGS="$(FLAGS)" re
	make -C $(DRAW_PATH) FLAGS="$(FLAGS)" re

$(DRAW):
	make -C $(DRAW_PATH) MLX=../../$(MLX_PATH)

$(LIBFT):
	make -C $(LIBFT_PATH)

linux:
	make -w LINKER="-L$(DRAW_PATH) -ldraw -L$(LIBFT_PATH) -lpthread -lft -lm -L./libs/minilibx -lmlx -lX11 -lXext" MLX_PATH="./libs/minilibx" all

.PHONY: clean fclean re relibs all linux
