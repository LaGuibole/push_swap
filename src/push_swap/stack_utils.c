/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:17:01 by guphilip          #+#    #+#             */
/*   Updated: 2025/02/20 12:44:28 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/// @brief Calculates the length of the stack
/// @param stack Pointer to the head of the stack
/// @return The number of elements in the stack
int	stack_len(t_stack_node *stack)
{
	int	count;

	if (!stack)
		return (0);
	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

/// @brief Finds the last node of the stack
/// @param stack Pointer to the head of the stack
/// @return Pointer to the last node, or NULL is stack is empty
t_stack_node	*find_last(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
	{
		stack = stack->next;
	}
	return (stack);
}

/// @brief Check if the stack is sorted in ascending order
/// @param stack Pointer to the head of the stack
/// @return True if the stack is sorted, false otherwise
bool	stack_sorted(t_stack_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}

/// @brief Finds the node with the minimum value in the stack
/// @param stack Pointer to the head of the stack
/// @return Pointer to the node containing the smallest value or NULL if stack
/// is empty
t_stack_node	*find_min(t_stack_node *stack)
{
	long			min;
	t_stack_node	*min_node;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->nbr < min)
		{
			min = stack->nbr;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

/// @brief Finds the node with the maximum value in the stack
/// @param stack Pointer to the head of the stack
/// @return Pointer to the node containing the largest value,
/// or NULL if the stack is empty
t_stack_node	*find_max(t_stack_node *stack)
{
	long			max;
	t_stack_node	*max_node;

	if (!stack)
		return (NULL);
	max = LONG_MIN;
	while (stack)
	{
		if (stack->nbr > max)
		{
			max = stack->nbr;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}
