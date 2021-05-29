/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna </var/mail/root>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:35:50 by jna               #+#    #+#             */
/*   Updated: 2021/05/29 07:45:14 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack *stack)
{
	int	i;
	int	temp;

	/* TODO: In common sense, an element below 1 does not rotate.
	 * 	 I'm deal only no element. +element count 1. Using count_elemets()
	 */
	if (count_elements(stack) < 2)
		return ;
	else
	{
		temp = stack->list[stack->top];
		i = stack->top;
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
	rotate(a);
	rotate(b);
	write(STDOUT_FILENO, "rr\n", 3);
}
