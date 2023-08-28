# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabdelsa <mabdelsa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/05 12:01:23 by mabdelsa          #+#    #+#              #
#    Updated: 2023/08/07 14:45:57 by mabdelsa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c print_char_string.c print_decimal.c print_hexa.c


OBJS	= $(SRC:.c=.o)

NAME	= libftprintf.a
AR		= ar rcs
RM		= rm -f
GCC		= cc
CFLAGS	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re