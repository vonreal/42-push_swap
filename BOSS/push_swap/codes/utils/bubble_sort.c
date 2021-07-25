/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 15:40:20 by jna               #+#    #+#             */
/*   Updated: 2021/07/25 15:51:31 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_value(int *dst, t_stack *src)
{
	int		i;

	i = 0;
	while (i < src->size)
	{
		dst[i] = src->list[i];
		i++;
	}
}

void	bubble_sort(int *dst, t_stack *src)
{
	int		i;
	int		j;
	int		temp;

	push_value(dst, src);
	i = 0;
	while (i < src->size - 1)
	{
		j = 0;
		while (j < src->size - 1)
		{
			if (dst[j] > dst[j + 1])
			{
				temp = dst[j];
				dst[j] = dst[j + 1];
				dst[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}
