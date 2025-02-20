/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:51:52 by guphilip          #+#    #+#             */
/*   Updated: 2025/02/20 17:36:05 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

/// @brief Checks for syntax errors in a given string
/// @param str_n The string to check
/// @return 1 if there is a syntax error, 0 otherwise
int	syntax_error(char *str_n)
{
	if (!(*str_n == '+' || *str_n == '-' || (*str_n >= '0' && *str_n <= '9')))
		return (1);
	if ((*str_n == '+' || *str_n == '-')
		&& !(str_n[1] >= '0' && str_n[1] <= '9'))
		return (1);
	while (*++str_n)
	{
		if (!(*str_n >= '0' && *str_n <= '9'))
			return (1);
	}
	return (0);
}

/// @brief Checks for duplicate values in the stack
/// @param a Pointer to the head of stack A
/// @param n The number to check for duplicates
/// @return 1 if a duplicate is found, 0 otherwise
int	duplicate_error(t_stack_node *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->nbr == n)
			return (1);
		a = a->next;
	}
	return (0);
}

/// @brief Free all nodes in the stack and sets it to NULL
/// @param stack Pointer to the head pointer of the stack
void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		current->nbr = 0;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

/// @brief Frees allocated memory and exits the program with an error
/// @param a Pointer to the head pointer of stack A
/// @param argv The argument array that may need cleanup()
/// @param argc The argument count
void	free_errors(t_stack_node **a, char **argv, int argc)
{
	cleanup(a, argv, argc);
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(1);
}

void	error_message(void)
{
	ft_putstr_fd(MSG_USAGE, STDERR_FILENO);
}
