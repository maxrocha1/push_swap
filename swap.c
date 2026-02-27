/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacari- <mmacari-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 11:02:01 by mmacari-          #+#    #+#             */
/*   Updated: 2026/02/27 11:29:15 by mmacari-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



void	swap(t_stack *stack)
{
	int	temp;

	if (!stack || !stack->next)
		return ;
	temp = stack->numbers[0];
	stack->numbers[0] = stack->numbers[1];
	stack->numbers[1] = temp;
}