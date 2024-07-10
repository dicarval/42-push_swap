/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:19:28 by dicarval          #+#    #+#             */
/*   Updated: 2024/07/10 17:15:58 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!*stack || !(*stack)->next)
		return ;
	first = (*stack)->next;
	second = *stack;
	second->next = first->next;
	if (first->next)
		first->next->prev = second;
	second->prev = first;
	first->next = second;
	first->prev = NULL;
	*stack = first;
}

void	sa(t_stack **a, bool print)
{
	swap(a);
	if (!print)
		printf("sa\n");
}

void	sb(t_stack **b, bool print)
{
	swap(b);
	if (!print)
		printf("sb\n");
}

void	ss(t_stack **a ,t_stack **b, bool print)
{
	swap(a);
	swap(b);
	if (!print)
		printf("ss\n");
}
