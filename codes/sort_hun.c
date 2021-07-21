/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 22:37:22 by jna               #+#    #+#             */
/*   Updated: 2021/07/13 22:20:27 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_action(t_stack *b)
{
	if (b->top == 96)
		return (3);
	if (b->top == 93)
		return (6);
	if (b->top == 87)
		return (13);
	if (b->top == 74)
		return (25);
	if (b->top == 49)
		return (50);
}

void	b_to_a(t_stack *a, t_stack *b, t_info *infos, int action)
{
	int		chunk;

	chunk = infos->chunks.list[infos->chunks.top];
	if (infos->chunks.top < 0)
		return ;
	if (chunk == 2)
	{
		sort_top_three_rest(a, b);
		infos->chunks.top--;
	}
	if (chunk == 3)
	{
		sort_top_three(a, b);
		infos->chunks.top--;
	}
	else
	{
		set_pivot(b, infos, chunk);
		divide_b(a, b, infos, chunk);
	}
	print_stack(*a, infos->chunks);
	b_to_a(a, b, infos, 0);
	// int		i;
	// 
	// i = 0;
	// action = get_action(b);
	// if (b->top <= 2)
	// 	return ;
	// if (action == 3)
	// 	sort_top_three(a, b);
	// else if (action == 6)
	// 	action_six(a, b, infos);
	// else if (action == 13)
	// 	action_thirteen(a, b, infos);
	// else if (action == 25)
	// 	action_twentyfive(a, b, infos);
	// else if (action == 50)
	// {
	// 	set_pivot(b, infos, 50);
	// 	divide_b(a, b, infos, 50);
	// 	sort_top_three(a, b);
	// 	action_six(a, b, infos);
	// 	action_thirteen(a, b, infos);
	// 	action_twentyfive(a, b, infos);
	// }
	// b_to_a(a, b, infos, action);
}
