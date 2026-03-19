/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacari- <mmacari-@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 14:23:48 by ruribeir          #+#    #+#             */
/*   Updated: 2026/03/19 14:53:08 by mmacari-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_resources(t_stack **a, t_stack **b)
{
	free_stack(a);
	free_stack(b);
}

static void	push_swap(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	if (size == 2 && !is_sorted(*a))
		sa(*a);
	else if (size == 3)
		sort_three(a);
	else if (size <= 5)
		sort_simple(a, b);
	else
		sort_complex(a, b);
}

static int	fill_stack(t_stack **a, int argc, char **argv)
{
	t_stack	*new;
	int		i;
	long	val;

	i = 1;
	while (i < argc)
	{
		val = ft_atol(argv[i]);
		new = stack_new((int)val);
		if (!new)
			return (0);
		stack_add_back(a, new);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	a = NULL;
	b = NULL;
	if (!validate_input(argc, argv))
		exit_error();
	if (!fill_stack(&a, argc, argv))
	{
		free_resources(&a, &b);
		exit_error();
	}
	if (!is_sorted(a))
	{
		assign_index(a, stack_size(a));
		push_swap(&a, &b);
	}
	free_resources(&a, &b);
	return (0);
}
