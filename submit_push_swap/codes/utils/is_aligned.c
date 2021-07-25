/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_aligned.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 22:31:47 by jna               #+#    #+#             */
/*   Updated: 2021/07/11 22:31:47 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_rest_bigger(t_stack *a, int pivot)
{
	int		i;

	i = a->top;
	while (i >= 0)
	{
		if (a->list[i] <= pivot)
			return (false);
		i--;
	}
	return (true);
}

bool	is_aligned(t_stack *stack, int *aligned)
{
	int		i;
	int		j;

	i = stack->top;
	j = 0;
	while (i >= 0)
	{
		if (!(stack->list[i] == aligned[j]))
			return (false);
		i--;
		j++;
	}
	return (true);
}
