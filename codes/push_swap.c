/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 16:21:29 by jna               #+#    #+#             */
/*   Updated: 2021/06/24 15:25:02 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	in_a_stack(t_stack *a, t_stack *b, int *datas, int mid)
{
	int		i;
	int		count;
	int		pivot;

	if (is_aligned(a))
		return ;
	i = a->top;
	count = 0;
	pivot = datas[mid];
	while (i > 0)
	{
		if (!is_aligned(a))
		{
			if (a->list[a->top] == pivot)
				sa(a);
		}
		if (a->list[a->top] < pivot)
		{
			pb(b, a);
			count++;
		}
		else if (a->list[a->top] > pivot)
			ra(a);
		i--;
	}
	while (count > 0)
	{
		pa(a, b);
		count--;
	}
}

static void	in_b_stack(t_stack *a, t_stack *b, int pivot)
{
	int			i;
	int			count;

	if (is_descending_order(b))
		return ;
	i = b->top;
	count= 0;
	while (i > 0)
	{
		if (!is_descending_order(b))
		{
			if (b->list[b->top] == pivot)
				sb(b);
		}
		if (b->list[b->top] > pivot)
		{
			pa(a, b);
			count++;
		}
		else if (b->list[b->top] < pivot)
			rb(b);
		i--;
	}
	while (count > 0)
	{
		pb(b, a);
		count--;
	}
}

void		set_infos(int midian, t_info *infos)
{
	infos->midian += midian;
	infos->pivot = infos->aligned[infos->midian];
}

void		push_swap(t_stack *a, t_stack *b, t_info *infos)
{
	if (is_aligned(a))
		return ;
	infos->midian = 0;
	set_infos(a->top / 2, infos);
	quick_sort(a, b, infos);
	// in_a_stack(a, b, datas, mid + mid / 2);
	// in_b_stack(a, b, datas[mid/2]);
}
