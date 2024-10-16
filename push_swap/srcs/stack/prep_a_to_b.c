/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:19:55 by dicarval          #+#    #+#             */
/*   Updated: 2024/10/16 15:03:01 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

static void	define_push_cost(t_stack *stack, long len)
{
	if (stack->above_median == true)
		stack->push_cost = len - stack->index;
	if (stack->above_median == false)
		stack->push_cost = stack->index;
	return ;
}

t_stack	*find_cheapest(t_stack *a)
{
	long	cheapest;
	t_stack	*cheapest_node;

	cheapest = LONG_MAX;
	while (a)
	{
		if (a->push_cost < cheapest)
		{
			cheapest = a->push_cost;
			cheapest_node = a;
		}
		a = a->next;
	}
	return (cheapest_node);
}

static void	set_cheapest(t_stack *stack)
{
	t_stack	*temp;
	long	len_stk;
	long	len_stk_tn;

	len_stk = stack_len(stack);
	len_stk_tn = stack_len(stack->target_node);
	temp = stack;
	while (temp)
	{
		define_push_cost(temp, len_stk);
		define_push_cost(temp->target_node, len_stk_tn);
		temp->push_cost += temp->target_node->push_cost;
		temp = temp->next;
	}
	return ;
}

static void	set_target_node_a(t_stack *a, t_stack *b)
{
	t_stack	*temp;
	t_stack	*target;
	long	closest_b;

	while (a)
	{
		closest_b = LONG_MIN;
		temp = b;
		while (temp)
		{
			if (a->nbr > temp->nbr
				&& temp->nbr > closest_b)
			{
				closest_b = temp->nbr;
				target = temp;
			}
			temp = temp->next;
		}
		if (closest_b == LONG_MIN)
			a->target_node = find_max(b);
		else
			a->target_node = target;
		a = a->next;
	}
}

void	prep_nodes_a_to_b(t_stack **a, t_stack **b)
{
	updt_index(*a);
	updt_index(*b);
	set_target_node_a(*a, *b);
	set_cheapest(*a);
}
