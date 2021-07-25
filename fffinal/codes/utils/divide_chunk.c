/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_chunk.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 18:02:04 by jna               #+#    #+#             */
/*   Updated: 2021/07/25 18:18:49 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	call_rrb(t_stack *b, int calls_rb)
{
	while (calls_rb > 0)
	{
		rrb(b);
		calls_rb--;
	}
}

void	divide_chunk(t_stack *a, t_stack *b, t_info *infos, int chunk)
{
	int		i;
	int		calls_rb;
	int		calls_pa;

	i = 0;
	calls_rb = 0;
	calls_pa = 0;
	while (i < chunk)
	{
		if (b->list[b->top] > infos->median)
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
	call_rrb(b, calls_rb);
	infos->chunks.list[infos->chunks.top] -= calls_pa;
	sort_top_a(a, b, infos, calls_pa);
}
