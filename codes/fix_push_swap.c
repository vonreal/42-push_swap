/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_push_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 19:53:42 by jna               #+#    #+#             */
/*   Updated: 2021/07/06 11:35:37 by jna              ###   ########.fr       */
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

int		get_max_num_idx(t_stack *stack, t_info *infos, int size)
{
	int		i;
	int		max;

	i = stack->top - 1;
	max = stack->top;
	while (size > 1)
	{
		if (stack->list[max] < stack->list[i])
			max = i;
		size--;
		i--;
	}
	max = get_idx_aligned(stack->list[max], infos);
	return (max);
}

int		get_min_num_idx(t_stack *stack, t_info *infos, int size)
{
	int		i;
	int		min;

	i = stack->top - 1;
	min = stack->top;
	while (size > 1)
	{
		if (stack->list[min] > stack->list[i])
			min = i;
		i--;
		size--;
	}
	min = get_idx_aligned(stack->list[min], infos);
	return (min);
}

void	set_pivot(t_stack *stack, t_info *infos, int size)
{
	int		max;
	int		min;

	max = get_max_num_idx(stack, infos, size);
	min = get_min_num_idx(stack, infos, size);
	infos->midian = (max + min) / 2;
	infos->pivot = infos->aligned[infos->midian];
}

void	a_to_b_rra(t_stack *a, t_stack *b, t_info *infos, int size)
{
	int		i;
	int		calls_ra;

	i = 0;
	calls_ra = 0;
	if (size == 1)
		return ;
	set_pivot(a, infos, size);
	while (i < size)
	{
		if (a->list[a->top] > infos->pivot)
		{
			ra(a);
			calls_ra++;
		}
		else
			pb(b, a);
		i++;
	}
	i = 0;
	while (i < calls_ra)
	{
		rra(a);
		i++;
	}
	a_to_b_rra(a, b, infos, calls_ra);
}

void	b_to_a(t_stack *a, t_stack *b, t_info *infos)
{
	int		i;
	int		calls_pa;

	i = 0;
	calls_pa = 0;
	if (b->top == 0)
	{
		pa(a, b);
		return ;
	}
	set_pivot(b, infos, b->top + 1);
	while (i < b->top + 1)
	{
		if (b->list[b->top] < infos->pivot)
			rb(b);
		else
		{
			pa(a, b);
			calls_pa++;
		}
		i++;
	}
	a_to_b_rra(a, b, infos, calls_pa);
	b_to_a(a, b, infos);
}

void	a_to_b(t_stack *a, t_stack *b, t_info *infos, int size)
{
	int		i;
	int		calls_ra;

	i = 0;
	calls_ra = 0;
	if (size == 1)
		return ;
	set_pivot(a, infos, size);
	while (i < size)
	{
		if (a->list[a->top] > infos->pivot)
		{
			ra(a);
			calls_ra++;
		}
		else
			pb(b, a);
		i++;
	}
	a_to_b(a, b, infos, calls_ra);
}

void	sort(t_stack *a, t_stack *b, t_info *infos)
{
	a_to_b(a, b, infos, a->top + 1);
	b_to_a(a, b, infos);
}


void	push_swap(t_stack *a, t_stack *b, t_info *infos)
{
	if (is_aligned(a, infos->aligned))
		return ;
	else
		sort(a, b, infos);
}
