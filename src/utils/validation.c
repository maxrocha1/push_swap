/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruribeir <ruribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 14:35:48 by ruribeir          #+#    #+#             */
/*   Updated: 2026/03/05 22:08:46 by ruribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_numeric(char *str)
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

static int	is_out_of_range(char *str)
{
	long	val;

	val = ft_atol(str);
	if (val < -2147483648 || val > 2147483647)
		return (1);
	return (0);
}

int	check_args_format(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!is_numeric(argv[i]))
			return (0);
		if (is_out_of_range(argv[i]))
			return (0);
		i++;
	}
	return (1);
}
