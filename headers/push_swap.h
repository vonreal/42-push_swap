/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 13:35:26 by root              #+#    #+#             */
/*   Updated: 2021/06/21 14:29:45 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include "../libft/libft.h"

# define TOP		1
# define END		0
# define NOTHING	-1

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
void			push_swap(t_stack *a, t_stack *b);

/*
**		codes/error/
*/
void			error_msg();

/*
**		codes/instructions/
*/
void			sa(t_stack *a);
void			sb(t_stack *b);
void			ss(t_stack *a, t_stack *b);
void			pa(t_stack *a, t_stack *b);
void			pb(t_stack *b, t_stack *a);
void			ra(t_stack *a);
void			rb(t_stack *b);
void			rr(t_stack *a, t_stack *b);
void			rra(t_stack *a);
void			rrb(t_stack *b);
void			rrr(t_stack *a, t_stack *b);

/*
**		codes/utils/
*/
int				get_sign(char c);
int				count_elements(t_stack *stack);	
void			stack(t_stack *a, t_stack *b);

#endif
