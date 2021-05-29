/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 13:25:56 by root              #+#    #+#             */
/*   Updated: 2021/05/29 07:59:05 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void		print_stack(t_stack a, t_stack b)
{
	int		i;

	if (a.top > b.top)
		i = a.top;
	else
		i = b.top;
	while (i >= 0)
	{
		if (a.top >= i)
			printf("%d ", a.list[i]);
		else
			printf("   ");
		if (b.top >= i)
			printf("%d\n", b.list[i]);
		else
			printf("\n");
		i--;
	}
	printf("- -\n");
	printf("a b\n");
}

int		main(int argc, char **argv)
{
	t_stack		a;
	t_stack		b;

	valid_arg(argc, argv);
	a = push_value(argc - 1, argv + 1);
	b = init_stack(argc - 1);
	/* TODO
	** push_swap(): Study stack data struction and Make instructions.
	*/
	printf("-----------------------------------------\n");
	print_stack(a, b);
	printf("-----------------------------------------\n");
	sa(&a);
	print_stack(a, b);
	printf("-----------------------------------------\n");
	pb(&b, &a);
	pb(&b, &a);
	pb(&b, &a);
	print_stack(a, b);
	printf("-----------------------------------------\n");
	rr(&a, &b);
	print_stack(a, b);
	printf("-----------------------------------------\n");
	rrr(&a, &b);
	print_stack(a, b);
	printf("-----------------------------------------\n");
	sa(&a);
	print_stack(a, b);
	printf("-----------------------------------------\n");
	pa(&a, &b);
	pa(&a, &b);
	pa(&a, &b);
	print_stack(a, b);
	printf("-----------------------------------------\n");
	/* If end of use the struct FREE!! AND NULL!!*/
	return (0);
}
