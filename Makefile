# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: root <jna@student.42.fr>                   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/26 13:18:14 by root              #+#    #+#              #
#    Updated: 2021/05/26 13:32:01 by root             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

CC	= gcc -Wall -Wextra -Werror

SRCS	= ./codes/main.c \

all:	$(NAME)

$(NAME):
	$(CC) $(SRCS) -o $(NAME)

clean:
	rm -f *.o

fclean:	clean
	rm -f $(NAME)

re:	fclean all
