# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/26 13:18:14 by root              #+#    #+#              #
#    Updated: 2021/05/27 02:53:30 by jna              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

CC		= gcc -Wall -Wextra -Werror

SRCS	=	./codes/main.c				\
			./codes/valid_arg.c			\
			./codes/push_value.c		\
			./codes/error/error_msg.c	\

INCLUDE	=	./headers

SUBDIR	= ./libft

all:	$(NAME)

$(NAME): Libft
		$(CC) $(SRCS) libft/*.c -I $(INCLUDE) -o $(NAME)
	
Libft:
	cd $(SUBDIR); $(MAKE)

clean:
	cd $(SUBDIR); $(MAKE) clean
	rm -f *.o

fclean:	clean
	cd $(SUBDIR); $(MAKE) fclean
	rm -f $(NAME)

re:	fclean all
