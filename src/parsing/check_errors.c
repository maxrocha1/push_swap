/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruribeir <ruribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 12:08:09 by ruribeir          #+#    #+#             */
/*   Updated: 2026/03/06 10:37:06 by ruribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*validate_input(int argc, char **argv)
{
	t_stack	*stack_a;
	int		i;
	long	value;

	stack_a = NULL;
	i = 1;
	while (i < argc)
	{
		if (!is_number(argv[i]))
			exit_error();
		value = ft_atoi_long(argv[i]);
		stack_add_back(&stack_a, stack_new((int)value));
		i++;
	}
	if (check_duplicates(stack_a))
	{
		free_stack(&stack_a);
		exit_error();
	}
	return (stack_a);
}

int	check_duplicates(t_stack *a)
{
	t_stack	*current;
	t_stack	*check;

	if (!a)
		return (0);
	current = a;
	while (current)
	{
		check = current->next;
		while (check)
		{
			if (current->value == check->value)
				return (1);
			check = check->next;
		}
		current = current->next;
	}
	return (0);
}

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

long	ft_atoi_long(const char *str)
{
	long	res;
	int		sign;
	int		i;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		if ((res * sign) > 2147483647 || (res * sign) < -2147483648)
			exit_error();
		i++;
	}
	return (res * sign);
}
