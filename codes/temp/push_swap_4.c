/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 19:53:42 by jna               #+#    #+#             */
/*   Updated: 2021/06/28 18:29:41 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_aligned(t_stack *stack, int *aligned)
{
	int		i;
	int		j;

	i = stack->top;
	j = 0;
	while (i >= 0)
	{
		if (!(stack->list[i] == aligned[j]))
			return (false);
		i--;
		j++;
	}
	return (true);
}

int		get_idx_aligned(int target, t_info *infos)
{
	int		i;

	i = 0;
	while (1)
	{
		if (target == infos->aligned[i])
			break ;
		i++;
	}
	return (i);
}

int		get_max_num_idx(t_stack *stack, t_info *infos, int end)
{
	int		i;
	int		max;

	i = stack->top - 1;
	max = stack->top;
	while (i >= end)
	{
		if (stack->list[max] < stack->list[i])
			max = i;
		i--;
	}
	max = get_idx_aligned(stack->list[max], infos);
	return (max);
}

int		get_min_num_idx(t_stack *stack, t_info *infos, int end)
{
	int		i;
	int		min;

	i = stack->top - 1;
	min = stack->top;
	while (i >= end)
	{
		if (stack->list[min] > stack->list[i])
			min = i;
		i--;
	}
	min = get_idx_aligned(stack->list[min], infos);
	return (min);
}

void	set_pivot(t_stack *stack, t_info *infos, int end)
{
	int		max;
	int		min;

	max = get_max_num_idx(stack, infos, end);
	min = get_min_num_idx(stack, infos, end);
	infos->midian = (max + min) / 2;
	infos->pivot = infos->aligned[infos->midian];
}

int		find_aligned(t_stack *stack, t_info *infos)
{
	int		i;
	int		idx;

	// 1. stack->list에서 infos->aligned[0] 를 찾는다.
	i = stack->top;
	while (i >= 0)
	{
		if (stack->list[i] == infos->aligned[0])
			break ;
		i--;
	}
	idx = i;
	i = 0;
	// 2. 해당 인덱스부터 stack->list[0]일 때까지 infos->aligned와 같은 값으로 정렬되었는지 판단한다.
	while (idx >= 0)
	{
		if (!(stack->list[idx] == infos->aligned[i]))
			return (0);
		idx--;
		i++;
	}
	// 3. 만약 정렬되었다면 해당 인덱스 전까지 피봇을 정하고 연산을 진행한다.
	return (i);
}

void	divide_a(t_stack *a, t_stack *b, t_info *infos)
{
	int		i;
	int		end;

	end = find_aligned(a, infos);
	set_pivot(a, infos, end);
	i = a->top;
	while (i >= end)
	{
		if (a->list[a->top] <= infos->pivot)
			pb(b, a);
		else if (a->list[a->top] > infos->pivot)
			ra(a);
		i--;
	}
	if (is_aligned(a, infos->aligned))
		return ;
	while (i >= 0)
	{
		ra(a);
		i--;
	}
}

void	sort_descending(t_stack *stack)
{
	int		i;
	int		max;

	// 1. 가장 큰 숫자의 위치를 찾는다.
	i = stack->top - 1;
	max = stack->top;
	while (i >= 0)
	{
		if (stack->list[max] < stack->list[i])
			max = i;
		i--;
	}
	// 2. 가장 큰 숫자의 위치를 맨 아래로 옮겨준다.
	if (max == stack->top)
		rb(stack);
	if (max == stack->top - 1)
		rrb(stack);
	// 3. 나머지를 연산해준다.
	if (stack->list[stack->top] > stack->list[stack->top - 1])
		sb(stack);
}

void	sort(t_stack *a, t_stack *b, t_info *infos)
{
	int		i;

	if (is_aligned(a, infos->aligned))
		return ;
	if (b->top == -1)
		divide_a(a, b, infos);
	if (b->top < 3)
	{
		sort_descending(b);
		i = b->top;
		while (i >= 0)
		{
			pa(a, b);
			ra(a);
			i--;
		}
	}
	set_pivot(b, infos, 0);
	i = b->top;
	while (i >= 0)
	{
		if (b->list[b->top] == infos->pivot)
			sb(b);
		if (b->list[b->top] > infos->pivot)
			pa(a, b);
		else if (b->list[b->top] < infos->pivot)
			rb(b);
		i--;
	}
	// print_stack(*a, *b);
	sort(a, b, infos);
}

void	push_swap(t_stack *a, t_stack *b, t_info *infos)
{
	if (is_aligned(a, infos->aligned))
		return ;
	else
		sort(a, b, infos);
}