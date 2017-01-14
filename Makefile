# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/21 02:48:50 by kbensado          #+#    #+#              #
#    Updated: 2017/01/14 04:08:36 by kbensado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =		gcc

NAME =		kbensado.filler

CFLAGS =	-Wextra -Wall -Werror -g -Weverything

SRC =		algo.c launch.c macro.c main.c seed.c set.c solve.c

OBJ =		$(SRC:.c=.o)

all:		$(NAME)

$(NAME):		$(OBJ)
			@make -C libft
			@make -C ft_printf
			@$(CC) $(CFLAGS) -I libft -c $(SRC)
			@$(CC) $(CFLAGS) -I ft_printf -c $(SRC)
			@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L libft -lft -L ft_printf -lftprintf
			mv kbensado.filler players
			@echo ... Compilation of filler DONE !

clean:
			@rm -rf $(OBJ)
			@make clean -C libft
			@make clean -C ft_printf
			@echo ... Objects clean in filler !

fclean:		clean
			@rm -rf $(NAME)
			@make fclean -C libft
			@make fclean -C ft_printf
			@echo ... Name clean in filler !

re:			fclean all
			@echo ... filler retry !


.PHONY: all, re, fclean, clean
