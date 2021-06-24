/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 14:34:11 by jna               #+#    #+#             */
/*   Updated: 2021/06/24 20:49:36 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	sort_rest(t_stack *stack)
{
	int	top;

	top = stack->top;
	if (stack->list[top] > stack->list[top - 1])
		sa(stack);
}

static int	get_big_num_index(t_stack *stack)
{
	int		i;
	int		idx;

	i = 1;
	idx = 0;
	while (i <= stack->top)
	{
		if (stack->list[idx] < stack->list[i])
			idx = i;
		i++;
	}
	return (idx);
}

static void	sort_three(t_stack *stack)
{
	int		idx;
	
	idx = get_big_num_index(stack);
	if (idx == stack->top)
		ra(stack);
	else if (idx == stack->top - 1)
		rra(stack);
	sort_rest(stack);
}

void	sort_a_stack(t_stack *a, t_stack *b, t_info *infos, int cnt)
{
	int		i;

	if (is_aligned(a) || a->top <= 2)
	{
		if (a->top <= 2)
			sort_three(a);
		quick_sort_rest(a, b, infos, cnt);
		return ;
	}
	set_infos(a->top / 2, infos);
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
	sort_a_stack(a, b, infos, cnt);
}

static void	sort_rest_b(t_stack *stack)
{
	int	top;

	top = stack->top - 1;
	if (stack->list[top] < stack->list[top - 1])
	{
		rb(stack);
		sb(stack);
		rrb(stack);
	}
}

static void	sort_three_b(t_stack *stack)
{
	int		idx;
	
	idx = get_big_num_index(stack);
	if (idx == 0)
		rrb(stack);
	else if (idx == stack->top - 1)
		rb(stack);
	sort_rest_b(stack);
}

static void	sort_b_stack(t_stack *a, t_stack *b, t_info *infos, int cnt)
{
	int		i;

	if (is_descending_order(b) || b->top <= 2)
	{
		if (b->top <= 2)
			sort_three_b(b);
		quick_sort_rest_b(a, b, infos, cnt);
		return ;
	}
	infos->midian = 0;
	set_infos(b->top / 2, infos);
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
			if (a->list[a->top] > a->list[a->top - 1])
				sa(a);
			cnt++;
		}
		else if (b->list[b->top] < infos->pivot)
			rb(b);
		i--;
	}
	sort_b_stack(a, b, infos, cnt);
}

void		quick_sort(t_stack *a, t_stack *b, t_info *infos)
{
	int		i;
	int		cnt;

	i = a->top;
	while (i > 0)
	{
		if (a->list[a->top] == infos->pivot)
			sa(a);
		if (a->list[a->top] < infos->pivot)
			pb(b, a);
		else if (a->list[a->top] > infos->pivot)
			ra(a);
		i--;
	}
	sort_a_stack(a, b, infos, 0);
	// quick_sort_rest(a, b, infos, cnt);
	// infos->midian = 0;
	//sort_b_stack(a, b, infos, 0);
}
