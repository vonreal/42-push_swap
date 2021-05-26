/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 13:35:26 by root              #+#    #+#             */
/*   Updated: 2021/05/27 05:12:34 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct	s_stack
{
	int		*list;
	int		top;
	int		size;
}				t_stack;

/*
**		codes/
*/
void			valid_arg(int argc, char **argv);
t_stack			push_value(int size, char **src);
t_stack			init_stack(int size);

/*
**		codes/error/
*/
void			error_msg();

/*
**		codes/instructions/
*/

/*
**		codes/utils/
*/
int				get_sign(char c);

#endif
