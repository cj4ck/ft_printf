# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 16:10:12 by cjackows          #+#    #+#              #
#    Updated: 2022/06/22 16:31:56 by cjackows         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =libftprintf.a

src = main.c

USR_LIB = libft.a
USR_LIB_PATH = ./libft

OBJ = $(src:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I.

NAME: all
all: $(NAME)
$(NAME):	$(OBJ) $(USR_LIB_PATH)
	ar rcs $(NAME) $^;

#$(USR_LIB):
#	@echo
#	cd ../libft; make all; cp libft.a ../src; cd ../src;

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY:	all clean fclean re bonus