/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 19:24:36 by jna               #+#    #+#             */
/*   Updated: 2020/11/25 23:16:28 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	if (!(new_node = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
