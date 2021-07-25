/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 14:43:45 by jna               #+#    #+#             */
/*   Updated: 2021/07/25 14:16:16 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_str(char *dst, char *src, size_t idx, size_t len)
{
	unsigned int	count;

	count = 0;
	while (src[count] != '\0' && idx < len)
	{
		if (dst[idx] != src[count])
			return (0);
		count++;
		idx++;
	}
	if (src[count] == '\0')
		return (1);
	return (0);
}

char	*ft_strnstr(char *haystack, char *needle, size_t len)
{
	unsigned int	count;

	count = 0;
	if (needle[0] == '\0')
		return (haystack);
	while (haystack[count] != '\0' && count < len)
	{
		if (haystack[count] == needle[0])
		{
			if (check_str(haystack, needle, count, len))
				return (&haystack[count]);
		}
		count++;
	}
	return (0);
}
