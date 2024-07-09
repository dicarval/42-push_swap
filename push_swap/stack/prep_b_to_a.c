/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 11:19:02 by dicarval          #+#    #+#             */
/*   Updated: 2024/07/09 11:46:55 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	set_target_node_b(t_stack *b, t_stack *a)
{
	t_stack	*temp;
	t_stack	*target;
	long	closest_a;

	while (b)
	{
		closest_a = LONG_MAX;
		temp = a;
		while (temp)
		{
			if (b->nbr < temp->nbr
				&& temp->nbr < closest_a)
			{
				closest_a = temp->nbr;
				target = temp;
			}
			temp = temp->next;
		}
		if (closest_a == LONG_MAX)
			b->target_node = find_min(a);
		else
			b->target_node = target;
		b = b->next;
	}
}
void prep_nodes_b_to_a(t_stack **b, t_stack **a)
{
	updt_index(*b);
	updt_index(*a);
	set_target_node_b(*b, *a);
}
