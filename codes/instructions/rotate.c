/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:35:50 by jna               #+#    #+#             */
/*   Updated: 2021/06/21 15:57:41 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack *stack)
{
	int	i;
	int	temp;

	temp = stack->list[stack->top];
	i = stack->top;
	while (i > 0)
	{
		stack->list[i] = stack->list[i - 1];
		i--;
	}
	stack->list[i] = temp;
}

void		ra(t_stack *a)
{
	if (count_elements(a) < 2)
		return ;
	else
	{
		rotate(a);
		write(STDOUT_FILENO, "ra\n", 3);
	}
}

void		rb(t_stack *b)
{
	if (count_elements(b) < 2)
		return ;
	else
	{
		rotate(b);
		write(STDOUT_FILENO, "rb\n", 3);
	}
}

void		rr(t_stack *a, t_stack *b)
{
	if (count_elements(a) < 2 && count_elements(b) < 2)
		return ;
	else
	{
		rotate(a);
		rotate(b);
		write(STDOUT_FILENO, "rr\n", 3);
	}
}
