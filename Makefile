# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vess <vess@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/01 05:31:56 by lzaccome          #+#    #+#              #
#    Updated: 2022/02/25 15:42:18 by vess             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = clang

CFLAGS =  -Wall -Wextra -Werror -g3 -o3

DEPS = $(SRCS:.c=.d)

DEPS_BONUS = $(SRCS_BONUS:.c=.d)

SRCS =	so_long.c \
		get_next_line.c \
		get_next_line_utils.c \
		display.c	\
		free.c	\
		moove.c \
		parse.c	\
		error.c	\
		utils.c	\
		win_conditions.c

SRCS_BONUS = bonus/so_long_bonus.c \
		bonus/get_next_line_bonus.c \
		bonus/get_next_line_utils_bonus.c \
		bonus/display_bonus.c	\
		bonus/free_bonus.c	\
		bonus/moove_bonus.c \
		bonus/parse_bonus.c	\
		bonus/error_bonus.c	\
		bonus/utils_bonus.c	\
		bonus/utils_bonus2.c	\
		bonus/win_conditions_bonus.c \

_GREY=	$'\033[1;30m
_RED=	$'\033[1;31m
_GREEN=	$'\033[1;32m
_YELLOW=$'\033[1;33m
_BLUE=	$'\033[1;34m
_PURPLE=$'\033[1;35m
_CYAN=	$'\033[1;36m
_WHITE=	$'\033[1;37m

OBJ = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
MLX = -lmlx -Lmlx_linux -Imlx_linux -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(OBJ)
		@echo "$(_YELLOW)[Compilation ongoing ...]"
		@echo "$(_GREEN)[Compilation finished]"
		@make -C mlx_linux all
			$(CC) $(CFLAGS) $(OBJ) $(MLX) -o $(NAME)
		@echo "$(_CYAN)[Executable created]"
		@echo [Name : so_long]

%.o: %.c
	$(CC) $(CFLAGS) -MMD -I includes -Imlx_linux -O3 -c $< -o $@
	
clean:
	@rm -f $(OBJ) $(DEPS)
	@rm -f $(OBJS_BONUS) $(DEPS_BONUS)
	@echo "$(_RED)[All .o removed]"

fclean: clean
	@rm -f $(NAME)
	@echo "$(_RED)[Executable removed]"

git : fclean
	git add --all
	git commit 
	git push 
	
re: fclean all

bonus : $(OBJS_BONUS)
	   @echo "$(_YELLOW)[Compilation ongoing ...]"
	   @echo "$(_GREEN)[Compilation finished]"
	   @make -C mlx_linux all
			$(CC) $(OBJS_BONUS) $(MLX) -o $(NAME)
	   @echo "$(_CYAN)[Executable created]"
	   @echo [Name : so_long]

-include $(DEPS)
-include $(DEPS_BONUS)

.PHONY : all bonus clean fclean re git bonus
