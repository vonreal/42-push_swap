/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna </var/mail/root>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:35:50 by jna               #+#    #+#             */
/*   Updated: 2021/05/27 13:55:22 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	is_empty(t_stack *stack)
{
	if (stack->top == -1)
		return (true);
	return (false);
}

static void	rotate(t_stack *stack)
{
	int	i;
	int	temp;

	/* TODO: In common sense, an element below 1 does not rotate.
	 * 	 I'm deal only no element. +element count 1. Using count_elemets()
	 */
	if (is_empty(stack))
		return ;
	else
	{
		temp = stack->list[stack->top];
		i = stack->top - 1;
		while (i > 0)
		{
			stack->list[i] = stack->list[i - 1];
			i--;
		}
		stack->list[i] = temp;
	}
}

void		ra(t_stack *a)
{
	rotate(a);
	write(STDOUT_FILENO, "ra\n", 3);
}

void		rb(t_stack *b)
{
	rotate(b);
	write(STDOUT_FILENO, "rb\n", 3);
}

void		rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}
