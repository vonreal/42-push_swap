/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna </var/mail/root>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:03:56 by jna               #+#    #+#             */
/*   Updated: 2021/05/27 13:22:33 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_elements(t_stack *stack)
{
	int	count;

	count = stack->top + 1;
	return (count);
}

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
	sa(a);
	sb(b);
	/* TODO: If sa and sb not work. How deal ss?
	** write(STDOUT_FILENO, "ss\n", 3);
	*/
}
