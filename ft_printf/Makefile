# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/26 17:04:04 by alsomvil          #+#    #+#              #
#    Updated: 2018/02/27 12:57:08 by alsomvil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c \
	  ft_checkoption.c \
	  ft_apply.c \
	  ft_conversion.c \
	  ft_convertpxou.c \
	  ft_converts.c \
	  ft_printuni.c

OBJ = $(SRC:.c=.o)
CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
all : $(NAME)

$(NAME): $(OBJ)
	ar rc ftprintf.a $(OBJ)
	make -C libft
	libtool libft/libft.a ftprintf.a -o $(NAME)
	rm -f ftprintf.a

%.o: src/%.c
	gcc -c -I include -I libft $^ -o $@

clean :
	make clean -C libft/
	rm -rf $(OBJ)

fclean: clean
	make fclean -C libft/
	rm -rf $(NAME)

re: fclean all

