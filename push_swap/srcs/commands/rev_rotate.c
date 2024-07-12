/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:30:09 by dicarval          #+#    #+#             */
/*   Updated: 2024/07/12 15:21:01 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

static void	rev_rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*rotated;

	if (!*stack || !(*stack)->next)
		return ;
	rotated = find_last(*stack);
	temp = *stack;
	rotated->prev->next = NULL;
	rotated->next = temp;
	rotated->prev = NULL;
	temp->prev = rotated;
	*stack = rotated;
}

void	rra(t_stack **a, bool print)
{
	t_stack	*temp;

	rev_rotate(a);
	if (!print)
		ft_printf("rra\n");
	temp = *a;
	while(temp)
	{
		ft_printf("%i\n", temp->nbr);
		temp = temp->next;
	}
	ft_printf("\n");
}

void	rrb(t_stack **b, bool print)
{
	t_stack	*temp;

	rev_rotate(b);
	if (!print)
		ft_printf("rrb\n");
	temp = *b;
	while(temp)
	{
		ft_printf("%i\n", temp->nbr);
		temp = temp->next;
	}
	ft_printf("\n");
}

void	rrr(t_stack **a, t_stack **b, bool print)
{
	t_stack	*temp;

	rev_rotate(a);
	rev_rotate(b);
	if (!print)
		ft_printf("rrr\n");
	temp = *a;
	while(temp)
	{
		ft_printf("%i\n", temp->nbr);
		temp = temp->next;
	}
	temp = *b;
	ft_printf("\n");
	while(temp)
	{
		ft_printf("%i\n", temp->nbr);
		temp = temp->next;
	}
	ft_printf("\n");
}
