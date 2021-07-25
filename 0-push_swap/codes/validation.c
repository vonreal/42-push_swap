/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 21:41:11 by jna               #+#    #+#             */
/*   Updated: 2021/07/22 21:41:11 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	Document requirment: <Handle errors>
**		1. Program quit errors.
**			[1] Segmentation fault, bus error, double free etc
**		2. Display "Error\n" on the standard error.
**			[1] Aren't integers
**			[2] Bigger than an integer
**			[3] Duplicates.
*/

// 테스트 필요
static bool	is_integer(char *target)
{
	char		**targets;
	long long	num;
	int			sign;
	int			i;

	if (has_blank(target))
	{
		targets = ft_split(target, ' ');
		i = 0;
		while (targets[i])
		{
			if (!is_integer(targets[i]))
			{
				free_and_null(NULL, targets);
				return (false);
			}
			i++;
		}
		free_and_null(NULL, targets);
	}
	else
	{
		if (!is_num(target))
			return (false);
		if (!is_range(INT_MIN, INT_MAX, get_num(target)))
			return (false);
	}
	return (true);
}

static bool is_duplicate(int *len, char *target)
{
	return (true);
}

static bool	error_msg(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	return (false);
}

bool	is_valid(int *len, char **target)
{
	int		i;

	i = 1;
	if (*len < 2)
		return (false);
	while (target[i])
	{
		if (!is_integer(target[i]))
			return (error_msg());
		if (!is_duplicate(len, target[i]))
			return (error_msg());
		i++;
	}
	return (true);
}
