/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 22:46:34 by jna               #+#    #+#             */
/*   Updated: 2021/07/11 22:46:34 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	action_sixty_three(t_stack *a, t_stack *b, t_info *infos)
{
	set_pivot(b, infos , 63);
	divide_b(a, b, infos, 63);

	action_four(a, b, infos);
	action_eight(a, b, infos);
	action_sixteen(a, b, infos);
	action_thirty_two(a, b, infos);
}

void	action_one_hun_twnety_five(t_stack *a, t_stack *b, t_info *infos)
{
	set_pivot(b, infos, 125);
	divide_b(a, b, infos, 125);

	action_four(a, b, infos);
	action_eight(a, b, infos);
	action_sixteen(a, b, infos);
	action_thirty_one(a, b, infos);
	action_sixty_three(a, b, infos);
}

void	action_two_hun_fifty_one(t_stack *a, t_stack *b, t_info *infos)
{
	set_pivot(b, infos, 250);
	divide_b(a, b, infos, 250);

	action_four(a, b, infos);
	action_eight(a, b, infos);
	action_sixteen(a, b, infos);
	action_thirty_one(a, b, infos);
	action_sixty_three(a, b, infos);
	action_one_hun_twnety_five(a, b, infos);
}
