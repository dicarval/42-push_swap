/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:27:47 by dicarval          #+#    #+#             */
/*   Updated: 2024/06/24 16:43:55 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_last(t_stack *a)
{
	if (!a)
		return (NULL);
	while (a->next != NULL)
	{
		a = a->next;
	}
	return (a);
}
