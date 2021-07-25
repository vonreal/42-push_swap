/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 01:47:10 by jna               #+#    #+#             */
/*   Updated: 2021/07/25 01:47:10 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_value(t_stack *b, t_stack *a, t_info *infos)
{
	int	size;
	int	i;

	infos->ascending = bubble_sort(b);
	i = 0;
	size = b->size- 1;
	while (i < b->size)
	{
		a->list[i] = b->list[size];
		i++;
		size--;
	}
	a->top = a->size - 1;
}