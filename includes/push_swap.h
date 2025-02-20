/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 12:02:04 by guphilip          #+#    #+#             */
/*   Updated: 2025/02/20 17:37:38 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include <stdio.h>
# include "libft.h"

# define MSG_USAGE "Error :\nUsage : ./push_swap <args>\n \
		Or\n\
	./push_swap \"args\" \n"

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

typedef void	(*t_rotator)(t_stack_node **a, t_stack_node **b, bool print);

// Errors

int				syntax_error(char *str_n);
int				duplicate_error(t_stack_node *a, int n);
void			free_stack(t_stack_node **stack);
void			free_errors(t_stack_node **a, char **argv, int argc);
void			cleanup(t_stack_node **a, char **split_argv, int argc);
int				check_len(char *test);
void			error_message(void);

// Stack Init

void			init_stack_a(t_stack_node **a, char **argv, int argc);

// Nodes Init

void			init_nodes_a(t_stack_node *a, t_stack_node *b);
void			init_nodes_b(t_stack_node *a, t_stack_node *b);
void			current_index(t_stack_node *stack);
void			set_cheapest(t_stack_node *stack);
t_stack_node	*get_cheapest(t_stack_node *stack);
void			push_prep(
					t_stack_node **stack,
					t_stack_node *top_node,
					char stack_name
					);

// Stack Utils

int				stack_len(t_stack_node *stack);
t_stack_node	*find_last(t_stack_node *stack);
bool			stack_sorted(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);

// Commands
// Push
void			pa(t_stack_node **a, t_stack_node **b, bool print);
void			pb(t_stack_node **b, t_stack_node **a, bool print);
// Reverse Rotate
void			rra(t_stack_node **a, bool print);
void			rrb(t_stack_node **b, bool print);
void			rrr(t_stack_node **a, t_stack_node **b, bool print);
// Rotate
void			ra(t_stack_node **a, bool print);
void			rb(t_stack_node **b, bool print);
void			rr(t_stack_node **a, t_stack_node **b, bool print);
// Swap
void			sa(t_stack_node **a, bool print);
void			sb(t_stack_node **b, bool print);
void			ss(t_stack_node **a, t_stack_node **b, bool print);

// Algo Turk
void			sort_stacks(t_stack_node **a, t_stack_node **b);
void			sort_three(t_stack_node **a);

#endif
