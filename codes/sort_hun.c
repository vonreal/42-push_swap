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
	else if (chunk == 3)
	{
		sort_top_three(a, b);
		infos->chunks.top--;
	}
	else
	{
		set_pivot(b, infos, chunk);
		divide_b(a, b, infos, chunk);
	}
	print_stack(infos->chunks, infos->chunks);
	b_to_a(a, b, infos, 0);
}
