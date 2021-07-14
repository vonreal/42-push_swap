/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 22:29:48 by jna               #+#    #+#             */
/*   Updated: 2021/07/13 22:17:54 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	call_rrb(t_stack *b, int calls_rb)
{
	while (calls_rb > 0)
	{
		rrb(b)
		calls_rb--;
	}
}

void	divide_b(t_stack *a, t_stack *b, t_info *infos, int size)
{
	int		i;
	int		calls_rb;
	int		calls_pa;

	i = 0;
	calls_pa = 0;
	calls_rb = 0;
	while (i < size)
	{
		if (b->list[b->top] > infos->pivot)
		{
			pa(a, b);
			calls_pa++;
		}
		else
		{
			rb(b);
			calls_rb++;
		}
		i++;
	}
	sort_top_a(a, b, infos, calls_pa);
}

void	a_to_b(t_stack *a, t_stack *b, t_info *infos, int calls_pb)
{
	int		i;

	i = a->top;
	calls_pb = 0;
	if (a->top <= 2)
	{
		sort_end(a);
		return ;
	}
	set_pivot(a, infos, a->top + 1);
	while (i >= 0)
	{
		if (a->list[a->top] <= infos->pivot)
		{
			pb(b, a);
			calls_pb++;
		}
		else
		{
			if (is_rest_bigger(a, infos->pivot))
				break ;
			ra(a);
		}
		i--;
	}
	a_to_b(a, b, infos, calls_pb);
}

void	sort(t_stack *a, t_stack *b, t_info *infos)
{
	if (a->size == 100)
	{
		a_to_b(a, b, infos, 0);
		b_to_a(a, b, infos, 3);
	}
	else if (a->size == 500)
	{
		a_to_b(a, b, infos, 0);
		b_to_a_five_hun(a, b, infos, 4);
	}
}

void	push_swap(t_stack *a, t_stack *b, t_info *infos)
{
	if (is_aligned(a, infos->aligned))
		return ;
	else
	{
		if (a->top == 2)
			sort_three(a);
		else if (a->top == 4)
			sort_five(a, b);
		else
			sort(a, b, infos);
	}
}
