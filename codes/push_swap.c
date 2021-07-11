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

void    recursive_sort_even(t_stack *a, t_stack *b, int chunk)
{
    if (chunk == 2)
        sort_top_three_rest(a, b);
    else if (chunk == 3)
        sort_top_three(a, b);
    else
        recursive_sort_even(a, b, chunk / 2);
}

void    recursive_sort(t_stack *a, t_stack *b, t_info *infos, int chunk)
{
    if (chunk == 2)
        sort_top_three_rest(a, b);
    else if (chunk == 3)
        sort_top_three(a, b);
    else
    {
        set_pivot(a, infos, chunk);
        divide_b(a, b, infos, chunk);
        if (chunk > 7)
        {
            recursive_sort_even(a, b, chunk / 2);
            if (chunk % 2 == 0)
            {
                recursive_sort(a, b, infos, (chunk / 2) / 2);
                if (chunk > 12)
                    recursive_sort(a, b, infos, (chunk / 2) / 2 + 1)
            }
        }
        recursive_sort(a, b, infos, chunk - (chunk / 2));
    }
}

void	b_to_a(t_stack *a, t_stack *b, t_info *infos, int chunk)
{
    if (b->top == 0)
        return ;
    else
        recursive_sort(a, b, infos, chunk);
    b_to_a(a, b, infos, b->size - (b->top + 1));
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
