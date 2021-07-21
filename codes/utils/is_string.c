/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 13:56:00 by jna               #+#    #+#             */
/*   Updated: 2021/07/21 13:56:00 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_blank(char str)
{
	if (str == ' ')
		return (true);
	return (false);
}

bool	is_string(char *str, int *size)
{
	int		i;
	char	**divide;
	bool	temp;

	i = 0;
	while (str[i])
	{
		if (temp = is_blank(str[i]))
			break ;
	}
	if (temp == true)
	{
		divide = ft_split(str, ' ');
		i = 0;
		while (divide[i])
		{
			if (!is_integer(divide[i]))
				return (false);
			size++;
			i++;
		}
		free_and_nulls(divide);
		return (true);
	}
	return (false);
}
