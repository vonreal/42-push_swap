/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 18:51:35 by jna               #+#    #+#             */
/*   Updated: 2020/11/21 00:03:05 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	unsigned int	count;

	ptr1 = (unsigned char *)dst;
	ptr2 = (unsigned char *)src;
	if (ptr1 == NULL && ptr2 == NULL)
		return (dst);
	count = 0;
	while (count < n)
	{
		ptr1[count] = ptr2[count];
		count++;
	}
	return (dst);
}
