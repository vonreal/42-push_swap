/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 21:44:38 by jna               #+#    #+#             */
/*   Updated: 2020/11/10 20:07:22 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*cursor;
	t_list	*next;

	cursor = *lst;
	while (cursor)
	{
		next = cursor->next;
		del(cursor);
		cursor = next;
	}
	*lst = NULL;
}
