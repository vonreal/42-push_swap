/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_unit_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 17:58:47 by jna               #+#    #+#             */
/*   Updated: 2021/07/25 13:21:58 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max(t_stack *b)
{
	int		i;
	int		max;

	i = b->top - 1;
	max = b->top;
	while (i >= b->top - 2)
	{
		if (b->list[max] < b->list[i])
			max = i;
		i--;
	}
	return (max);
}

int	call_ra(t_stack *a)
{
	ra(a);
	return (1);
}

void	call_rra_a(t_stack *a, int calls_ra)
{
	while (calls_ra > 0)
	{
		rra(a);
		calls_ra--;
	}
}

void	sort_top_three_b(t_stack *a, t_stack *b)
{
	rb(b);
	rb(b);
	pa(a, b);
	rrb(b);
	rrb(b);
}
