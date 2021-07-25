/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 15:17:07 by jna               #+#    #+#             */
/*   Updated: 2020/11/20 23:51:07 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	count;
	unsigned char	*ptr;

	ptr = (unsigned char *)b;
	count = 0;
	while (count < len)
	{
		ptr[count] = (unsigned char)c;
		count++;
	}
	return (b);
}
