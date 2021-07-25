/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 14:35:24 by jna               #+#    #+#             */
/*   Updated: 2021/07/25 14:16:41 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *s, int c)
{
	int	count;
	int	last;
	int	first;

	count = 0;
	last = 0;
	first = -1;
	while (s[count] != '\0')
	{
		if (s[count] == (char)c)
		{
			last = count;
			first = last;
		}
		count++;
	}
	if (c == '\0')
		return (&s[count]);
	if (first != -1)
		return (&s[last]);
	return (0);
}
