/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 13:41:12 by dicarval          #+#    #+#             */
/*   Updated: 2024/07/16 10:54:24 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

void	free_stack(t_stack **a)
{
	t_stack	*temp;
	t_stack	*current;

	if (a == NULL)
		return ;
	current = *a;
	while (current != NULL)
	{
		current->nbr = 0;
		temp = current;
		current = current->next;
		free(temp);
	}
	*a = NULL;
	return ;
}

void	error_protocol(t_stack **a)
{
	free_stack(a);
	write (2, "Error\n", 6);
	exit(1);
}

int	error_duplicate(t_stack *a, int n)
{
	if (!a)
		return (0);
	while (a != NULL)
	{
		if (a->nbr == n)
			return (1);
		a = a->next;
	}
	return (0);
}

int	error_syntax(char *argv)
{
	int	i;

	i = 0;
	if (!(argv[i] == '+' || argv[i] == '-'
			|| (argv[i] >= '0' && argv[i] <= '9')))
		return (1);
	if ((argv[0] == '+' || argv[0] == '-')
		&& !(argv[1] >= '0' && argv[1] <= '9'))
		return (1);
	i++;
	while (argv[i])
	{
		if (!(argv[i] >= '0' && argv[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}
