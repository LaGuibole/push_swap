/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 09:47:08 by guphilip          #+#    #+#             */
/*   Updated: 2025/02/20 12:02:24 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/// @brief Rotates the stack (first element becomes last)
/// @param stack Pointer to the stack's head pointer
static void	rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = find_last(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

/// @brief Performs a rotate on stack A
/// @param a Pointer to the stack's A head pointer
/// @param print Print ra if true
void	ra(t_stack_node **a, bool print)
{
	rotate(a);
	if (print)
		ft_printf("ra\n");
}

/// @brief Performs a rotate on stack B
/// @param b Pointer to the stack's B head pointer
/// @param print Print rb if true
void	rb(t_stack_node **b, bool print)
{
	rotate(b);
	if (print)
		ft_printf("rb\n");
}

/// @brief Performs a rotate on both A and B stack
/// @param a Pointer to the stack's A head pointer
/// @param b Pointer to the stack's B head pointer
/// @param print Print rr if true
void	rr(t_stack_node **a, t_stack_node **b, bool print)
{
	rotate(a);
	rotate(b);
	if (print)
		ft_printf("rr\n");
}
