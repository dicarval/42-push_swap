/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:43:23 by dicarval          #+#    #+#             */
/*   Updated: 2024/10/18 10:26:54 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

static void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*a != cheapest_node && *b != cheapest_node->target_node)
		rr(a, b, false);
	updt_index(*a);
	updt_index(*b);
}

static void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*a != cheapest_node && *b != cheapest_node->target_node)
		rrr(a, b, false);
	updt_index(*a);
	updt_index(*b);
}

static void	move_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = find_cheapest(*a);
	if (cheapest_node->above_median
		&& cheapest_node->target_node->above_median)
		rev_rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		rotate_both(a, b, cheapest_node);
	prep_for_push(a, cheapest_node, 'a');
	prep_for_push(b, cheapest_node->target_node, 'b');
	pb(a, b, false);
}

static void	move_b_to_a(t_stack **b, t_stack **a)
{
	prep_for_push(a, (*b)->target_node, 'a');
	pa(a, b, false);
}

void	sort_stacks(t_stack **a, t_stack **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(a, b, false);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(a, b, false);
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		prep_nodes_a_to_b(a, b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		prep_nodes_b_to_a(b, a);
		move_b_to_a(b, a);
	}
	updt_index(*a);
	min_on_top(a);
}
