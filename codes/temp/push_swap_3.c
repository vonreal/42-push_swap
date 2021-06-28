/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 19:53:42 by jna               #+#    #+#             */
/*   Updated: 2021/06/28 17:22:27 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_aligned(t_stack *stack, int *aligned)
{
	int		i;
	int		j;

	i = stack->top;
	while (i >= 0)
	{
		j = 0;
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

int		get_max_num_idx(t_stack *stack, t_info *infos)
{
	int		i;
	int		max;

	i = stack->top - 1;
	max = stack->top;
	while (i >= 0)
	{
		if (stack->list[max] < stack->list[i])
			max = i;
		i--;
	}
	max = get_idx_aligned(stack->list[max], infos);
	return (max);
}

int		get_min_num_idx(t_stack *stack, t_info *infos)
{
	int		i;
	int		min;

	i = stack->top - 1;
	min = stack->top;
	while (i >= 0)
	{
		if (stack->list[min] > stack->list[i])
			min = i;
		i--;
	}
	min = get_idx_aligned(stack->list[min], infos);
	return (min);
}

void	set_pivot(t_stack *stack, t_info *infos)
{
	int		max;
	int		min;

	max = get_max_num_idx(stack, infos);
	min = get_min_num_idx(stack, infos);
	infos->midian = (max + min) / 2;
	infos->pivot = infos->aligned[infos->midian];
}

static void	sort_rest(t_stack *stack)
{
	int	top;

	top = stack->top;
	if (stack->list[top] > stack->list[top - 1])
		sa(stack);
}

static int	get_big_num_index(t_stack *stack)
{
	int		i;
	int		idx;

	i = 1;
	idx = 0;
	while (i <= stack->top)
	{
		if (stack->list[idx] < stack->list[i])
			idx = i;
		i++;
	}
	return (idx);
}

static void	sort_three(t_stack *stack)
{
	int		i;
	int		big_idx;

	// 1. 가장 큰 수의 위치를 찾는다.
	i = stack->top;
	big_idx = stack->top;
	while (i >= stack->top - 2)
	{
		if (stack->list[big_idx] < stack->list[i])
			big_idx = i;
		i--;
	}
	// 2. 위치에 따라 가장 큰 수를 맨 아래로 옮겨준다.
	if (big_idx == stack->top)
	{
		sa(stack);
		ra(stack);
		sa(stack);
		rra(stack);
	}
	else if (big_idx == stack->top - 1)
	{
		ra(stack);
		sa(stack);
		rra(stack);
	}
	// 3. 나머지 연산
	if (stack->list[stack->top] > stack->list[stack->top - 1])
		sa(stack);
}

void	sort(t_stack *a, t_stack *b, t_info *infos)
{
	int		i;

	set_pivot(a, infos);
	// 1. 1을 찾는다.
	// 2. stack->list[0] 까지 정렬이 되었는가?
	// 3. yes. 그렇다면 1의 인덱스를 기억한다.
	// 4. 1의 인덱스 전까지의 max와 min을 찾는다.
	// 5. 1의 인덱스 위까지 3개가 남을때까지 계속해서 max는 넘긴다.
	// 6. 3개는 정렬하고 ra() * 3으로 정렬해준다.
	if (a->top <= 2)
	{
		sort_three(a);
		return ;
	}
	i = a->top;
	while (i >= 0)
	{
		if (a->list[a->top] == infos->pivot)
			sa(a);
		if (a->list[a->top] > infos->pivot)
			pb(b, a);
		else if (a->list[a->top] < infos->pivot)
			ra(a);
		i--;
	}
	sort(a, b, infos);
}

void	sort_b(t_stack *a, t_stack *b, t_info *infos)
{
	int		i;

	set_pivot(b, infos);
	i = b->top;
	while (i >= 0)
	{
		if (b->list[b->top] == infos->pivot)
			sb(b);
		if (b->list[b->top] < infos->pivot)
			pa(a, b);
		else if (b->list[b->top] > infos->pivot)
			rb(b);
		i--;
	}
	sort_three(a);
}

void	push_swap(t_stack *a, t_stack *b, t_info *infos)
{
	if (is_aligned(a, infos->aligned))
		return ;
	else
	{
		sort(a, b, infos);
		sort_b(a, b, infos);
	}
}
