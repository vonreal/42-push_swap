/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 23:16:04 by jna               #+#    #+#             */
/*   Updated: 2021/05/27 05:20:08 by jna              ###   ########.fr       */
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

static bool	is_equal(char *s1, char *s2)
{
	unsigned int	i;

	if (s1 == NULL || s2 == NULL)
		return (false);
	else if (ft_strlen(s1) != ft_strlen(s2))
		return (false);
	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (false);
		i++;
	}
	if ((s1[i] != s2[i]) && (s1[i] == '\0'))
		return (false);
	return (true);
}

static bool	is_duplicate(char *src, char **target)
{
	int		dup;
	int		i;

	dup = 0;
	i = 0;
	while (target[i])
	{
		if (target[i][0] == '+' || src[0] == '+')
		{
			target[i]++;
			src++;
		}
		if (is_equal(target[i], src))
			dup++;
		if (dup > 1)
			return (false);
		i++;
	}
	return (true);
}

static bool	is_range(int min, int max, long long num)
{
	if (min <= num && num <= max)
		return (true);
	return (false);
}

static bool	is_integer(char *str)
{
	long long	num;
	int			sign;
	int			i;

	num = 0;
	sign = 1;
	i = 0;
	if (get_sign(str[0]) != 0)
	{
		sign = get_sign(str[0]);
		i++;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		else
			num = (num * 10) + str[i] - '0';
		i++;
	}
	if (!is_range(INT_MIN, INT_MAX, num * sign))
		return (false);
	return (true);
}

void		valid_arg(int argc, char **argv)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		if (!is_integer(argv[i]))
			error_msg();
		if (!is_duplicate(argv[i], argv))
			error_msg();
		i++;
	}
}
