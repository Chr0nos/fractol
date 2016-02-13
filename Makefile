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
OBJ=main.o

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $<

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re
