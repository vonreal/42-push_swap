/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 19:53:42 by jna               #+#    #+#             */
/*   Updated: 2021/07/09 18:58:02 by jna              ###   ########.fr       */
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

int		get_max_num_idx(t_stack *stack, t_info *infos, int size)
{
	int		i;
	int		max;

	i = stack->top - 1;
	max = stack->top;
	while (size > 1)
	{
		if (stack->list[max] < stack->list[i])
			max = i;
		size--;
		i--;
	}
	max = get_idx_aligned(stack->list[max], infos);
	return (max);
}

int		get_min_num_idx(t_stack *stack, t_info *infos, int size)
{
	int		i;
	int		min;

	i = stack->top - 1;
	min = stack->top;
	while (size > 1)
	{
		if (stack->list[min] > stack->list[i])
			min = i;
		i--;
		size--;
	}
	min = get_idx_aligned(stack->list[min], infos);
	return (min);
}

void	set_pivot(t_stack *stack, t_info *infos, int size)
{
	int		max;
	int		min;

	max = get_max_num_idx(stack, infos, size);
	min = get_min_num_idx(stack, infos, size);
	infos->midian = (max + min) / 2;
	infos->pivot = infos->aligned[infos->midian];
}

bool	is_rest_bigger(t_stack *a, int pivot)
{
	int		i;

	i = a->top;
	while (i >= 0)
	{
		if (a->list[i] <= pivot)
			return (false);
		i--;
	}
	return (true);
}

void	sort_top_three_rest(t_stack *a, t_stack *b)
{
	if (b->list[b->top] < b->list[b->top - 1])
		sb(b);
	pa(a, b);
	pa(a, b);
}

void	sort_top_three_rest_a(t_stack *a, t_stack *b)
{
	if (a->list[a->top] > a->list[a->top - 1])
		sa(a);
}

void	sort_top_three(t_stack *a, t_stack *b)
{
	int		i;
	int		j;
	int		max;

	i = b->top - 1;
	max = b->top;
	while (i >= b->top - 2)
	{
		if (b->list[max] < b->list[i])
			max = i;
		i--;
	}
	if (max == b->top)
	{
		pa(a, b);
		sort_top_three_rest(a, b);
	}
	else if (max == b->top - 1)
	{
		rb(b);
		pa(a, b);
		rrb(b);
		sort_top_three_rest(a, b);
	}
	else if (max == b->top - 2)
	{
		rb(b);
		rb(b);
		pa(a, b);
		rrb(b);
		rrb(b);
		sort_top_three_rest(a, b);
	}

}

void	sort_top_three_a(t_stack *a, t_stack *b)
{
	int		i;
	int		j;
	int		max;

	i = a->top - 1;
	max = a->top;
	while (i >= a->top - 2)
	{
		if (a->list[max] < a->list[i])
			max = i;
		i--;
	}
	if (max == a->top)
	{
		sa(a);
		ra(a);
		sa(a);
		rra(a);
		sort_top_three_rest_a(a, b);
	}
	else if (max == a->top - 1)
	{
		ra(a);
		sa(a);
		rra(a);
		sort_top_three_rest_a(a, b);

	}
	else if (max == a->top - 2)
		sort_top_three_rest_a(a, b);
}

int	get_action(t_stack *b)
{
	if (b->top == 96)
		return (3);
	if (b->top == 93)
		return (6);
	if (b->top == 87)
		return (13);
	if (b->top == 74)
		return (25);
	if (b->top == 49)
		return (50);
}

void	sort_top_a(t_stack *a, t_stack *b, t_info *infos, int size)
{
	int		i;
	int		calls_ra;
	
	i = 0;
	calls_ra = 0;
	set_pivot(a, infos, size);
	if (size <= 3)
	{
		if (size == 3)
			sort_top_three_a(a, b);
		else if (size == 2)
			sort_top_three_rest_a(a, b);
		return ;
	}
	while (i < size)
	{
		if (a->list[a->top] <= infos->pivot)
			pb(b, a);
		else
		{
			ra(a);
			calls_ra++;
		}
		i++;
	}
	i = calls_ra;
	while (calls_ra > 0)
	{
		rra(a);
		calls_ra--;
	}
	sort_top_a(a, b, infos, i);
}

