/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 15:47:41 by jna               #+#    #+#             */
/*   Updated: 2020/11/21 04:16:20 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		length;
	int		idx;

	length = ft_strlen(s1);
	ptr = (char *)malloc(sizeof(char) * (length + 1));
	if (ptr == NULL)
		return (0);
	idx = 0;
	while (idx < length)
	{
		ptr[idx] = s1[idx];
		idx++;
	}
	ptr[idx] = '\0';
	return (ptr);
}
