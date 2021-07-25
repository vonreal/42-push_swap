# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/24 20:34:06 by jna               #+#    #+#              #
#    Updated: 2021/07/24 20:34:06 by jna              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

CC		=	gcc -Wall -Wextra -Werror

SRCS	=	./codes/main.c \
			./codes/vaildation.c \

INCLUDE =	./headers

all:		$(NAME)

$(NAME):
			$(CC) $(SRCS) $(INCLUDE) -o $(NAME)

clean:
			rm -f *.o

fclean:		clean
			rm -f $(NAME)

re:			fclean all