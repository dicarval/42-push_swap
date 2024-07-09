/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 16:29:26 by dicarval          #+#    #+#             */
/*   Updated: 2024/07/09 13:34:29 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	prep_for_push(t_stack **stack, t_stack *move_to_top, char stack_name)
{
	while (*stack != move_to_top)
	{
		if (stack_name = 'a')
		{
			if (move_to_top->above_median)
				rra(stack, false);
			else
				ra(stack, false);
		}
		if (stack_name = 'b')
		{
			if (move_to_top->above_median)
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
	median = stack_len(stack)/2;
	while (stack)
	{
		stack->index = i;
		if (i > median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}

}

void	min_on_top(t_stack **a)
{
	while ((*a)->nbr != find_min(*a)->nbr)
	{
		if (find_min(*a)->above_median)
			rra(a, false);
		else
			ra(a, false);
	}
}
