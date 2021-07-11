/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_top_three.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 22:39:27 by jna               #+#    #+#             */
/*   Updated: 2021/07/11 22:39:27 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_top_three_rest(t_stack *a, t_stack *b)
{
	if (b->list[b->top] < b->list[b->top - 1])
		sb(b);
	pa(a, b);
	pa(a, b);
}

void	sort_top_three_rest_a(t_stack *a, t_stack *b)
{
	if (a->list[a->top] > a->list[a->top - 1])
		sa(a);
}

void	sort_top_three(t_stack *a, t_stack *b)
{
	int		i;
	int		j;
	int		max;

	i = b->top - 1;
	max = b->top;
	while (i >= b->top - 2)
	{
		if (b->list[max] < b->list[i])
			max = i;
		i--;
	}
	if (max == b->top)
	{
		pa(a, b);
		sort_top_three_rest(a, b);
	}
	else if (max == b->top - 1)
	{
		rb(b);
		pa(a, b);
		rrb(b);
		sort_top_three_rest(a, b);
	}
	else if (max == b->top - 2)
	{
		rb(b);
		rb(b);
		pa(a, b);
		rrb(b);
		rrb(b);
		sort_top_three_rest(a, b);
	}
}

void	sort_top_three_a(t_stack *a, t_stack *b)
{
	int		i;
	int		j;
	int		max;

	i = a->top - 1;
	max = a->top;
	while (i >= a->top - 2)
	{
		if (a->list[max] < a->list[i])
			max = i;
		i--;
	}
	if (max == a->top)
	{
		sa(a);
		ra(a);
		sa(a);
		rra(a);
		sort_top_three_rest_a(a, b);
	}
	else if (max == a->top - 1)
	{
		ra(a);
		sa(a);
		rra(a);
		sort_top_three_rest_a(a, b);

	}
	else if (max == a->top - 2)
		sort_top_three_rest_a(a, b);
}

void	sort_top_a(t_stack *a, t_stack *b, t_info *infos, int size)
{
	int		i;
	int		calls_ra;
	
	i = 0;
	calls_ra = 0;
	set_pivot(a, infos, size);
	if (size <= 3)
	{
		if (size == 3)
			sort_top_three_a(a, b);
		else if (size == 2)
			sort_top_three_rest_a(a, b);
		return ;
	}
	while (i < size)
	{
		if (a->list[a->top] <= infos->pivot)
			pb(b, a);
		else
		{
			ra(a);
			calls_ra++;
		}
		i++;
	}
	i = calls_ra;
	while (calls_ra > 0)
	{
		rra(a);
		calls_ra--;
	}
	sort_top_a(a, b, infos, i);
}
