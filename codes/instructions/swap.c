/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:03:56 by jna               #+#    #+#             */
/*   Updated: 2021/06/21 15:57:32 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *stack)
{
	int	first;
	int	second;
	int	temp;

	first = stack->top;
	second = stack->top - 1;
	temp = stack->list[first];
	stack->list[first] = stack->list[second];
	stack->list[second] = temp;
}

void		sa(t_stack *a)
{
	if (count_elements(a) < 2)
		return ;
	else
	{
		swap(a);
		write(STDOUT_FILENO, "sa\n", 3);
	}
}

void		sb(t_stack *b)
{
	if (count_elements(b) < 2)
		return ;
	else
	{
		swap(b);
		write(STDOUT_FILENO, "sb\n", 3);
	}
}

void		ss(t_stack *a, t_stack *b)
{
	if (count_elements(a) < 2 && count_elements(b) < 2)
		return ;
	else
	{
		swap(a);
		swap(b);
		write(STDOUT_FILENO, "ss\n", 3);
	}
}
