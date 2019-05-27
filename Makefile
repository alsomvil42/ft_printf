# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/26 17:04:04 by alsomvil          #+#    #+#              #
#    Updated: 2018/04/26 00:43:19 by alsomvil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c \
	  ft_apply.c \
	  ft_conversion.c \
	  ft_convertpxou.c \
	  ft_convertp.c \
	  ft_removestruct.c \
	  ft_convertdi.c \
	  ft_putstr_minu.c \
	  ft_applyoptiond.c \
	  ft_applyoptiono.c \
	  ft_applyoptionx.c \
	  ft_printuni.c \
	  ft_converts.c \
	  ft_checkoptionchart.c \
	  ft_convertpourcent.c \
	  ft_printuni_two.c \
	  ft_converts_one.c \

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

%.o: %.c
	gcc $(FLAGS) -c -I include -I libft $^ -o $@

clean :
	make clean -C libft
	rm -rf $(OBJ)

fclean: clean
	make fclean -C libft
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re norme
