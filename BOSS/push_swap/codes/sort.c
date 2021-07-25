/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 16:00:59 by jna               #+#    #+#             */
/*   Updated: 2021/07/25 12:53:00 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	is_rest_bigger(t_stack *a, int median)
{
	int		i;

	i = a->top;
	while (i >= 0)
	{
		if (a->list[i] <= median)
			return (false);
		i--;
	}
	return (true);
}

static bool	is_sorted(t_stack *stack, int *ascending)
{
	int		i;
	int		j;

	i = stack->top;
	j = 0;
	while (i >= 0)
	{
		if (!(stack->list[i] == ascending[j]))
			return (false);
		i--;
		j++;
	}
	return (true);
}	

static void	a_to_b(t_stack *a, t_stack *b, t_info *infos)
{
	int		i;

	i = a->top + 1;
	if (a->top < 3)
	{
		sort_end(a);
		return ;
	}
	set_median(a, infos, a->top + 1);
	infos->chunks.top++;
	while (--i >= 0)
	{
		if (a->list[a->top] <= infos->median)
		{
			pb(b, a);
			infos->chunks.list[infos->chunks.top] += 1;
		}
		else
		{
			if (is_rest_bigger(a, infos->median))
				break ;
			ra(a);
		}
	}
	a_to_b(a, b, infos);
}

static void	b_to_a(t_stack *a, t_stack *b, t_info *infos)
{
	int		chunk;

	if (infos->chunks.top < 0)
		return ;
	chunk = infos->chunks.list[infos->chunks.top];
	if (chunk == 2)
	{
		sort_top_three_rest(a, b);
		infos->chunks.top--;
	}
	else if (chunk == 3)
	{
		sort_top_three(a, b);
		infos->chunks.top--;
	}
	else
	{
		set_median(b, infos, chunk);
		divide_chunk(a, b, infos, chunk);
	}
	b_to_a(a, b, infos);
}

void	sort(t_stack *a, t_stack *b, t_info *infos)
{
	if (is_sorted(a, infos->ascending))
		return ;
	else
	{
		a_to_b(a, b, infos);
		b_to_a(a, b, infos);
	}
}
