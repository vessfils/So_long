# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vess <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/01 10:19:31 by vess              #+#    #+#              #
#    Updated: 2022/02/07 23:13:28 by vess             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = so_long.c \
	  get_next_line.c \
	  get_next_line_utils.c \
	display.c	\


OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		make -C minilibx-linux
		mv minilibx-linux/libmlx.a .
		gcc -Wall -g3 -Werror -Wextra -c $(SRC)
		gcc -Wall -g -Werror -Wextra -L. -lmlx -lXext -lX11 $(OBJ) -o $(NAME)

clean:
		make -C minilibx-linux clean
		rm -rf $(OBJ) libft.a libmlx.a

fclean: clean
		make -C minilibx-linux clean
		rm -rf $(NAME)

re : fclean all
