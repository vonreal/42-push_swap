/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 16:17:53 by jna               #+#    #+#             */
/*   Updated: 2021/06/28 16:19:20 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_rest(t_stack *stack)
{
	int	top;

	top = stack->top;
	if (stack->list[top] > stack->list[top - 1])
		sa(stack);
}

static int	get_big_num_index(t_stack *stack)
{
	int		i;
	int		idx;

	i = 1;
	idx = 0;
	while (i <= stack->top)
	{
		if (stack->list[idx] < stack->list[i])
			idx = i;
		i++;
	}
	return (idx);
}

void	sort_three(t_stack *stack)
{
	int		idx;
	
	idx = get_big_num_index(stack);
	if (idx == stack->top)
		ra(stack);
	else if (idx == stack->top - 1)
		rra(stack);
	sort_rest(stack);
}
