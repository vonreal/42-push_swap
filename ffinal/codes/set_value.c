/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 15:33:41 by jna               #+#    #+#             */
/*   Updated: 2021/07/25 15:40:12 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_stack(t_stack *dst, t_stack *src)
{
	int		i;
	int		j;

	i = 0;
	j = src->size - 1;
	while (i < src->size)
	{
		dst->list[i] = src->list[j];
		i++;
		j--;
	}
	dst->top = src->size - 1;
}

static void	set_info(t_info *dst, t_stack *src)
{
	bubble_sort(dst->ascending, src);
}

void	set_value(t_stack *a, t_stack *b, t_info *infos)
{
	set_stack(a, b);
	set_info(infos, b);
}
