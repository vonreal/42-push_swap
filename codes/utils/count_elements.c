/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna </var/mail/root>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 06:48:35 by jna               #+#    #+#             */
/*   Updated: 2021/05/29 06:49:36 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		count_elements(t_stack *stack)
{
	return (stack->top + 1);
}
