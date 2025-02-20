/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:06:39 by guphilip          #+#    #+#             */
/*   Updated: 2025/02/20 11:59:16 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/// @brief Rotates the stack in reverse (last element becomes first)
/// @param stack Pointer to the stack's head pointer
static void	rev_rotate(t_stack_node **stack)
{
	t_stack_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = find_last(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

/// @brief Reverse rotates on stack A
/// @param a Pointer to the stack A's head pointer
/// @param print Print rra if true
void	rra(t_stack_node **a, bool print)
{
	rev_rotate(a);
	if (print)
		ft_printf("rra\n");
}

/// @brief Reverse rotates on stack B
/// @param b Pointer to the stack B's head pointer
/// @param print Print rrb if true
void	rrb(t_stack_node **b, bool print)
{
	rev_rotate(b);
	if (print)
		ft_printf("rrb\n");
}

/// @brief Performs a rev rotate on both A and B stacks
/// @param a Pointer to the head of A stack
/// @param b Pointer to the head of B stack
/// @param print Print rrr if true
void	rrr(t_stack_node **a, t_stack_node **b, bool print)
{
	rev_rotate(a);
	rev_rotate(b);
	if (print)
		ft_printf("rrr\n");
}
