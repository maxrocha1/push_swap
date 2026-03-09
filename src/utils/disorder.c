/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruribeir <ruribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 13:07:47 by ruribeir          #+#    #+#             */
/*   Updated: 2026/03/05 13:54:48 by ruribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	count_mistakes(t_stack *i, int *mistakes, int *total_pairs)
{
	t_stack	*j;

	j = i->next;
	while (j)
	{
		(*total_pairs)++;
		if (i->value > j->value)
			(*mistakes)++;
		j = j->next;
	}
}

float	compute_disorder(t_stack *stack)
{
	int		mistakes;
	int		total_pairs;
	t_stack	*i;

	mistakes = 0;
	total_pairs = 0;
	if (!stack || !stack->next)
		return (0.0);
	i = stack;
	while (i)
	{
		count_mistakes(i, &mistakes, &total_pairs);
		i = i->next;
	}
	if (total_pairs == 0)
		return (0.0);
	return ((float)mistakes / total_pairs);
}
