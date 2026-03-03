/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruribeir <ruribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 13:07:47 by ruribeir          #+#    #+#             */
/*   Updated: 2026/03/03 13:16:19 by ruribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	compute_disorder(t_stack *stack)
{
	int	mistakes;
	int	total_pairs;
	t_stack *i;
	t_stack *j;

	mistakes = 0;
	total_pairs= 0;
	if (!stack || !stack->next)
		return (0.0);
	i = stack;
	while (i)
	{
		j = i->next;
		while (j)
		{
			total_pairs++;
			if (i->value > j->value)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	if (total_pairs == 0)
		return (0.0);
	return ((float)mistakes / total_pairs);
}
