/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 16:30:39 by jna               #+#    #+#             */
/*   Updated: 2020/11/25 23:23:28 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*strjoin;
	unsigned int	size_s1;
	unsigned int	size_s2;

	if (s1 == NULL)
		return (0);
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	if (!(strjoin = (char *)malloc(sizeof(char) * (size_s1 + size_s2 + 1))))
		return (0);
	ft_strlcpy(strjoin, s1, size_s1 + 1);
	ft_strlcpy(strjoin + size_s1, s2, size_s2 + 1);
	return (strjoin);
}
