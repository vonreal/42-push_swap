/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 13:35:26 by root              #+#    #+#             */
/*   Updated: 2021/07/06 10:32:25 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include "../libft/libft.h"

# include <stdio.h>

typedef struct	s_stack
{
	int		*list;
	int		top;
	int		size;
}				t_stack;

typedef struct	s_info
{
	int		midian;
	int		pivot;
	int		*aligned;
}				t_info;


void			print_stack(t_stack a, t_stack b);
void			sort_a_stack(t_stack *a, t_stack *b, t_info *infos, int cnt);

/*
**		codes/
*/
void			valid_arg(int argc, char **argv);
t_stack			push_value(int size, char **src);
void			*allocate(int size, int length);
t_stack			init_stack(int size);
void			push_swap(t_stack *a, t_stack *b, t_info *infos);
void			sort_three(t_stack *stack);
void			a_to_b(t_stack *a, t_stack *b, t_info *infos, int size);

/*
**		temp/
*/
// void			set_infos(int midian, t_info *infos);
// void			quick_sort(t_stack *a, t_stack *b, t_info *infos);
// bool			is_aligned(t_stack *stack);
// bool			is_descending_order(t_stack *stack);
// void			quick_sort_rest(t_stack *a, t_stack *b, t_info *infos, int cnt);
// void			quick_sort_rest_b(t_stack *a, t_stack *b, t_info *infos, int cnt);

/*
**		codes/error/
*/
void			error_msg();

/*
**		codes/instructions/
*/
void			sa(t_stack *a);
void			sb(t_stack *b);
void			ss(t_stack *a, t_stack *b);
void			pa(t_stack *a, t_stack *b);
void			pb(t_stack *b, t_stack *a);
void			ra(t_stack *a);
void			rb(t_stack *b);
void			rr(t_stack *a, t_stack *b);
void			rra(t_stack *a);
void			rrb(t_stack *b);
void			rrr(t_stack *a, t_stack *b);

/*
**		codes/utils/
*/
int				get_sign(char c);
int				count_elements(t_stack *stack);
void			free_and_null_stack(t_stack *stack);
int				*bubble_sort(t_stack *stack);

#endif
