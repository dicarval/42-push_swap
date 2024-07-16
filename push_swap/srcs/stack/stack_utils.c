/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:27:47 by dicarval          #+#    #+#             */
/*   Updated: 2024/07/16 15:53:08 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

t_stack	*find_max(t_stack *stack)
{
	t_stack	*temp;
	long	max;

	if (!stack)
		return (NULL);
	max = LONG_MIN;
	while (stack)
	{
		if (stack->nbr > max)
		{
			max = stack->nbr;
			temp = stack;
		}
		stack = stack->next;
	}
	return (temp);
}

t_stack	*find_min(t_stack *stack)
{
	t_stack	*temp;
	long	min;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->nbr < min)
		{
			min = stack->nbr;
			temp = stack;
		}
		stack = stack->next;
	}
	return (temp);
}

long	stack_len(t_stack *stack)
{
	long	len;

	len = 0;
	while (stack->prev != NULL)
		stack = stack->prev;
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
