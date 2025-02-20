/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:48:47 by guphilip          #+#    #+#             */
/*   Updated: 2025/02/20 12:12:26 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/// @brief Rotates stacks A and B until the target node in B is on top of stack
/// @param a Pointer to the stack's A head pointer
/// @param b Pointer to stack's B head pointer
/// @param cheapest_node Node in stack A considered as the cheapest to move
/// @param rot The function to be used ('rr' or 'rrr')
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

/// @brief Moves the cheapest node fron stack A to stack B
/// @param a Pointer to the stack A head pointer
/// @param b Pointer to the stack B head pointer
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

/// @brief Moves a node from stack B to stack A
/// @param a Pointer to the stack A's head pointer
/// @param b Pointer to the stack B's head pointer
static void	move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	push_prep(a, (*b)->target_node, 'a');
	pa(a, b, true);
}

/// @brief Moves the smallest element to the top of stack A
/// @param a Pointer to the stack A's pointer
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

/// @brief Sort the stacks by moving elements from stack A to stack B, sorting
/// A in the meantime
/// @param a Pointer to the A's stack head
/// @param b Pointer to the B's stack head
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
