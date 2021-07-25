/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 04:28:21 by jna               #+#    #+#             */
/*   Updated: 2020/11/21 04:48:03 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	size;
	unsigned int	idx;

	size = ft_strlen(dst);
	idx = 0;
	if ((size + idx + 1) < dstsize)
	{
		while (src[idx] && (size + idx + 1) < dstsize)
		{
			dst[size + idx] = src[idx];
			idx++;
		}
		dst[size + idx] = '\0';
	}
	if (dstsize == 0)
		return (ft_strlen(src));
	if (dstsize < size)
		return (dstsize + ft_strlen(src));
	return (size + ft_strlen(src));
}
