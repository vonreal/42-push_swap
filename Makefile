# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/26 13:18:14 by root              #+#    #+#              #
#    Updated: 2021/07/07 09:02:54 by jna              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

CC		= gcc

SRCS	=	./codes/main.c							\
			./codes/push_swap.c						\
			./codes/push_value.c					\
			./codes/valid_arg.c						\
			./codes/sort_three.c					\
			./codes/sort_five.c						\
			./codes/sort_hun.c						\
			./codes/sort_five_hun.c					\
			./codes/actions/action_1.c				\
			./codes/actions/action_2.c				\
			./codes/actions/action_3.c				\
			./codes/utils/bubble_sort.c				\
			./codes/utils/count_elements.c			\
			./codes/utils/free_and_null.c			\
			./codes/utils/is_aligned.c				\
			./codes/utils/get_sign.c				\
			./codes/utils/set_pivot.c				\
			./codes/utils/sort_top_three.c			\
			./codes/instructions/swap.c				\
			./codes/instructions/push.c				\
			./codes/instructions/rotate.c			\
			./codes/instructions/reverse_rotate.c	\
			./codes/error/error_msg.c				\

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
