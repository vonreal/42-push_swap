/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna </var/mail/root>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:57:01 by jna               #+#    #+#             */
/*   Updated: 2021/05/27 14:03:39 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_elements(t_stack *stack)
{
	return (stack->top + 1);
}

static void	reverse_rotate(t_stack *stack)
{
	int	i;
	int	temp;

	if (count_elements(stack) < 2)
		return ;
	else
	{
		i = 0;
		temp = stack->list[0];
		while (i < stack->size - 1)
		{
			stack->list[i] = stack->list[i + 1];
			i++;
		}
		stack->list[i] = temp;
	}
}

void		rra(t_stack *a)
{
	reverse_rotate(a);
	write(STDOUT_FILENO, "rra\n", 4);
}

void		rrb(t_stack *b)
{
	reverse_rotate(b);
	write(STDOUT_FILENO, "rrb\n", 4);
}

void		rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
	write(STDOUT_FILENO, "rrr\n", 4);
}
