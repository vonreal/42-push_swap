/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna </var/mail/root>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 10:49:31 by jna               #+#    #+#             */
/*   Updated: 2021/05/31 13:12:09 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	where_index(int big_idx, int total)
{
	/* I think if total_size / 2
	 *  if total_size - big-idx(corrent idx)
	 *  bigger than total_size / 2 rra();
	 *  smaller than total_size / 2 ra();
	 *  if big_idx == 0 Nothing.
	 */
	int	mid;

	mid = (int)(total / 2);
	if (big_idx == 0)
		return (NOTHING);
	if (big_idx < mid)
		return (END);
	if (big_idx >= mid)
		return (TOP);
	return (0);
}

static int	get_index_of_big_num(t_stack *stack)
{
	int	big;
	int	i;

	big = 0;
	i = 1;
	while (i <= stack->top)
	{
		if (stack->list[big] < stack->list[i])
			big = i;
		i++;
	}
	return (big);
}

static void	cmp_the_rest(t_stack *stack)
{
	int	first;
	int	second;

	first = stack->top;
	second = stack->top - 1;
	if (stack->list[first] > stack->list[second])
			sa(stack);
	else
		return ;
}

static void	if_argc_three(t_stack *stack)
{
	int	big_idx;
	int	where_idx;

	big_idx = get_index_of_big_num(stack);
	where_idx = where_index(big_idx, stack->size);
	if (where_idx == NOTHING)
	{
		cmp_the_rest(stack);
		return ;
	}
	if (where_idx == TOP)
		ra(stack);
	else
		rra(stack);
	cmp_the_rest(stack);
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

static void	if_argc_five(t_stack *a, t_stack *b)
{
	pb(b, a);
	pb(b, a);
	if_argc_three(a);
	pa(a, b);
	swap(get_count(a), a);
	pa(a, b);
	swap(get_count(a), a);
}

void		push_swap(t_stack *a, t_stack *b)
{
	if (a->size == 3)
		if_argc_three(a);
	else if (a->size == 5)
		if_argc_five(a, b);
	if (b->size == a->size)	//temp(gcc avoid)
		return ;
}
