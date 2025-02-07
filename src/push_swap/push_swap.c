/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 15:13:32 by guphilip          #+#    #+#             */
/*   Updated: 2025/01/28 17:44:41 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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

// static char	**parse_arguments(int argc, char **argv)
// {
// 	if (argc == 1 || (argc == 2 && !argv[1][0]))
// 		return (NULL);
// 	if (argc == 2)
// 		return (ft_split(argv[1], ' '));
// 	return (argv);
// }

static void	sort_stack(t_stack_node **a, t_stack_node **b)
{
	if (stack_len(*a) == 2)
		sa(a, true);
	else if (stack_len(*a) == 3)
		sort_three(a);
	else
		sort_stacks(a, b);
}

static void	cleanup(t_stack_node **a, char **split_argv, int argc)
{
	free_stack(a);
	if (argc == 2)
		free_split(split_argv);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**split_argv;

	a = NULL;
	b = NULL;
	argv++;
	if (argc < 2)
		return (1);
	if (argc == 2)
		split_argv = ft_split(argv[0], ' ');
	else
		split_argv = argv;
	init_stack_a(&a, split_argv);
	if (!stack_sorted(a))
		sort_stack(&a, &b);
	cleanup(&a, split_argv, argc);
	return (0);
}

// int	main(int argc, char **argv)
// {
// 	t_stack_node	*a;
// 	t_stack_node	*b;
// 	char			**split_argv;

// 	a = NULL;
// 	b = NULL;
// 	split_argv = NULL;
// 	if (argc == 1 || (argc == 2 && !argv[1][0]))
// 		return (1);
// 	else if (argc == 2)
// 	{
// 		split_argv = ft_split(argv[1], ' ');
// 		argv = split_argv;
// 	}
// 	init_stack_a(&a, argv + 1);
// 	if (!stack_sorted(a))
// 	{
// 		if (stack_len(a) == 2)
// 			sa(&a, true);
// 		else if (stack_len(a) == 3)
// 			sort_three(&a);
// 		else
// 			sort_stacks(&a, &b);
// 	}
// 	free_stack(&a);
// 	if (split_argv)
// 		free_split(split_argv);
// 	return (0);
// }
