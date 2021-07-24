/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 21:11:36 by jna               #+#    #+#             */
/*   Updated: 2021/07/25 01:11:54 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include "../libft/libft.h"

/*
**		codes/
*/
bool		is_valid(int *len, char **target);
void		free_and_null(char *str, char **strs);

/*
**		utils
*/
bool		is_num(char *str);
bool		is_range(int min, int max, long long num);
long long	get_num(char *str);

bool		error_msg(void);

void		*allocate(int size, int length);

#endif
