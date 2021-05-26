/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 13:25:56 by root              #+#    #+#             */
/*   Updated: 2021/05/27 04:07:42 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_stack		a;
	t_stack		b;

	valid_arg(argc, argv);
	a = push_value(argc - 1, argv + 1);
	b = init_stack(argc - 1);
	/* TODO
	** push_swap(): Study stack data struction and Make instructions.
	*/
	return (0);
}
