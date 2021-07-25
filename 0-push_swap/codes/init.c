/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 21:06:22 by jna               #+#    #+#             */
/*   Updated: 2021/07/22 21:06:22 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack init_stack()
{
	t_stack	stack;

	return (stack);
}

static t_info init_info()
{
	t_info infos;

	return (infos);
}

void	init(t_stack *a, t_stack *b, t_info *infos)
{
	a = init_stack();
	b = init_stack();
	infos = init_info();
}