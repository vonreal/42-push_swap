/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_value.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 02:11:10 by jna               #+#    #+#             */
/*   Updated: 2021/05/29 07:10:08 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	Document requirment: The stack a formatted as a list of integers.
**		1. The first argument should be at the top of the stack.
*/

static void	*allocate(int size, int length)
{
	void		*temp;

	if (!(temp = ft_calloc(size, length)))
		exit(0);
	return (temp);
}

t_stack		init_stack(int size)
{
	t_stack stack;

	stack.list = (int *)allocate(sizeof(int), size);
	stack.size = size;
	stack.top = -1;
	return (stack);
}

t_stack		push_value(int size, char **src)
{
	t_stack	stack;
	int		i;
	int		j;

	stack = init_stack(size);
	i = 0;
	j = stack.size - 1;
	while (src[i])
	{
		stack.list[j] = ft_atoi(src[i]);
		i++;
		j--;
	}
	stack.top = i - 1;
	return (stack);
}
