/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_top_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 18:09:02 by jna               #+#    #+#             */
/*   Updated: 2021/07/25 13:25:16 by jna              ###   ########.fr       */
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

static void	chunk_set(t_info *infos, int calls_pb)
{
	if (calls_pb != 0)
	{
		infos->chunks.top++;
		infos->chunks.list[infos->chunks.top] = calls_pb;
	}
}

void	sort_top_a(t_stack *a, t_stack *b, t_info *infos, int size)
{
	int		i;
	int		calls_ra;
	int		calls_pb;

	i = -1;
	calls_ra = 0;
	calls_pb = 0;
	set_median(a, infos, size);
	if (size <= 3)
	{
		sort_top_a_end(a, size);
		return ;
	}
	while (++i < size)
	{
		if (a->list[a->top] <= infos->median)
		{
			pb(b, a);
			calls_pb++;
		}
		else
			calls_ra += call_ra(a);
	}
	call_rra_a(a, calls_ra);
	chunk_set(infos, calls_pb);
	sort_top_a(a, b, infos, calls_ra);
}
