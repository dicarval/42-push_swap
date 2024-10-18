/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 11:19:02 by dicarval          #+#    #+#             */
/*   Updated: 2024/10/18 10:15:20 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

static void	set_target_node_b(t_stack *b, t_stack *a)
{
	t_stack	*temp_a;
	t_stack	*target;
	long	closest_a;

	while (b)
	{
		closest_a = LONG_MAX;
		temp_a = a;
		while (temp_a)
		{
			if (b->nbr < temp_a->nbr
				&& temp_a->nbr < closest_a)
			{
				closest_a = temp_a->nbr;
				target = temp_a;
			}
			temp_a = temp_a->next;
		}
		if (closest_a == LONG_MAX)
			b->target_node = find_min(a);
		else
			b->target_node = target;
		b = b->next;
	}
}

void	prep_nodes_b_to_a(t_stack **b, t_stack **a)
{
	updt_index(*b);
	updt_index(*a);
	set_target_node_b(*b, *a);
}
