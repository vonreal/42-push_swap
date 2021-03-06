/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna </var/mail/root>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:22:38 by jna               #+#    #+#             */
/*   Updated: 2021/07/13 22:07:20 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	is_empty(t_stack *stack)
{
	if (stack->top == -1)
		return (true);
	return (false);
}

static int	pop(t_stack *stack)
{
	int	data;

	data = stack->list[stack->top];
	stack->top -= 1;
	return (data);
}

static void	push(t_stack *stack, int data)
{
	stack->top += 1;
	stack->list[stack->top] = data;
}

void	pa(t_stack *a, t_stack *b)
{
	int	data;

	if (is_empty(b))
		return ;
	else
	{
		data = pop(b);
		push(a, data);
		write(STDOUT_FILENO, "pa\n", 3);
	}
}

void	pb(t_stack *b, t_stack *a)
{
	int	data;

	if (is_empty(a))
		return ;
	else
	{
		data = pop(a);
		push(b, data);
		write(STDOUT_FILENO, "pb\n", 3);
	}
}
