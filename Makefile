# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/26 13:18:14 by root              #+#    #+#              #
#    Updated: 2021/05/31 12:44:31 by jna              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

CC		= gcc

SRCS	=	./codes/main.c					\
			./codes/valid_arg.c			\
			./codes/push_value.c			\
			./codes/stack.c				\
			./codes/push_swap.c			\
			./codes/utils/get_sign.c		\
			./codes/utils/count_elements.c		\
			./codes/instructions/swap.c		\
			./codes/instructions/push.c		\
			./codes/instructions/rotate.c		\
			./codes/instructions/reverse_rotate.c	\
			./codes/error/error_msg.c		\

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
