/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 22:46:11 by jna               #+#    #+#             */
/*   Updated: 2021/07/13 21:59:44 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	action_four(t_stack *a, t_stack *b, t_info *infos)
{
	set_pivot(b, infos, 4);
	divide_b(a, b, infos, 4);
	sort_top_three_rest(a, b);
}

void	action_eight(t_stack *a, t_stack *b, t_info *infos)
{
	set_pivot(b, infos, 8);
	divide_b(a, b, infos, 8);
	sort_top_three_rest(a, b);
	action_four(a, b, infos);
}

void	action_sixteen(t_stack *a, t_stack *b, t_info *infos)
{
	set_pivot(b, infos, 16);
	divide_b(a, b, infos, 16);
	sort_top_three_rest(a, b);
	action_four(a, b, infos);
	action_eight(a, b, infos);
}

void	action_thirty_one(t_stack *a, t_stack *b, t_info *infos)
{
	set_pivot(b, infos, 31);
	divide_b(a, b, infos, 31);
	action_four(a, b, infos);
	action_eight(a, b, infos);
	action_sixteen(a, b, infos);
}

void	action_thirty_two(t_stack *a, t_stack *b, t_info *infos)
{
	set_pivot(b, infos, 32);
	divide_b(a, b, infos, 32);
	sort_top_three_rest(a, b);
	action_four(a, b, infos);
	action_eight(a, b, infos);
	action_sixteen(a, b, infos);
}
