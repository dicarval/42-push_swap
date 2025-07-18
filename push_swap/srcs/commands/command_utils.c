/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 16:29:26 by dicarval          #+#    #+#             */
/*   Updated: 2024/10/18 11:25:05 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

void	prep_for_push(t_stack **stack, t_stack *node, char stack_name)
{
	while (*stack != node)
	{
		if (stack_name == 'a')
		{
			if (node->above_median)
				rra(stack, false);
			else
				ra(stack, false);
		}
		if (stack_name == 'b')
		{
			if (node->above_median)
				rrb(stack, false);
			else
				rb(stack, false);
		}
	}
}

void	updt_index(t_stack *stack)
{
	int	i;
	int	median;

	if (!stack)
		return ;
	i = 0;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i >= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

void	min_on_top(t_stack **a)
{
	t_stack	*min;

	min = find_min(*a);
	while ((*a)->nbr != min->nbr)
	{
		if (min->above_median)
			rra(a, false);
		else
			ra(a, false);
	}
}
