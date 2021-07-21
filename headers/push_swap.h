/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 13:35:26 by root              #+#    #+#             */
/*   Updated: 2021/07/11 14:03:27 by jna              ###   ########.fr       */
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
bool			is_integer(char *str, int *size);
t_stack			push_value(int size, char **src);
void			*allocate(int size, int length);
t_stack			init_stack(int size);
void			push_swap(t_stack *a, t_stack *b, t_info *infos);
void			sort_three(t_stack *stack);
void			sort_five(t_stack *a, t_stack *b);
void			b_to_a(t_stack *a, t_stack *b, t_info *infos, int action);
void			b_to_a_five_hun(t_stack *a, t_stack *b, t_info *infos, int action);
void			divide_b(t_stack *a, t_stack *b, t_info *infos, int size);


/*
**		actions/
*/
void			action_six(t_stack *a, t_stack *b, t_info *infos);
void			action_seven(t_stack *a, t_stack *b, t_info *infos);
void			action_thirteen(t_stack *a, t_stack *b, t_info *infos);
void			action_twentyfive(t_stack *a, t_stack *b, t_info *infos);
void			action_twentyfour(t_stack *a, t_stack *b, t_info *infos);
void			action_four(t_stack *a, t_stack *b, t_info *infos);
void			action_eight(t_stack *a, t_stack *b, t_info *infos);
void			action_sixteen(t_stack *a, t_stack *b, t_info *infos);
void			action_thirty_one(t_stack *a, t_stack *b, t_info *infos);
void			action_thirty_two(t_stack *a, t_stack *b, t_info *infos);
void			action_sixty_three(t_stack *a, t_stack *b, t_info *infos);
void			action_one_hun_twnety_five(t_stack *a, t_stack *b, t_info *infos);
void			action_two_hun_fifty_one(t_stack *a, t_stack *b, t_info *infos);

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
void			free_and_nulls(char **str);
int				*bubble_sort(t_stack *stack);
bool			is_aligned(t_stack *stack, int *aligned);
bool			is_rest_bigger(t_stack *a, int pivot);
void			set_pivot(t_stack *stack, t_info *infos, int size);
void			sort_top_three(t_stack *a, t_stack *b);
void			sort_top_three_a(t_stack *a, t_stack *b);
void			sort_top_three_rest(t_stack *a, t_stack *b);
void			sort_top_three_rest_a(t_stack *a, t_stack *b);
void			sort_top_a(t_stack *a, t_stack *b, t_info *infos, int size);
void			sort_end(t_stack *a);

#endif
