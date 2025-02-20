/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:15:22 by guphilip          #+#    #+#             */
/*   Updated: 2025/02/20 12:35:07 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

/// @brief Converts a string to a long integer
/// @param nptr The string to convert
/// @return The converted long integer
static long	ft_atol(const char	*nptr)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	while (((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' '))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res *= 10;
		res += nptr[i] - '0';
		i++;
	}
	return (res * sign);
}

/// @brief Adds a new node to the stack
/// @param stack Pointer to the head of the stack
/// @param n Value to store in the new node
static void	add_node(t_stack_node **stack, int n)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->next = NULL;
	node->nbr = n;
	node->cheapest = 0;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

/// @brief Check if a number has a valid length to fit within an int
/// @param test The string representing the number
/// @return 1 if the number is too long 0 otherwise
int check_len(char *test)
{
	int count;

	count = 0;
	if (*test == '-' || *test == '+')
		test++;
	while (*test == '0')
	{
		test++;
	}
	count = ft_strlen(test);
	if (count > 11)
		return (1);
	return (0);
}

/// @brief Initializes stack A with values from arguments
/// @param a Pointer to the head of stack A
/// @param argv Array of input arguments
/// @param argc Number of arguments
void	init_stack_a(t_stack_node **a, char **argv, int argc)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (syntax_error(argv[i]))
			free_errors(a, argv, argc);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN || check_len(argv[i]))
			free_errors(a, argv, argc);
		if (duplicate_error(*a, (int)n))
			free_errors(a, argv, argc);
		add_node(a, (int)n);
		i++;
	}
}

/// @brief Finds the cheapest node in the stack
/// @param stack Pointer to the head of the stack
/// @return Pointer to the cheapest node
t_stack_node	*get_cheapest(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

/// @brief Moves the top node to the correct position before pushing
/// @param stack POinter to the head of the stack
/// @param top_node The node to be positioned
/// @param stack_name The stack identifier "a" or "b"
void	push_prep(t_stack_node **stack, t_stack_node *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack, true);
			else
				rra(stack, true);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack, true);
			else
				rrb(stack, true);
		}
	}
}
