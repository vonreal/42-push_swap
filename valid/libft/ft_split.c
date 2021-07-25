/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 19:32:09 by jna               #+#    #+#             */
/*   Updated: 2021/07/25 23:49:53 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_height_size(char const *s, char c)
{
	int	idx;
	int	height;

	idx = 0;
	height = 0;
	while (s[idx])
	{
		while (s[idx] == c && s[idx])
			idx++;
		if (s[idx] != c && s[idx])
		{
			while (s[idx] != c && s[idx])
				idx++;
			height++;
		}
	}
	return (height);
}

static void	free_str(char **str, int count)
{
	int	idx;

	idx = 0;
	while (idx <= count)
	{
		free(str[idx]);
		idx++;
	}
	free(str);
}

static void	set_width_size(char const *s, char c, char **str)
{
	int	idx;
	int	height;
	int	width;

	idx = 0;
	height = 0;
	while (s[idx])
	{
		while (s[idx] == c && s[idx])
			idx++;
		if (s[idx] != c && s[idx])
		{
			width = 0;
			while (s[idx] != c && s[idx])
			{
				width++;
				idx++;
			}
			str[height] = (char *)malloc(sizeof(char) * (width + 1));
			if (str[height] == NULL)
				free_str(str, height);
			height++;
		}
	}
}

static void	set_str(char const *s, char c, char **str)
{
	int	idx;
	int	height;
	int	width;

	idx = 0;
	height = 0;
	while (s[idx])
	{
		while (s[idx] == c && s[idx])
			idx++;
		if (s[idx] != c && s[idx])
		{
			width = 0;
			while (s[idx] != c && s[idx])
			{
				str[height][width] = s[idx];
				width++;
				idx++;
			}
			str[height][width] = '\0';
			height++;
		}
	}
	str[height] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		height;

	if (s == NULL)
		return (NULL);
	height = get_height_size(s, c);
	str = (char **)malloc(sizeof(char *) * (height + 1));
	if (str == NULL)
		return (NULL);
	set_width_size(s, c, str);
	set_str(s, c, str);
	return (str);
}
