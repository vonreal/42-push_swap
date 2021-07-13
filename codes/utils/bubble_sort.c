/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 15:26:56 by jna               #+#    #+#             */
/*   Updated: 2021/07/13 22:12:04 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_value(int *datas, t_stack *stack)
{
	int		i;
	int		j;

	i = stack->top;
	j = 0;
	while (i >= 0)
	{
		datas[j] = stack->list[i];
		j++;
		i--;
	}
}

int	*bubble_sort(t_stack *stack)
{
	int		*datas;
	int		temp;
	int		i;
	int		j;

	datas = (int *)allocate(sizeof(int), stack->size);
	set_value(datas, stack);
	i = 0;
	while (i < stack->size - 1)
	{
		j = 0;
		while (j < stack->size - 1)
		{
			if (datas[j] > datas[j + 1])
			{
				temp = datas[j];
				datas[j] = datas[j + 1];
				datas[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	return (datas);
}