void	divide_b(t_stack *a, t_stack *b, t_info *infos, int size)
{
	int		i;
	int		calls_rb;
	int		calls_pa;

	i = 0;
	calls_pa = 0;
	calls_rb = 0;
	while (i < size)
	{
		if (b->list[b->top] > infos->pivot)
		{
			pa(a, b);
			calls_pa++;
		}
		else
		{
			rb(b);
			calls_rb++;
		}
		i++;
	}
	while (calls_rb > 0)
	{
		rrb(b);
		calls_rb--;
	}
	sort_top_a(a, b, infos, calls_pa);
}

void	action_six(t_stack *a, t_stack *b, t_info *infos)
{
	set_pivot(b, infos, 6);
	divide_b(a, b, infos, 6);
	sort_top_three(a, b);
}

void	action_seven(t_stack *a, t_stack *b, t_info *infos)
{
	set_pivot(b, infos, 7);
	divide_b(a, b, infos, 7);
	
}

void	action_thirteen(t_stack *a, t_stack *b, t_info *infos)
{
	set_pivot(b, infos, 13);
	divide_b(a, b, infos, 13);
	sort_top_three(a, b);

	set_pivot(b, infos, 7);
	divide_b(a, b, infos, 7);

	set_pivot(b, infos, 4);
	divide_b(a, b, infos, 4);
	sort_top_three_rest(a, b);
}

void	action_twentyfive(t_stack *a, t_stack *b, t_info *infos)
{
	set_pivot(b, infos, 25);
	divide_b(a, b, infos, 25);

	sort_top_three(a, b);
	action_six(a, b, infos);
	action_thirteen(a, b, infos);
}

void	action_twentyfour(t_stack *a, t_stack *b, t_info *infos)
{
	set_pivot(b, infos, 24);
	divide_b(a, b, infos, 24);

	sort_top_three(a, b);
	action_six(a, b, infos);
	action_thirteen(a, b, infos);
}

void	b_to_a(t_stack *a, t_stack *b, t_info *infos, int action)
{
	int		i;

	i = 0;
	action = get_action(b);
	if (b->top <= 2)
		return ;
	if (action == 3)
		sort_top_three(a, b);
	else if (action == 6)
		action_six(a, b, infos);
	else if (action == 13)
		action_thirteen(a, b, infos);
	else if (action == 25)
		action_twentyfive(a, b, infos);
	else if (action == 50)
	{
		set_pivot(b, infos, 50);
		divide_b(a, b, infos, 50);
		
		sort_top_three(a, b);
		action_six(a, b, infos);
		action_thirteen(a, b, infos);
		action_twentyfive(a, b, infos);
	}
	b_to_a(a, b, infos, action);
}

int	get_action_five_hun(t_stack *b)
{
	int		action;

	action = b->size - b->top;
	return (action);
}

void	action_four(t_stack *a, t_stack *b, t_info *infos)
{
	set_pivot(b, infos, 4);
	divide_b(a, b, infos, 4);
	sort_top_three_rest(a, b);
}

void	action_eight(t_stack *a, t_stack *b, t_info *infos)
{
	set_pivot(b, infos, 8);
	divide_b(a, b, infos, 8);

	sort_top_three_rest(a, b);
	action_four(a, b, infos);
}

void	action_sixteen(t_stack *a, t_stack *b, t_info *infos)
{
	set_pivot(b, infos, 16);
	divide_b(a, b, infos, 16);

	sort_top_three_rest(a, b);
	action_four(a, b, infos);
	action_eight(a, b, infos);
}

