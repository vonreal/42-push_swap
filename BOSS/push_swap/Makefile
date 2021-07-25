# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/24 21:06:03 by jna               #+#    #+#              #
#    Updated: 2021/07/25 12:52:35 by jna              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

CC		=	gcc

FLAGS	=	-Wall -Wextra -Werror -g -fsanitize=address

SRCS	=	./codes/main.c \
			./codes/validation.c \
			./codes/init.c \
			./codes/set_value.c \
			./codes/sort.c \
			./codes/end_of_use.c \
			./codes/instructions/push.c \
			./codes/instructions/reverse_rotate.c \
			./codes/instructions/rotate.c \
			./codes/instructions/swap.c \
			./codes/utils/is_integer.c \
			./codes/utils/allocate.c \
			./codes/utils/error_msg.c \
			./codes/utils/bubble_sort.c \
			./codes/utils/count_elements.c \
			./codes/utils/sort_unit.c \
			./codes/utils/sort_unit_2.c \
			./codes/utils/divide_chunk.c \
			./codes/utils/sort_top_a.c \
			./codes/utils/set_median.c 

INCLUDE	=	./headers

SUBDIR	=	./libft

all:		$(NAME)

$(NAME):	Libft
			$(CC) $(FLAGS) $(SRCS) libft/*.c -I $(INCLUDE) -o $(NAME)

Libft:
			cd $(SUBDIR); $(MAKE)

clean:
			cd $(SUBDIR); $(MAKE) clean
			rm -f *.o

fclean:		clean
			cd $(SUBDIR); $(MAKE) fclean
			rm -f $(NAME)

re:			fclean all
