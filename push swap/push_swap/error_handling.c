/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 13:41:12 by dicarval          #+#    #+#             */
/*   Updated: 2024/06/21 14:44:12 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **a)
{
	t_stack	*temp;
	t_stack	*current;

	if (a != NULL)
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
}

void	error_protocol(t_stack **a)
{
	free_stack(a);
	ft_printf("Error");
	exit(1);
}

int	error_syntax(char *argv)
{
	if (!(*argv == '+' || *argv == '-' || (*argv >= '0' && *argv <= '9')))
		return(1);
	if ((argv[0] == '+' || argv[0] == '-') && !(argv[1] >= '0' && argv[1] <= '9'))
		return(1);
	while (++*argv)
	{
		if (!(*argv >= '0' && *argv <= '9'))
			return(1);
	}
	return (0);
}
