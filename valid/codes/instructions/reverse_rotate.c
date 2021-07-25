/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:57:01 by jna               #+#    #+#             */
/*   Updated: 2021/07/13 22:08:22 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack *stack)
{
	int	i;
	int	temp;

	i = 0;
	temp = stack->list[0];
	while (i < stack->top)
	{
		stack->list[i] = stack->list[i + 1];
		i++;
	}
	stack->list[i] = temp;
}

void	rra(t_stack *a)
{
	if (count_elements(a) < 2)
		return ;
	else
	{
		reverse_rotate(a);
		write(STDOUT_FILENO, "rra\n", 4);
	}
}

void	rrb(t_stack *b)
{
	if (count_elements(b) < 2)
		return ;
	else
	{
		reverse_rotate(b);
		write(STDOUT_FILENO, "rrb\n", 4);
	}
}

void	rrr(t_stack *a, t_stack *b)
{
	if (count_elements(a) < 2 && count_elements(b) < 2)
		return ;
	else
	{
		reverse_rotate(a);
		reverse_rotate(b);
		write(STDOUT_FILENO, "rrr\n", 4);
	}
}
