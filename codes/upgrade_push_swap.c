/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upgrade_push_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 19:53:42 by jna               #+#    #+#             */
/*   Updated: 2021/07/05 15:21:22 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_aligned(t_stack *stack, int *aligned)
{
	int		i;
	int		j;

	i = stack->top;
	j = 0;
	while (i >= 0)
	{
		if (!(stack->list[i] == aligned[j]))
			return (false);
		i--;
		j++;
	}
	return (true);
}

int		get_idx_aligned(int target, t_info *infos)
{
	int		i;

	i = 0;
	while (1)
	{
		if (target == infos->aligned[i])
			break ;
		i++;
	}
	return (i);
}

int		get_max_num_idx(t_stack *stack, t_info *infos, int end)
{
	int		i;
	int		max;

	i = stack->top - 1;
	max = stack->top;
	while (i >= end)
	{
		if (stack->list[max] < stack->list[i])
			max = i;
		i--;
	}
	max = get_idx_aligned(stack->list[max], infos);
	return (max);
}

int		get_min_num_idx(t_stack *stack, t_info *infos, int end)
{
	int		i;
	int		min;

	i = stack->top - 1;
	min = stack->top;
	while (i >= end)
	{
		if (stack->list[min] > stack->list[i])
			min = i;
		i--;
	}
	min = get_idx_aligned(stack->list[min], infos);
	return (min);
}

void	set_calls(t_call *calls)
{
	calls->ra = 0;
	calls->rb = 0;
	calls->pa = 0;
	calls->pb = 0;
}

void	set_pivot(t_stack *stack, t_info *infos, int end)
{
	int		max;
	int		min;

	max = get_max_num_idx(stack, infos, end);
	min = get_min_num_idx(stack, infos, end);
	infos->midian = (max + min) / 2;
	infos->pivot = infos->aligned[infos->midian];
	set_calls(&infos->calls);
}

void	b_to_a(t_stack *a, t_stack *b, t_info *infos, int size)
{
	int		i;
	
	i = 0;
	if (size == 1)
	{
		pa(a);
		return ;
	}
	set_pivot(b, infos, size);
	while (i <= size)
	{
		if (b->top > infos->pivot)
		{
			rb(b);
			infos->calls.rb++;
		}
		else
		{
			pa(a, b);
			infos->calls.pa++;
		}
		i++;
	}
	i = 0;
	while (i <= infos->calls.ra)
	{
		rra(a);
		i++;
	}
	a_to_b(a, b, infos, infos->calls.pa);
	b_to_a(a, b, infos, infos->calls.pb);
}

void	a_to_b(t_stack *a, t_stack *b, t_info *infos, int size)
{
	int		i;

	i = 0;
	if (size == 1)
		return ;
	set_pivot(a, infos, size);
	while (i <= size)
	{
		if (a->top > infos->pivot)
		{
			ra(a);
			infos->calls.ra++;
		}
		else
		{
			pb(b, a);
			infos->calls.pb++;
		}
		i++;
	}
	i = 0;
	while (i <= call_ra)
	{
		rra(a);
		i++;
	}
	a_to_b(a, b, infos, infos->calls.ra);
	b_to_a(a, b, infos, infos->calls.pb);
}

void	sort(t_stack *a, t_stack *b, t_info *infos)
{
	set_pivot(a, infos, 0);
	a_to_b(a, b, infos, a->top);
}


void	push_swap(t_stack *a, t_stack *b, t_info *infos)
{
	if (is_aligned(a, infos->aligned))
		return ;
	else
		sort(a, b, infos);
}
