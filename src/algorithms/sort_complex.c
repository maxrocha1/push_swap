/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruribeir <ruribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 10:12:55 by ruribeir          #+#    #+#             */
/*   Updated: 2026/03/04 15:33:20 by ruribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_complex(t_stack **a, t_stack**b)
{
	if (stack_size(*a) > 3 && !is_sorted(*a))
		pb(a, b);
	if (stack_size(*a) > 3 && !is_sorted(*a))
		pb(a, b);
	while (stack_size(*a) > 3 && !is_sorted(*a))
	{
		get_pos(*a);
		get_pos(*b);
		update_targets(*a, *b);
		calculate_cost(*a, *b);
		do_cheapest_move(a, b);
	}
	sort_three(a);
	while (*b)
	{
		prepare_back_to_a(a, b);
		back_to_a(a, b);
	}
	last_shift(a);
}

static void	rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		rr(a, b);
	}
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		rrr(a, b);
	}
}

void	do_cheapest_move(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	t_stack	*cheapest_node;
	int		min_cost;

	tmp = *a;
	min_cost = 2147483647;
	while (tmp)
	{
		if (abs_val(tmp->cost_a) + abs_val(tmp->cost_b) < min_cost)
		{
			min_cost = abs_val(tmp->cost_a) + abs_val(tmp->cost_b);
			cheapest_node = tmp;
		}
		tmp = tmp->next;
	}
	rotate_both(a, b, &cheapest_node->cost_a, &cheapest_node->cost_b);
	while (cheapest_node->cost_a > 0 && (cheapest_node->cost_a)--)
		ra(a);
	while (cheapest_node->cost_a < 0 && (cheapest_node->cost_a)++)
		rra(a);
	while (cheapest_node->cost_b > 0 && (cheapest_node->cost_b)--)
		rb(b);
	while (cheapest_node->cost_b < 0 && (cheapest_node->cost_b)++)
		rrb(b);
	pb(a, b);
}

void	back_to_a(t_stack **a, t_stack **b)
{
	int	size_a;

	size_a = stack_size(*a);
	if ((*b)->target_pos <= size_a / 2)
		while ((*b)->target_pos--)
			ra(a);
	else
		while ((*b)->target_pos++ < size_a)
			rra(a);
	pa(a, b);
}

void	last_shift(t_stack **a)
{
	int	size;
	int	min_pos;

	size = stack_size(*a);
	min_pos = get_min_pos(*a);
	if (min_pos <= size / 2)
		while (get_min_pos(*a) != 0)
			ra(a);
	else
		while (get_min_pos(*a) != 0)
			rra(a);
}
