/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 13:25:56 by root              #+#    #+#             */
/*   Updated: 2021/07/21 08:11:35 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack a, t_stack b)
{
	int		i;

	if (a.top > b.top)
		i = a.top;
	else
		i = b.top;
	while (i >= 0)
	{
		if (a.top >= i)
			printf("%2d ", a.list[i]);
		else
			printf("  ");
		if (b.top >= i)
			printf("%2d\n", b.list[i]);
		else
			printf("\n");
		i--;
	}
	printf("- -\n");
	printf("a b\n");
}

void	print_datas(int *datas, t_stack *stack)
{
	int		i;

	i = 0;
	while (i < stack->size)
	{
		printf("%d ", datas[i]);
		i++;
	}
	printf("\n");
}

static void	free_and_null(t_stack *a, t_stack *b, t_info *infos)
{
	free_and_null_stack(a);
	free_and_null_stack(b);
	free_and_null_stack(&infos->chunks);
	free(infos->aligned);
}

int	main(int argc, char **argv)
{
	t_stack		a;
	t_stack		b;
	t_info		infos;
	
	valid_arg(argc, argv);
	a = push_value(argc - 1, argv + 1);
	b = init_stack(argc - 1);
	infos.chunks = init_stack(argc - 1);
	infos.aligned = bubble_sort(&a);
	push_swap(&a, &b, &infos);
	print_stack(a, b);
	free_and_null(&a, &b, &infos);
	return (0);
}
