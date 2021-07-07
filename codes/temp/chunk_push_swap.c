/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 10:49:31 by jna               #+#    #+#             */
/*   Updated: 2021/07/07 07:17:21 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_index(t_stack *stack, int target)
{
	int		i;

	i = 0;
	while (i <= stack->top)
	{
		if (stack->list[i] == target)
			return (i);
		i++;
	}	
	return (0);
}

void		divide_chunk(t_stack *a, t_stack *b, int *aligned, int size)
{
	int		i;
	int		j;
	int		k;
	int		idx;
	int		limit;

	if (size == 5)
		limit = 20;
	if (size == 10)
		limit = 50;
	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (j < limit)
		{
			idx = find_index(a, aligned[k]);
			if (idx <= (a->top / 2))
			{
				while (idx + 1 > 0)
				{
					rra(a);
					idx--;
				}
				pb(b, a);
			}
			else if (idx > (a->top / 2))
			{
				while (idx < a->top)
				{
					ra(a);
					idx++;
				}
				pb(b, a);
			}
			k++;
			j++;
		}
		i++;
	}
}

void		sort(t_stack *a, t_stack *b, t_info *infos)
{
	int		i;

	i = 0;
	if (a->size == 100)
	{
		divide_chunk(a, b, infos->aligned, 5);
		while (i < 100)
		{
			pa(a, b);
			i++;
		}	
	}
	if (a->size == 500)
	{
		divide_chunk(a, b, infos->aligned, 10);
		i = 0;
		while (i < 500)
		{
			pa(a, b);
			i++;
		}
	}
}

void		push_swap(t_stack *a, t_stack *b, t_info *infos)
{
	sort(a, b, infos);
}
