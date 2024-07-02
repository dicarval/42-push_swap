/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:19:55 by dicarval          #+#    #+#             */
/*   Updated: 2024/07/02 17:54:13 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	find_push_cost(t_stack *a, t_stack *b)
{
	while (a)
	{

	}
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
	find_push_cost(*a, *b);
	set_cheapest(*a, *b);

}
