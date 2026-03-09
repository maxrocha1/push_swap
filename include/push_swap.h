/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruribeir <ruribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 12:06:33 by ruribeir          #+#    #+#             */
/*   Updated: 2026/03/06 10:43:45 by ruribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

t_stack	*validate_input(int argc, char **argv);
void	free_stack(t_stack **stack);
void	exit_error(void);
long	ft_atol(const char *str);
int		is_number(char *str);
long	ft_atoi_long(const char *str);
int		check_duplicates(t_stack *stack);
int		check_args_format(int argc, char **argv);

t_stack	*stack_new(int value);
void	stack_add_back(t_stack **stack, t_stack *new_node);
int		stack_size(t_stack *stack);
t_stack	*stack_last(t_stack *stack);

float	compute_disorder(t_stack *stack);
bool	is_sorted(t_stack *stack);

void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	get_pos(t_stack *stack);
int		get_max_pos(t_stack *stack);
int		get_min_pos(t_stack *stack);
int		abs_val(int n);

void	sort_simple(t_stack **a, t_stack **b);
void	sort_medium(t_stack **a, t_stack **b);
void	sort_complex(t_stack **a, t_stack **b);
void	sort_adaptative(t_stack **a, t_stack **b);
void	update_targets(t_stack *a, t_stack *b);
void	calculate_cost(t_stack *a, t_stack *b);
void	do_cheapest_move(t_stack **a, t_stack **b);
void	prepare_back_to_a(t_stack **a, t_stack **b);
void	sort_three(t_stack **a);
void	back_to_a(t_stack **a, t_stack **b);
void	last_shift(t_stack **a);
void	assign_index(t_stack *stack, int stack_size);

#endif