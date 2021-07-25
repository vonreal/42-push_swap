/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 19:05:04 by jna               #+#    #+#             */
/*   Updated: 2021/07/25 14:08:34 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_size(int n)
{
	int	count;

	count = 1;
	if (n < 0)
	{
		if (n == INT_MIN)
			return (11);
		n *= (-1);
		count++;
	}
	while (n > 9)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	int	idx;
	int	size;

	size = get_size(n);
	str = (char *)malloc(size + 1);
	if (str == NULL)
		return (0);
	idx = 0;
	if (n < 0)
		str[idx++] = '-';
	ft_memset(&str[idx], '0', size - 1);
	str[size] = '\0';
	while (size - 1 >= idx)
	{
		if (n < 0)
			str[size - 1] = (n % 10) * (-1) + '0';
		else
			str[size - 1] = (n % 10) + '0';
		n /= 10;
		size--;
	}
	return (str);
}
