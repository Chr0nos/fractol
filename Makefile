# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/13 01:09:09 by snicolet          #+#    #+#              #
#    Updated: 2016/02/18 11:43:24 by snicolet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fractol
FLAGS=-Wall -Werror -Wextra -Weverything
CC=clang
OBJ=main.o events.o mandelbrot.o rainbow.o julia.o
DRAW_PATH=./libs/draw/
DRAW=$(DRAW_PATH)libdraw.a
LIBFT_PATH=./libs/libft/
LIBFT=$(LIBFT_PATH)libft.a
LINKER=-L$(DRAW_PATH) -ldraw -L$(LIBFT_PATH) -lft -lm -L./libs/minilibx_macos -lmlx -framework AppKit -framework OpenGL

all: $(NAME)

$(NAME): $(OBJ) $(DRAW) $(LIBFT)
	$(CC) $(OBJ) -o $(NAME) $(LINKER) $(FLAGS)

%.o: %.c
	$(CC) $(FLAGS) -c $< -I $(DRAW_PATH) -I $(LIBFT_PATH)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

relibs: re
	make -C $(LIBFT_PATH) re
	make -C $(DRAW_PATH) re

$(DRAW):
	make -C $(DRAW_PATH)

$(LIBFT):
	make -C $(LIBFT_PATH)

.PHONY: clean fclean re relibs all
