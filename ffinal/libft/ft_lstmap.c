/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 20:21:36 by jna               #+#    #+#             */
/*   Updated: 2020/11/11 20:38:41 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new;
	t_list *node;

	if (lst == NULL)
	{
		ft_lstclear(&lst, del);
		return (NULL);
	}
	new = ft_lstnew(f(lst->content));
	while (lst->next != NULL)
	{
		lst = lst->next;
		node = ft_lstnew(f(lst->content));
		ft_lstadd_back(&new, node);
	}
	return (new);
}
