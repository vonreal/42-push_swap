/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_top_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 18:09:02 by jna               #+#    #+#             */
/*   Updated: 2021/07/25 18:47:28 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_top_three_rest_a(t_stack *a)
{
	if (a->list[a->top] > a->list[a->top - 1])
		sa(a);
}

static void	sort_top_three_a(t_stack *a)
{
	int		max;

	max = get_max(a);
	if (max == a->top)
	{
		sa(a);
		ra(a);
		sa(a);
		rra(a);
		sort_top_three_rest_a(a);
	}
	else if (max == a->top - 1)
	{
		ra(a);
		sa(a);
		rra(a);
		sort_top_three_rest_a(a);
	}
	else if (max == a->top - 2)
		sort_top_three_rest_a(a);
}

static void	sort_top_a_end(t_stack *a, int size)
{
	if (size == 3)
		sort_top_three_a(a);
	else if (size == 2)
		sort_top_three_rest_a(a);
	return ;
}

static void	call_rrb_a(t_stack *a, int calls_ra)
{
	while (calls_ra > 0)
	{
		rra(a);
		calls_ra--;
	}
}

void	sort_top_a(t_stack *a, t_stack *b, t_info *infos, int size)
{
	int		i;
	int		calls_ra;

	i = -1;
	calls_ra = 0;
	set_median(a, infos, size);
	if (size <= 3)
	{
		sort_top_a_end(a, size);
		return ;
	}
	infos->chunks.top++;
	while (++i < size)
	{
		if (a->list[a->top] <= infos->median)
		{
			pb(b, a);
			infos->chunks.list[infos->chunks.top] += 1;
		}
		else
			calls_ra += call_ra(a);
	}
	call_rrb_a(a, calls_ra);
	sort_top_a(a, b, infos, calls_ra);
}
