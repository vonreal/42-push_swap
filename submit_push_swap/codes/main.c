/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 22:33:09 by jna               #+#    #+#             */
/*   Updated: 2021/07/24 22:33:55 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack *b)
{
	t_stack	a;
	t_info	infos;

	init(b, &a, &infos);
	set_value(b, &a, &infos);
	sort(&a, b, &infos);
	cleaning(b, &a, &infos);
}

int	main(int argc, char **argv)
{
	t_stack a;

	a = init_stack(0);
	if (is_valid(&argc, argv, &a))
		push_swap(&a);
	return (0);
}