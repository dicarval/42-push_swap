/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:19:28 by dicarval          #+#    #+#             */
/*   Updated: 2024/07/12 15:23:37 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

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
	t_stack	*temp;

	swap(a);
	if (!print)
		ft_printf("sa\n");
	temp = *a;
	while(temp)
	{
		ft_printf("%i\n", temp->nbr);
		temp = temp->next;
	}
	ft_printf("\n");
}

void	sb(t_stack **b, bool print)
{
	t_stack	*temp;

	swap(b);
	if (!print)
		ft_printf("sb\n");
	temp = *b;
	while(temp)
	{
		ft_printf("%i\n", temp->nbr);
		temp = temp->next;
	}
	ft_printf("\n");
}

void	ss(t_stack **a, t_stack **b, bool print)
{
	t_stack	*temp;

	swap(a);
	swap(b);
	if (!print)
		ft_printf("ss\n");
	temp = *a;
	while(temp)
	{
		ft_printf("%i\n", temp->nbr);
		temp = temp->next;
	}
	temp = *b;
	while(temp)
	{
		ft_printf("%i\n", temp->nbr);
		temp = (temp)->next;
	}
	ft_printf("\n");
}
