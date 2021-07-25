/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 01:11:00 by jna               #+#    #+#             */
/*   Updated: 2021/07/25 13:37:20 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*allocate(int size, int length)
{
	void	*temp;

	temp = ft_calloc(size, length);
	if (temp == NULL)
		exit(0);
	return (temp);
}
