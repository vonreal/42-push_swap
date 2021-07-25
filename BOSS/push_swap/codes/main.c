/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 22:33:09 by jna               #+#    #+#             */
/*   Updated: 2021/07/25 18:48:48 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack *b)
{
	t_stack	a;
	t_info	infos;

	init(&a, b, &infos);
	set_value(&a, b, &infos);
	sort(&a, b, &infos);
	end_of_use(&a, b, &infos);
}

int	main(int argc, char **argv)
{
	t_stack	temp;

	init_stack(&temp, 0);
	if (is_valid(&argc, argv, &temp))
		push_swap(&temp);
	return (0);
}
