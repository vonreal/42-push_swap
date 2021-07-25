/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 23:01:43 by jna               #+#    #+#             */
/*   Updated: 2021/07/23 23:01:43 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	has_blank(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			return (true);
		i++;
	}
	return (false);
}

static int	get_sign(char c)
{
	if (c == '+')
		return (1);
	else if (c == '-')
		return (-1);
	return (0);
}

bool	is_range(int min, int max, long long num)
{
	if (min <= num && num <= max)
		return (true);
	return (false);
}

bool	is_num(char *str)
{
	int		i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if ('0' <= str[i] && str[i] <= '9')
			return (false);
		i++;
	}
	return (true);
}

long long	get_num(char *str)
{
	long long	num;
	int			sign;
	int			i;

	i = 0;
	if (!(sign = get_sign(str[i])))
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			exit(error_msg());
		else
			num = (num * 10) + str[i] - '0';
		i++;
	}
	return (num * sign);
}