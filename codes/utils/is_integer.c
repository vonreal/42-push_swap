/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 23:01:37 by jna               #+#    #+#             */
/*   Updated: 2021/07/24 23:33:36 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_sign(char c)
{
	if (c == '+')
		return (1);
	if (c == '-')
		return (-1);
	return (0);
}

bool	is_num(char *str)
{
	int		i;
	int		sign;

	i = 0;
	sign = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		sign = 1;
		i++;
	}
	while (str[i])
	{
		if (!('0' <= str[i] && str[i] <= '9'))
			return (false);
		i++;
	}
	if (sign == 1 && i == 1)
		return (false);
	return (true);
}

long long	get_num(char *str)
{
	long long	num;
	int			sign;
	int			i;

	i = 0;
	num = 0;
	sign = 1;
	if (get_sign(str[i]))
	{
		sign = get_sign(str[i]);
		i++;
	}
	while (str[i])
	{
		num = (num * 10) + str[i] - '0';
		i++;
	}
	return (num * sign);
}

bool	is_range(int min, int max, long long num)
{
	if (min <= num && num <= max)
		return (true);
	return (false);
}
