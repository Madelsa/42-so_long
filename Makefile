# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabdelsa <mabdelsa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/22 14:03:21 by mabdelsa          #+#    #+#              #
#    Updated: 2023/08/28 12:48:17 by mabdelsa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = so_long.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c\
		map_checks.c utils.c

PRINTF_P = ./ft_printf/
PRINTF_AR = ./ft_printf/libftprintf.a

NAME 	= so_long
AR		= ar rs
RM		= rm -f
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

OBJS	= $(SRC:.c=.o)

all: $(NAME)

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -I ./mlx -c $< -o $@

$(NAME): $(OBJS) $(PRINTF_AR)
	cp $(PRINTF_AR) $(NAME)
	$(CC) $(OBJS) $(MLX_FLAGS) $(PRINTF_AR) -o $(NAME)

$(PRINTF_AR):
	make -C $(PRINTF_P)

clean:
	make fclean -C $(PRINTF_P)
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re