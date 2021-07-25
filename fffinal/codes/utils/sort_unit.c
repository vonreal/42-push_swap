/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_unit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 16:47:19 by jna               #+#    #+#             */
/*   Updated: 2021/07/25 18:00:50 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	int		top;

	idx = get_big_num_index(stack);
	if (idx == stack->top)
		ra(stack);
	else if (idx == stack->top - 1)
		rra(stack);
	top = stack->top;
	if (stack->list[top] > stack->list[top - 1])
		sa(stack);
}

void	sort_end(t_stack *stack)
{
	int		top;

	top = stack->top;
	if (stack->top == 2)
		sort_three(stack);
	else if (stack->list[top] > stack->list[top - 1])
		sa(stack);
}

void	sort_top_three_rest(t_stack *a, t_stack *b)
{
	if (b->list[b->top] < b->list[b->top - 1])
		sb(b);
	pa(a, b);
	pa(a, b);
}

void	sort_top_three(t_stack *a, t_stack *b)
{
	int		max;

	max = get_max(b);
	if (max == b->top)
	{
		pa(a, b);
		sort_top_three_rest(a, b);
	}
	else if (max == b->top - 1)
	{
		rb(b);
		pa(a, b);
		rrb(b);
		sort_top_three_rest(a, b);
	}
	else if (max == b->top - 2)
	{
		rb(b);
		rb(b);
		pa(a, b);
		rrb(b);
		rrb(b);
		sort_top_three_rest(a, b);
	}
}
