/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 22:34:06 by jna               #+#    #+#             */
/*   Updated: 2021/07/25 23:31:28 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	is_integer(char *target, int *size)
{
	char		**targets;
	int			i;

	if (ft_strchr(target, ' '))
	{
		targets = ft_split(target, ' ');
		i = -1;
		while (targets[++i])
		{
			if (!is_integer(targets[i], size))
			{
				free_and_null(NULL, targets);
				return (false);
			}
		}
		free_and_null(NULL, targets);
	}
	else
	{
		if (!is_num(target) || \
			!is_range(INT_MIN, INT_MAX, get_num(target)))
			return (false);
		*size += 1;
	}
	return (true);
}

void	make_one_line(int *line, char *src, int *size)
{
	char	**srcs;
	int		i;

	if (ft_strchr(src, ' '))
	{
		srcs = ft_split(src, ' ');
		i = 0;
		while (srcs[i])
		{
			make_one_line(line, srcs[i], size);
			i++;
		}
		free_and_null(NULL, srcs);
	}
	else
	{
		line[*size] = (int)get_num(src);
		*size += 1;
	}
}

static bool	is_duplicate(int *len, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (len[i] == len[j])
			{
				free(len);
				len = NULL;
				return (true);
			}
			j++;
		}
		i++;
	}
	return (false);
}

bool	is_valid(int *len, char **target, t_stack *stack)
{
	int		size;
	int		i;

	i = 1;
	if (*len < 2)
		return (false);
	while (target[i])
	{
		if (!is_integer(target[i], &stack->size))
			return (error_msg());
		i++;
	}
	stack->list = (int *)allocate(sizeof(int), stack->size);
	i = 1;
	size = 0;
	while (target[i])
	{
		make_one_line(stack->list, target[i], &size);
		i++;
	}
	if (is_duplicate(stack->list, stack->size))
		return (error_msg());
	return (true);
}
