#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/02/13 01:09:09 by snicolet          #+#    #+#             *#
#*   Updated: 2016/02/13 01:14:06 by snicolet         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME=fractol
FLAGS=-Wall -Werror -Wextra -Weverything
CC=clang
OBJ=main.o events.o mandelbrot.o rainbow.o
DRAW_PATH=./libs/draw/
DRAW=$(DRAW_PATH)libdraw.a
LINKER=-L$(DRAW_PATH) -ldraw -L./libs/libft -lft -lm -L./libs/minilibx_macos -lmlx -framework AppKit -framework OpenGL

all: $(NAME)

$(NAME): $(OBJ) $(DRAW)
	$(CC) $(OBJ) -o $(NAME) $(LINKER)

%.o: %.c
	$(CC) $(FLAGS) -c $< -I $(DRAW_PATH) -I ./libs/libft

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

$(DRAW):
	make -C $(DRAW_PATH)

.PHONY: clean fclean re
