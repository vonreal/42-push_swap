/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_median.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 22:35:05 by jna               #+#    #+#             */
/*   Updated: 2021/07/25 16:53:34 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_idx_aligned(int target, t_info *infos)
{
	int		i;

	i = 0;
	while (1)
	{
		if (target == infos->ascending[i])
			break ;
		i++;
	}
	return (i);
}

static int	get_max_num_idx(t_stack *stack, t_info *infos, int size)
{
	int		i;
	int		max;

	i = stack->top - 1;
	max = stack->top;
	while (size > 1)
	{
		if (stack->list[max] < stack->list[i])
			max = i;
		size--;
		i--;
	}
	max = get_idx_aligned(stack->list[max], infos);
	return (max);
}

static int	get_min_num_idx(t_stack *stack, t_info *infos, int size)
{
	int		i;
	int		min;

	i = stack->top - 1;
	min = stack->top;
	while (size > 1)
	{
		if (stack->list[min] > stack->list[i])
			min = i;
		i--;
		size--;
	}
	min = get_idx_aligned(stack->list[min], infos);
	return (min);
}

void	set_median(t_stack *stack, t_info *infos, int size)
{
	int		max;
	int		min;

	max = get_max_num_idx(stack, infos, size);
	min = get_min_num_idx(stack, infos, size);
	infos->mid_idx = (max + min) / 2;
	infos->median = infos->ascending[infos->mid_idx];
}
