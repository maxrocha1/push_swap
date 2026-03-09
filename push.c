/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacari- <mmacari-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 14:51:24 by mmacari-          #+#    #+#             */
/*   Updated: 2026/03/04 15:40:25 by mmacari-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_stack(t_stack **from, t_stack **to)
{
	t_stack	*temp;

	temp = *from;
	*from = (*from)->next;
	temp->next = *to;
	*to = temp;
}

void	pa(t_stack **a, t_stack **b)
{
	push_stack(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	push_stack(a, b);
	write(1, "pb\n", 3);
}
