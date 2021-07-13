/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 22:42:48 by jna               #+#    #+#             */
/*   Updated: 2021/07/13 21:59:07 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	action_six(t_stack *a, t_stack *b, t_info *infos)
{
	set_pivot(b, infos, 6);
	divide_b(a, b, infos, 6);
	sort_top_three(a, b);
}

void	action_seven(t_stack *a, t_stack *b, t_info *infos)
{
	set_pivot(b, infos, 7);
	divide_b(a, b, infos, 7);
}

void	action_thirteen(t_stack *a, t_stack *b, t_info *infos)
{
	set_pivot(b, infos, 13);
	divide_b(a, b, infos, 13);
	sort_top_three(a, b);
	set_pivot(b, infos, 7);
	divide_b(a, b, infos, 7);
	set_pivot(b, infos, 4);
	divide_b(a, b, infos, 4);
	sort_top_three_rest(a, b);
}

void	action_twentyfive(t_stack *a, t_stack *b, t_info *infos)
{
	set_pivot(b, infos, 25);
	divide_b(a, b, infos, 25);
	sort_top_three(a, b);
	action_six(a, b, infos);
	action_thirteen(a, b, infos);
}

void	action_twentyfour(t_stack *a, t_stack *b, t_info *infos)
{
	set_pivot(b, infos, 24);
	divide_b(a, b, infos, 24);
	sort_top_three(a, b);
	action_six(a, b, infos);
	action_thirteen(a, b, infos);
}
