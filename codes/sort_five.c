/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 04:25:10 by jna               #+#    #+#             */
/*   Updated: 2021/07/10 04:25:10 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_count(t_stack *stack)
{
	int	count;
	int	target;
	int	i;

	count = 0;
	target = stack->list[stack->top];
	i = stack->top - 1;
	while (i >= 0)
	{
		if (target < stack->list[i])
			return (count);
		i--;
		count++;
	}
	return (count);
}

static void	bottom_swap(t_stack *stack, int count)
{
	int	mid;
	int	i;

	mid = (int)(stack->size / 2);
	i = count;
	count = 0;
	while (i > mid)
	{
		rra(stack);
		sa(stack);
		i--;
		count++;
	}
	ra(stack);
	ra(stack);
	while (count > 1)
	{
		ra(stack);
		count--;
	}
}

static void	top_swap(t_stack *stack, int count)
{
	int	i;

	i = count;
	count = 0;
	while (i > 1)
	{
		sa(stack);
		ra(stack);
		i--;
		count++;
	}
	sa(stack);
	rra(stack);
	while (count > 1)
	{
		rra(stack);
		count--;
	}
}

static void	swap(int count,	t_stack *a)
{
	int	mid;

	mid = (int)(a->size / 2);
	if (count == 0)
		return ;
	else if (count == 1)
		sa(a);
	else if (count == a->top )
		ra(a);
	else if (1 < count && count <= mid)
		top_swap(a, count);
	else if (mid < count && count < a->size)
		bottom_swap(a, count);
}

void	sort_five(t_stack *a, t_stack *b)
{
	int		count;

	count = a->size - 3;
	while (count > 0)
	{
		pb(b, a);
		count--;
	}
	sort_three(a);
	count = a->size - 3;
	while (count > 0)
	{
		pa(a, b);
		swap(get_count(a), a);
		count--;
	}
}
