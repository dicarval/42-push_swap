/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:27:47 by dicarval          #+#    #+#             */
/*   Updated: 2024/07/01 15:39:03 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_stack *stack)
{
	int	len;

	len = 0;
	while (stack != NULL)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

bool	stack_sorted(t_stack *stack)
{
	if (!stack)
		return (false);
	while (stack->next != NULL)
	{
		if (stack->nbr > stack->next->nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}

t_stack	*find_last(t_stack *a)
{
	if (!a)
		return (NULL);
	while (a->next != NULL)
		a = a->next;
	return (a);
}
t_stack	*find_min(t_stack *a)
{
	t_stack *temp;

	temp->nbr = INT_MIN;
	while (a)
	{
		if (a->nbr > temp->nbr)
			temp = a;
		a = a->next;
	}
	return (temp);
}
