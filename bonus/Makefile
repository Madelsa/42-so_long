# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabdelsa <mabdelsa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/22 14:03:21 by mabdelsa          #+#    #+#              #
#    Updated: 2023/09/16 15:54:14 by mabdelsa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC	=	so_long.c ./map_checks/map_checks.c ./map_rendering/render_map.c ./map_checks/create_map_copy.c \
		./move_player/move_player.c ./map_checks/get_original_map.c ./map_checks/map_checks_recursion.c \
		./map_rendering/destroy_win_event.c

NAME = so_long
AR = ar rs
RM = rm -f
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -L../mandatory/mlx -lmlx -framework OpenGL -framework AppKit

LIBFT_P = ../mandatory/libft/
LIBFT_AR = ../mandatory/libft/libft.a

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -I ./mlx -c $< -o $@

$(NAME): $(OBJS) $(LIBFT_AR)
	$(CC) $(OBJS) $(MLX_FLAGS) $(LIBFT_AR) -o $(NAME)

$(LIBFT_AR):
	make -C $(LIBFT_P)

clean:
	make -C $(LIBFT_P) clean
	$(RM) $(OBJS)

fclean: clean
	make -C $(LIBFT_P) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

