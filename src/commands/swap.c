/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:06:03 by guphilip          #+#    #+#             */
/*   Updated: 2025/02/20 17:28:31 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/// @brief Swap first two elements of the 2 stacks
/// @param head A pointer to the head of the stack
static void	swap(t_stack_node **head)
{
	if (!head || !(*head)->next)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

/// @brief Swaps the first two element of stack A
/// @param a Pointer to the stack A's head pointer
/// @param print Print the move sa if true
void	sa(t_stack_node **a, bool print)
{
	swap(a);
	if (print)
		ft_printf("sa\n");
}

/// @brief Swaps the first two elements of stack B
/// @param b Pointer to the stack B's head pointer
/// @param print Print sb if true
void	sb(t_stack_node **b, bool print)
{
	swap(b);
	if (print)
		ft_printf("sb\n");
}

/// @brief Swaps the first two elements of both stack A and B
/// @param a Pointer the the stack A's head pointer
/// @param b POinter to the stack B's head pointer
/// @param print Print ss if true
void	ss(t_stack_node **a, t_stack_node **b, bool print)
{
	swap(a);
	swap(b);
	if (print)
		ft_printf("ss\n");
}
