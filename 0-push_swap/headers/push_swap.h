/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 21:06:53 by jna               #+#    #+#             */
/*   Updated: 2021/07/22 21:06:53 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

typedef struct	s_stack
{
	int		*list;
	int		top;
	int		size;
}				t_stack;

typedef struct	s_info
{
	int		*ascending;
	int		mid_idx;
	int		midian;
	t_stack	chunks;
}				t_info;

/*
**      codes/
*/
bool	    is_valid(int *argc, char **target);
void        push_swap();
void	    init(t_stack *a, t_stack *b, t_info *infos);

void	    free_and_null(char *str, char **strs);
#endif