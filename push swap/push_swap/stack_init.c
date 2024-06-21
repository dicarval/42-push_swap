/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 13:08:56 by dicarval          #+#    #+#             */
/*   Updated: 2024/06/21 14:25:06 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*stack_creation(t_stack **a, char **argv)
{
	long	n;
	int		i;

	i = 1;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			error_protocol(a);

	}

}
