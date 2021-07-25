/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 21:02:49 by jna               #+#    #+#             */
/*   Updated: 2021/07/22 21:02:49 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	if (is_valid(&argc, argv))
		push_swap();
	return (0);
}

void	push_swap()
{
	t_stack	a;
	t_stack	b;
	t_info	infos;

	init(&a, &b, &infos);
	set_value(&a, &infos);
	sort(&a, &b, &infos);
	cleaning(&a, &b, &infos);
}
