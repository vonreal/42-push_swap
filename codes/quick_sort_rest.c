/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_rest.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 17:46:47 by jna               #+#    #+#             */
/*   Updated: 2021/06/24 20:57:16 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_num(t_stack *stack, int cnt)
{
	int		i;
	int		max;

	i = stack->top;
	max = stack->list[i];
	while (cnt - 1 > 0)
	{
		if (max < stack->list[i - 1])
			max = stack->list[i- 1];
		cnt--;
		i--;
	}
	return (max);
}

static int	get_min_num(t_stack *stack, int cnt)
{
	int		i;
	int		min;

	i = stack->top;
	min = stack->list[i];
	while (cnt - 1 > 0)
	{
		if (min > stack->list[i - 1])
			min = stack->list[i - 1];
		cnt--;
		i--;
	}
	return (min);
}

static int	get_idx(t_info *infos, int max, int min)
{
	int		i;
	int		start;
	int		end;

	i = 0;
	while (1)
	{
		if (infos->aligned[i] == min)
			start = i;
		if (infos->aligned[i] == max)
		{
			end = i;
			break ;
		}
		i++;
	}
	return ((start + end) / 2);
}

void		set_pivot(t_stack *a, t_stack *b, t_info *infos, int cnt)
{
	int		max;
	int		min;
	int		idx;

	max = get_max_num(b, cnt);
	min = get_min_num(b, cnt);
	idx = get_idx(infos, max, min);
	infos->midian = 0;
	set_infos(idx, infos);
}

int	sort_a_stack_two(t_stack *a, t_stack *b, t_info *infos, int cnt)
{
	int		i;

	if (is_aligned(a) || a->top <= 2)
		return (cnt);
	i = a->top;
	while (i > 0)
	{
		if (!is_aligned(a))
		{
			if (a->list[a->top] == infos->pivot)
				sa(a);
		}
		if (a->list[a->top] < infos->pivot)
		{
			pb(b, a);
			if (b->list[b->top] < b->list[b->top - 1])
				sb(b);
			cnt++;
		}
		else if (a->list[a->top] > infos->pivot)
			ra(a);
		i--;
	}
	//  set_pivot(a, b, infos, cnt);
	// sort_a_stack_two(a, b, infos, cnt);
	return (cnt);
}

void		quick_sort_rest(t_stack *a, t_stack *b, t_info *infos, int cnt)
{
	int		i;
	
	set_pivot(a, b, infos, cnt);
	if (cnt <= 2)
	{
		if (cnt == 2)
		{
			if (b->list[b->top] < b->list[b->top - 1])
				sb(b);
		}
		while (cnt > 0)
		{
			pa(a, b);
			cnt--;
		}
		return ;
	}
	i = cnt;
	while (i > 0)
	{
		pa(a, b);
		i--;
	}
	sort_a_stack_two(a, b, infos, cnt);
	printf("cnt is %d\n", cnt);
	printf("infos->fivot: %d\n", infos->pivot);
	print_stack(*a, *b);
	//quick_sort_rest(a, b, infos, cnt);
}

void		set_pivot_b(t_stack *a, t_stack *b, t_info *infos, int cnt)
{
	int		max;
	int		min;
	int		idx;

	max = get_max_num(a, cnt);
	min = get_min_num(a, cnt);
	idx = get_idx(infos, max, min);
	infos->midian = 0;
	set_infos(idx, infos);
}

void		quick_sort_rest_b(t_stack *a, t_stack *b, t_info *infos, int cnt)
{
	int		i;

	set_pivot_b(a, b, infos, cnt);
	if (cnt <= 2)
	{
		if (cnt == 2)
		{
			if (b->list[b->top] < b->list[b->top - 1])
				sb(b);
		}
		while (b->top >= 0)
			pa(a, b);
		return ;
	}
	while (cnt > 0)
	{
		pb(b, a);
		cnt--;
	}
	i = b->top;
	while (i > 0)
	{
		if (!is_descending_order(b))
		{
			if (b->list[b->top] == infos->pivot)
				sb(b);
		}
		if (b->list[b->top] > infos->pivot)
		{
			pa(a, b);
			cnt++;
		}
		else if (b->list[b->top] < infos->pivot)
			rb(b);
		i--;
	}
	quick_sort_rest_b(a, b, infos, cnt);
}
