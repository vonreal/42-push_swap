/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 01:59:06 by jna               #+#    #+#             */
/*   Updated: 2021/07/25 01:59:06 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort(t_stack *a, t_stack *b, t_info *infos)
{
    if (is_aligned(a, infos->ascending))
		return ;
    else
	{
		if (a->top == 4)
			sort_five(a, b);
		else
        {
            a_to_b(a, b, infos, 0);
	        b_to_a(a, b, infos, 3);
        }
	}
}