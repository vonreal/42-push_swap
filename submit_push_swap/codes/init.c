/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 01:27:58 by jna               #+#    #+#             */
/*   Updated: 2021/07/25 01:27:58 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	init_stack(int size)
{
	t_stack stack;

	if (size != 0)
	{
		stack.list = (int *)allocate(sieof(int) * size);
		stack.size = size;
	}
	else
	{
		stack.list = NULL;
		stack.size = 0;
	}
	stack.top = -1;
	return (stack);
}

t_info	init_info(t_stack *a)
{
	t_info infos;

	infos.ascending = NULL;
	infos.mid_idx = 0;
	infos.midian = 0;
	infos.chunks = init_stack(a->size);
	return (infos);
}

void	init(t_stack *a, t_stack *b, t_info *infos)
{
	b = init_stack(a->size);
	infos = init_info(a);
}
