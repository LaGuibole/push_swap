/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:48:47 by guphilip          #+#    #+#             */
/*   Updated: 2025/01/20 15:36:45 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	rotate_both(
	t_stack_node **a,
	t_stack_node **b,
	t_stack_node *cheapest_node,
	t_rotator rot
)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rot(a, b, true);
	current_index(*a);
	current_index(*b);
}

static void	move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node, rr);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		rotate_both(a, b, cheapest_node, rrr);
	push_prep(a, cheapest_node, 'a');
	push_prep(b, cheapest_node->target_node, 'b');
	pb(b, a, true);
}

static void	move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	push_prep(a, (*b)->target_node, 'a');
	pa(a, b, true);
}

static void	min_on_top(t_stack_node **a)
{
	while ((*a)->nbr != find_min(*a)->nbr)
	{
		if (find_min(*a)->above_median)
			ra(a, true);
		else
			rra(a, true);
	}
}

void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a, true);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a, true);
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}
