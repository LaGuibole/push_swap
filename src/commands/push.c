/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:02:58 by guphilip          #+#    #+#             */
/*   Updated: 2025/02/20 11:54:02 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/// @brief Moves the top element from source stack to dest stack
/// @param dst Pointer to the dest stack
/// @param src Pointer to the src stack
static void	push(t_stack_node **dst, t_stack_node **src)
{
	t_stack_node	*push_node;

	if (!*src)
		return ;
	push_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	push_node->prev = NULL;
	if (!*dst)
	{
		*dst = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *dst;
		push_node->next->prev = push_node;
		*dst = push_node;
	}
}

/// @brief Pushes the top element from stack B to stack A
/// @param a Pointer to stack A (destination stack)
/// @param b Pointer to stack B (source stack)
/// @param print Prints pa if true
void	pa(t_stack_node **a, t_stack_node **b, bool print)
{
	push(a, b);
	if (print)
		ft_printf("pa\n");
}

/// @brief Pushes the top element from stack A to stack B
/// @param b Pointer to stack B (destination stack)
/// @param a Pointer to stack A (source stack)
/// @param print Prints pb if true
void	pb(t_stack_node **b, t_stack_node **a, bool print)
{
	push(b, a);
	if (print)
		ft_printf("pb\n");
}
