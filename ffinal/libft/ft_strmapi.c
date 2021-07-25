/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 21:04:32 by jna               #+#    #+#             */
/*   Updated: 2020/11/25 23:23:55 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*newstr;
	unsigned int	idx;

	if (s == NULL)
		return (0);
	newstr = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (newstr == NULL)
		return (0);
	idx = 0;
	while (s[idx])
	{
		newstr[idx] = f(idx, s[idx]);
		idx++;
	}
	newstr[idx] = '\0';
	return (newstr);
}
