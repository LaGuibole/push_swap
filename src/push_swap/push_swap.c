/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 15:13:32 by guphilip          #+#    #+#             */
/*   Updated: 2025/02/20 17:32:30 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/// @brief Frees a dynamically allocated array of strings
/// @param split The array to free
static void	free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

/// @brief Sorts stack A based on its length
/// @param a Pointer to stack A
/// @param b POinter to stackl B
static void	sort_stack(t_stack_node **a, t_stack_node **b)
{
	if (stack_len(*a) == 2)
		sa(a, true);
	else if (stack_len(*a) == 3)
		sort_three(a);
	else
		sort_stacks(a, b);
}

/// @brief Cleans up allocated memory for the stacks and args
/// @param a Pointer to stack A
/// @param split_argv Array of arguments, possibly allocated dynamically
/// @param argc Number of original arguments
void	cleanup(t_stack_node **a, char **split_argv, int argc)
{
	free_stack(a);
	if (argc == 2)
		free_split(split_argv);
}

/// @brief Check if a number has a valid length to fit within an int
/// @param test The string representing the number
/// @return 1 if the number is too long 0 otherwise
int	check_len(char *test)
{
	int	count;

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

/// @brief Main entry point for the Push_Swap program
/// @param argc Number of arguments
/// @param argv Array of arguments
/// @return Returns 0 on success, 1 if there were not enough arguments
int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**split_argv;

	a = NULL;
	b = NULL;
	argv++;
	if (argc < 2)
	{
		error_message();
		return (1);
	}
	if (argc == 2)
		split_argv = ft_split(argv[0], ' ');
	else
		split_argv = argv;
	init_stack_a(&a, split_argv, argc);
	if (!stack_sorted(a))
		sort_stack(&a, &b);
	cleanup(&a, split_argv, argc);
	return (0);
}
