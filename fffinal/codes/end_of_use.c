/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_of_use.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 22:41:58 by jna               #+#    #+#             */
/*   Updated: 2021/07/25 15:59:13 by jna              ###   ########.fr       */
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

static void	free_and_null_stack(t_stack *stack)
{
	free(stack->list);
	stack->list = NULL;
}

static void	free_and_null_info(t_info *infos)
{
	free(infos->ascending);
	infos->ascending = NULL;
	free_and_null_stack(&infos->chunks);
}

void	end_of_use(t_stack *a, t_stack *b, t_info *infos)
{
	free_and_null_stack(a);
	free_and_null_stack(b);
	free_and_null_info(infos);
}
