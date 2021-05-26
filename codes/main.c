/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <jna@student.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 13:25:56 by root              #+#    #+#             */
/*   Updated: 2021/05/26 13:53:48 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	error_msg()
{
}

void	valid_arg(int argc, char **argv)
{
	
}

int	main(int argc, char **argv)
{
	t_stack	stack;
	
	valid_arg(argc, argv);
	push_value(argc, argv);
	return (1);
}
