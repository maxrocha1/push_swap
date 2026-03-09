/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruribeir <ruribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 14:10:09 by ruribeir          #+#    #+#             */
/*   Updated: 2026/03/04 15:37:23 by ruribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_target_in_b(t_stack *b, int index_a)
{
	t_stack	*tmp;
	int		target_idx;
	long	max_smaller;

	tmp = b;
	target_idx = -1;
	max_smaller = -1;
	while (tmp)
	{
		if (tmp->index < index_a && tmp->index > max_smaller)
		{
			max_smaller = tmp->index;
			target_idx = tmp->pos;
		}
		tmp = tmp->next;
	}
	if (target_idx == -1)
		return (get_max_pos(b));
	return (target_idx);
}

void	update_targets(t_stack *a, t_stack *b)
{
	t_stack	*tmp_a;

	tmp_a = a;
	while (tmp_a)
	{
		tmp_a->target_pos = get_target_in_b(b, tmp_a->index);
		tmp_a = tmp_a->next;
	}
}

void	calculate_cost(t_stack *a, t_stack *b)
{
	int	size_a;
	int	size_b;

	size_a = stack_size(a);
	size_b = stack_size(b);
	while (a)
	{
		if (a->pos <= size_a / 2)
			a->cost_a = a->pos;
		else
			a->cost_a = (size_a - a->pos) * -1;
		if (a->target_pos <= size_b / 2)
			a->cost_b = a->target_pos;
		else
			a->cost_b = (size_b - a->target_pos) * -1;
		a = a->next;
	}
}

void	prepare_back_to_a(t_stack **a, t_stack **b)
{
	t_stack	*tmp_a;
	long	target_idx;
	int		target_pos;
	int		i;

	tmp_a = *a;
	target_idx = 2147483647;
	target_pos = 0;
	i = 0;
	while (tmp_a)
	{
		if (tmp_a->index > (*b)->index && tmp_a->index < target_idx)
		{
			target_idx = tmp_a->index;
			target_pos = i;
		}
		tmp_a = tmp_a->next;
		i++;
	}
	if (target_idx == 2147483647)
		target_pos = get_min_pos(*a);
	(*b)->target_pos = target_pos;
}
