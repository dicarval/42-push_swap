/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:49:31 by dicarval          #+#    #+#             */
/*   Updated: 2024/07/12 17:10:17 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*rotated;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	rotated = *stack;
	last = find_last(*stack);
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	rotated->prev = last;
	rotated->next = NULL;
	last->next = rotated;
}

void	ra(t_stack **a, bool print)
{
	rotate(a);
	if (!print)
		ft_printf("ra\n");
}

void	rb(t_stack **b, bool print)
{
	rotate(b);
	if (!print)
		ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b, bool print)
{
	rotate(a);
	rotate(b);
	if (!print)
		ft_printf("rr\n");
}
