/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruribeir <ruribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 13:55:47 by ruribeir          #+#    #+#             */
/*   Updated: 2026/03/05 14:22:28 by ruribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_pos(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack->pos = i;
		stack = stack->next;
		i++;
	}
}

int	get_min_pos(t_stack *stack)
{
	int	min_idx;
	int	min_pos;

	if (!stack)
		return (-1);
	get_pos(stack);
	min_idx = stack->index;
	min_pos = stack->pos;
	while (stack)
	{
		if (stack->index < min_idx)
		{
			min_idx = stack->index;
			min_pos = stack->pos;
		}
		stack = stack->next;
	}
	return (min_pos);
}

int	get_max_pos(t_stack *stack)
{
	int	max_idx;
	int	max_pos;

	if (!stack)
		return (-1);
	get_pos(stack);
	max_idx = stack->index;
	max_pos = stack->pos;
	while (stack)
	{
		if (stack->index > max_idx)
		{
			max_idx = stack->index;
			max_pos = stack->pos;
		}
		stack = stack->next;
	}
	return (max_pos);
}

int	abs_val(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

void	assign_index(t_stack *stack, int stack_size)
{
	t_stack	*ptr;
	t_stack	*highest;
	long	value;

	while (--stack_size >= 0)
	{
		ptr = stack;
		value = -2147483649L;
		highest = NULL;
		while (ptr)
		{
			if (ptr->value > value && ptr->index == -1)
			{
				value = ptr->value;
				highest = ptr;
			}
			ptr = ptr->next;
		}
		if (highest)
			highest->index = stack_size;
	}
}
