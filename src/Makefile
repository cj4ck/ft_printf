# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 16:10:12 by cjackows          #+#    #+#              #
#    Updated: 2022/07/14 13:55:14 by cjackows         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =libftprintf.a

src = core.c utilities.c

USR_LIB = libft.a
USR_LIB_PATH = ./libft

OBJ:= $(src:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I. -I$(USR_LIB_PATH)

%.o : %.c
	$(CC) -c $^ $(CFLAGS) -o $@


NAME: all
all: $(NAME)
$(NAME): $(OBJ) $(USR_LIB)
	ar rcs $(NAME) $(OBJ)

$(USR_LIB):
	@echo
	cd ../libft; make; cp libft.a ../src;
	cd ../src;
	mv libft.a $(NAME);

clean:
	rm -rf $(OBJ)
	cd ../libft; make clean; cd ../src

fclean: clean
	rm -rf $(NAME)
	cd ../libft; make fclean; cd ../src

re: fclean all

.PHONY:	all clean fclean re bonus