/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 21:11:36 by jna               #+#    #+#             */
/*   Updated: 2021/07/25 19:56:03 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int		*list;
	int		top;
	int		size;
}				t_stack;

typedef struct s_info
{
	int		*ascending;
	int		mid_idx;
	int		median;
	t_stack	chunks;
}				t_info;

/*
**		codes/
*/
bool		is_valid(int *len, char **target, t_stack *stack);
void		free_and_null(char *str, char **strs);
void		init(t_stack *a, t_stack *b, t_info *infos);
void		init_stack(t_stack *stack, int size);
void		set_value(t_stack *a, t_stack *b, t_info *infos);
void		sort(t_stack *a, t_stack *b, t_info *infos);
void		end_of_use(t_stack *a, t_stack *b, t_info *infos);

/*
**		codes/instructions/
*/

void		sa(t_stack *a);
void		sb(t_stack *b);
void		ss(t_stack *a, t_stack *b);
void		pa(t_stack *a, t_stack *b);
void		pb(t_stack *b, t_stack *a);
void		ra(t_stack *a);
void		rb(t_stack *b);
void		rr(t_stack *a, t_stack *b);
void		rra(t_stack *a);
void		rrb(t_stack *b);
void		rrr(t_stack *a, t_stack *b);

/*
**		utils
*/
bool		is_num(char *str);
bool		is_range(int min, int max, long long num);
long long	get_num(char *str);
bool		error_msg(void);
void		*allocate(int size, int length);
void		bubble_sort(int *dst, t_stack *src);
int			count_elements(t_stack *stack);
void		sort_end(t_stack *stack);
void		sort_three(t_stack *stack);
void		set_median(t_stack *stack, t_info *infos, int size);
void		sort_top_three_rest(t_stack *a, t_stack *b);
void		sort_top_three(t_stack *a, t_stack *b);
int			get_max(t_stack *b);
void		divide_chunk(t_stack *a, t_stack *b, t_info *infos, int chunk);
void		sort_top_a(t_stack *a, t_stack *b, t_info *infos, int size);
int			call_ra(t_stack *a);
void		sort_five(t_stack *a, t_stack *b);

#endif
