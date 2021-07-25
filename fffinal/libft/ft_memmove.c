/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 19:44:06 by jna               #+#    #+#             */
/*   Updated: 2020/11/21 03:22:33 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	unsigned int	count;

	ptr1 = (unsigned char *)dst;
	ptr2 = (unsigned char *)src;
	if (ptr1 == NULL && ptr2 == NULL)
		return (dst);
	if (ptr2 < ptr1)
	{
		count = 1;
		while (count <= len)
		{
			ptr1[len - count] = ptr2[len - count];
			count++;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
