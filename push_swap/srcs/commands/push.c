/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:13:57 by dicarval          #+#    #+#             */
/*   Updated: 2024/07/11 16:04:17 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

static void	push(t_stack **receiver, t_stack **sender)
{
	t_stack	*push_node;

	if (!*sender)
		return ;
	push_node = *sender;
	*sender = (*sender)->next;
	if (*sender)
		(*sender)->prev = NULL;
	if (!*receiver)
	{
		*receiver = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *receiver;
		(*receiver)->prev = push_node;
		*receiver = push_node;
	}
}

void	pa(t_stack **a, t_stack **b, bool print)
{
	push(a, b);
	if (!print)
		printf("pa\n");
}

void	pb(t_stack **a, t_stack **b, bool print)
{
	push(b, a);
	if (!print)
		printf("pa\n");
}
