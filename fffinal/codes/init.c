/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 15:11:53 by jna               #+#    #+#             */
/*   Updated: 2021/07/25 16:54:09 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *stack, int size)
{
	if (size == 0)
	{
		stack->list = NULL;
		stack->size = 0;
	}
	else
	{
		stack->list = (int *)allocate(sizeof(int), size);
		stack->size = size;
	}
	stack->top = -1;
}

static void	init_info(t_info *infos, t_stack *stack)
{
	infos->ascending = (int *)allocate(sizeof(int), stack->size);
	infos->mid_idx = 0;
	infos->median = 0;
	init_stack(&infos->chunks, stack->size);
}

void	init(t_stack *a, t_stack *b, t_info *infos)
{
	init_stack(a, b->size);
	init_info(infos, b);
}
