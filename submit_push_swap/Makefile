# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/24 21:06:03 by jna               #+#    #+#              #
#    Updated: 2021/07/25 01:12:25 by jna              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

CC		=	gcc

FLAGS	=	-Wall -Wextra -Werror -g -fsanitize=address

SRCS	=	./codes/main.c \
			./codes/validation.c \
			./codes/end_of_use.c \
			./codes/utils/is_integer.c \
			./codes/utils/allocate.c \
			./codes/utils/error_msg.c \

INCLUDE	=	./headers

SUBDIR	=	./libft

all:		$(NAME)

$(NAME):	Libft
			$(CC) $(SRCS) libft/*.c -I $(INCLUDE) -o $(NAME)

Libft:
			cd $(SUBDIR); $(MAKE)

clean:
			cd $(SUBDIR); $(MAKE) clean
			rm -f *.o

fclean:		clean
			cd $(SUBDIR); $(MAKE) fclean
			rm -f $(NAME)

re:			fclean all
