/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:33:54 by dicarval          #+#    #+#             */
/*   Updated: 2024/07/16 15:44:43 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <unistd.h>
# include "../ft_printf/ft_printf.h"

typedef struct s_stack
{
	long			nbr;
	long			index;
	long			push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target_node;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

//***Error handling
int		error_syntax(char *argv);
int		error_duplicate(t_stack *a, int n);
void	error_protocol(t_stack **a);
void	free_stack(t_stack **a);

//***Stack initialization
void	stack_creation(t_stack **a, char **argv);

//***Stack utils
t_stack	*find_last(t_stack *a);
bool	stack_sorted(t_stack *stack);
long	stack_len(t_stack *stack);
t_stack	*find_min(t_stack *stack);
t_stack	*find_max(t_stack *stack);

//***Nodes preparation to push
void	prep_nodes_a_to_b(t_stack **a, t_stack **b);
void	prep_nodes_b_to_a(t_stack **b, t_stack **a);
t_stack	*find_cheapest(t_stack *a);

//***Stack sorting
void	sort_stacks(t_stack **a, t_stack **b);
void	sort_three(t_stack **a);

//***Commands
void	pa(t_stack **a, t_stack **b, bool print);
void	pb(t_stack **a, t_stack **b, bool print);
void	sa(t_stack **a, bool print);
void	sb(t_stack **b, bool print);
void	ss(t_stack **a, t_stack **b, bool print);
void	ra(t_stack **a, bool print);
void	rb(t_stack **b, bool print);
void	rr(t_stack **a, t_stack **b, bool print);
void	rra(t_stack **a, bool print);
void	rrb(t_stack **b, bool print);
void	rrr(t_stack **a, t_stack **b, bool print);

//***Commands utils
void	prep_for_push(t_stack **stack, t_stack *top_node, char stack_name);
void	updt_index(t_stack *stack);
void	min_on_top(t_stack **a);

#endif
