/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 14:56:22 by jna               #+#    #+#             */
/*   Updated: 2021/06/24 14:56:31 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_aligned(t_stack *stack)
{
	int		i;

	i = stack->top;
	while (i > 0)
	{
		if (!(stack->list[i] < stack->list[i - 1]))
			return (false);
		i--;
	}
	return (true);
}

bool	is_descending_order(t_stack *stack)
{
	int		i;

	i = stack->top;
	while (i > 0)
	{
		if (!(stack->list[i] > stack->list[i - 1]))
			return (false);
		i--;
	}
	return (true);
}