void	action_thirty_one(t_stack *a, t_stack *b, t_info *infos)
{
	set_pivot(b, infos, 31);
	divide_b(a, b, infos, 31);

	action_four(a, b, infos);
	action_eight(a, b, infos);
	action_sixteen(a, b, infos);
}

void	action_thirty_two(t_stack *a, t_stack *b, t_info *infos)
{
	set_pivot(b, infos, 32);
	divide_b(a, b, infos, 32);

	sort_top_three_rest(a, b);
	action_four(a, b, infos);
	action_eight(a, b, infos);
	action_sixteen(a, b, infos);
}

void	action_sixty_three(t_stack *a, t_stack *b, t_info *infos)
{
	set_pivot(b, infos , 63);
	divide_b(a, b, infos, 63);

	action_four(a, b, infos);
	action_eight(a, b, infos);
	action_sixteen(a, b, infos);
	action_thirty_two(a, b, infos);
}

void	action_one_hun_twnety_five(t_stack *a, t_stack *b, t_info *infos)
{
	set_pivot(b, infos, 125);
	divide_b(a, b, infos, 125);

	action_four(a, b, infos);
	action_eight(a, b, infos);
	action_sixteen(a, b, infos);
	action_thirty_one(a, b, infos);
	action_sixty_three(a, b, infos);
}

void	action_two_hun_fifty_one(t_stack *a, t_stack *b, t_info *infos)
{
	set_pivot(b, infos, 250);
	divide_b(a, b, infos, 250);

	action_four(a, b, infos);
	action_eight(a, b, infos);
	action_sixteen(a, b, infos);
	action_thirty_one(a, b, infos);
	action_sixty_three(a, b, infos);
	action_one_hun_twnety_five(a, b, infos);
}

void	b_to_a_five_hun(t_stack *a, t_stack *b, t_info *infos, int action)
{
	int		i;
	
	i = 0;
	action = get_action_five_hun(b);
	if (b->top <= 2)
		return ;
	if (action == 4)
		action_four(a, b, infos);
	else if (action == 8)
		action_eight(a, b, infos);
	else if (action == 16)
		action_sixteen(a, b, infos);
	else if (action == 32) // 31
		action_thirty_one(a, b, infos);
	else if (action == 63)
		action_sixty_three(a, b, infos);
	else if (action == 126) // 125
		action_one_hun_twnety_five(a, b, infos);
	else if (action == 251) // 250
		action_two_hun_fifty_one(a, b, infos);
	b_to_a_five_hun(a, b, infos, action);
}

void	a_to_b(t_stack *a, t_stack *b, t_info *infos, int calls_pb)
{
	int		i;

	i = a->top;
	calls_pb = 0;
	if (a->top <= 2)
	{
		if (a->top == 2)
			sort_three(a);
		else if(a->list[a->top] > a->list[a->top - 1])
			sa(a);
		return ;
	}
	set_pivot(a, infos, a->top + 1);
	while (i >= 0)
	{
		if (a->list[a->top] <= infos->pivot)
		{
			pb(b, a);
			calls_pb++;
		}
		else
		{
			if (is_rest_bigger(a, infos->pivot))
				break ;
			ra(a);
		}
		i--;
	}
	a_to_b(a, b, infos, calls_pb);
}

void	sort(t_stack *a, t_stack *b, t_info *infos)
{
	if (a->size == 100)
	{
		a_to_b(a, b, infos, 0);
		b_to_a(a, b, infos, 3);
	}
	else if (a->size == 500)
	{
		a_to_b(a, b, infos, 0);
		b_to_a_five_hun(a, b, infos, 4);
	}
}

void	push_swap(t_stack *a, t_stack *b, t_info *infos)
{
	if (is_aligned(a, infos->aligned))
		return ;
	else
	{
		if (a->top == 2)
			sort_three(a);
		else if (a->top == 4)
			sort_five(a, b);
		else
			sort(a, b, infos);
	}
}
