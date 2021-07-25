/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 16:01:53 by jna               #+#    #+#             */
/*   Updated: 2020/11/21 03:44:38 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	count;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	count = 0;
	while (count < n)
	{
		if (ptr[count] == (unsigned char)c)
			return ((void *)s + count);
		count++;
	}
	return (0);
}
