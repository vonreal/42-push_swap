/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 01:50:40 by jna               #+#    #+#             */
/*   Updated: 2021/07/25 01:50:40 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_and_null(char *str, char **strs)
{
	int		i;

	if (str != NULL)
	{
		free(str);
		str = NULL;
	}
	if (strs != NULL)
	{
		i = 0;
		while (strs[i])
		{
			free(strs[i]);
			strs[i] = NULL;
			i++;
		}
		free(strs);
	}
}

void	free_and_null_stack(t_stack *stack)
{
	free(stack->list);
	stack->list = NULL;
}