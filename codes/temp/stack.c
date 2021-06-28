/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna </var/mail/root>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 12:32:45 by jna               #+#    #+#             */
/*   Updated: 2021/05/27 12:58:23 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void print_list(t_stack *stack, char *name)
{
	int	i;

	i = stack->top;
	while (i >= 0)
	{
		printf("%2d\n", stack->list[i]);
		i--;
	}
	printf("stack %s\n", name);
}

static bool is_full(t_stack *stack)
{
	if ((stack->top + 1) >= (stack->size))
		return (true);
	return (false);
}

static bool is_empty(t_stack *stack)
{
	if (stack->top == -1)
		return (true);
	return (false);
}

void	push(t_stack *a, t_stack *b, int data)
{
	if (!is_full(a))
	{
		a->top += 1;
		a->list[a->top] = data;
		print_list(a, "a");
	}
	else
		printf("stack a is full.\n");
	if (!is_full(b))
	{
		b->top += 1;
		b->list[b->top] = data;
		print_list(b, "b");
	}
	else
		printf("stack b is full.\n");

}

void	pop(t_stack *a, t_stack *b)
{
	if (!is_empty(a))
	{
		printf("[a]pop: %d\n", a->list[a->top]);
		a->top -= 1;
		print_list(a, "a");
	}
	else
		printf("stack a is empty.\n");
	if (!is_empty(b))
	{
		printf("[b]pop: %d\n", b->list[b->top]);
		b->top -= 1;
		print_list(b, "b");
	}
	else
		printf("stack b is empty.\n");

}

void	stack(t_stack *a, t_stack *b)
{
	int	input;

	input = 0;
	printf("1: pop all stack\n");
	printf("2: push all stack\n");
	scanf("%d", &input);

	if (input == 1)
		pop(a, b);
	else if (input == 2)
	{
		printf("input data: ");
		scanf("%d", &input);
		push(a, b, input);
	}
}
