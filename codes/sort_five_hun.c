/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_hun.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 22:44:40 by jna               #+#    #+#             */
/*   Updated: 2021/07/13 22:19:45 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_action_five_hun(t_stack *b)
{
	int		action;

	action = b->size - b->top;
	return (action);
}

void	b_to_a_five_hun(t_stack *a, t_stack *b, t_info *infos, int action)
{
	int		i;

	i = 0;
	action = get_action_five_hun(b);
	if (b->top <= 2)
		return ;
	if (action == 4)
		action_four(a, b, infos);
	else if (action == 8)
		action_eight(a, b, infos);
	else if (action == 16)
		action_sixteen(a, b, infos);
	else if (action == 32)
		action_thirty_one(a, b, infos);
	else if (action == 63)
		action_sixty_three(a, b, infos);
	else if (action == 126)
		action_one_hun_twnety_five(a, b, infos);
	else if (action == 251)
		action_two_hun_fifty_one(a, b, infos);
	b_to_a_five_hun(a, b, infos, action);
}
