/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:13:57 by dicarval          #+#    #+#             */
/*   Updated: 2024/07/12 15:20:44 by dicarval         ###   ########.fr       */
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
	t_stack	*temp;

	push(a, b);
	if (!print)
		ft_printf("pa\n");
	temp = *a;
	while(temp)
	{
		ft_printf("%i\n", temp->nbr);
		temp = temp->next;
	}
	ft_printf("\n");
	temp = *b;
	while(temp)
	{
		ft_printf("%i\n", temp->nbr);
		temp = temp->next;
	}
	ft_printf("\n");
}

void	pb(t_stack **a, t_stack **b, bool print)
{
	t_stack	*temp;

	push(b, a);
	if (!print)
		ft_printf("pb\n");
	temp = *a;
	while(temp)
	{
		ft_printf("%i\n", temp->nbr);
		temp = temp->next;
	}
	ft_printf("\n");
	temp = *b;
	while(temp)
	{
		ft_printf("%i\n", temp->nbr);
		temp = temp->next;
	}
	ft_printf("\n");
}
