/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 19:44:27 by jna               #+#    #+#             */
/*   Updated: 2021/07/25 14:17:25 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_set(char c, char const *set)
{
	int	idx;

	idx = 0;
	while (set[idx])
	{
		if (set[idx] == c)
			return (1);
		idx++;
	}
	return (0);
}

static int	check_front(char const *s1, char const *set)
{
	int	front;

	front = 0;
	while (s1[front])
	{
		if (!check_set(s1[front], set))
			return (front);
		front++;
	}
	return (front);
}

static int	check_back(char const *s1, char const *set)
{
	int	size;
	int	back;

	size = ft_strlen(s1);
	back = 1;
	while (back <= size)
	{
		if (!check_set(s1[size - back], set))
			return ((size - back) + 1);
		back++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*strtrim;
	int	size;

	if (s1 == NULL)
		return (0);
	if (s1[check_front(s1, set)] == '\0')
		return (ft_strdup(""));
	size = check_back(s1, set) - check_front(s1, set);
	if (size >= 0)
	{
		if (!(strtrim = (char *)malloc(sizeof(char) * (size + 1))))
			return (0);
		ft_strlcpy(strtrim, s1 + check_front(s1, set), size + 1);
		return (strtrim);
	}
	return (0);
}
