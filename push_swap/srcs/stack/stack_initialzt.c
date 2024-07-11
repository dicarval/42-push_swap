/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_initialzt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 13:08:56 by dicarval          #+#    #+#             */
/*   Updated: 2024/07/11 16:04:54 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

static void	append_node(t_stack **a, int n)
{
	t_stack	*new_node;
	t_stack	*last_node;

	if (!a)
		return ;
	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->nbr = n;
	if (*a == NULL)
	{
		*a = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last_node = find_last(*a);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}

static long	atol(const char *argv)
{
	long	result;
	int		sign;

	while (*argv == ' ' || *argv == '\t' || *argv == '\n'
		|| *argv == '\r' || *argv == '\f' || *argv == '\v')
		*argv++;
	sign = 1;
	if (*argv == '-' || *argv == '+')
	{
		if (*argv == '-')
			sign = -1;
		*argv++;
	}
	result = 0;
	while (*argv != '\0')
	{
		result = (result * 10) + (*argv - '0');
		*argv++;
	}
	return (result * sign);
}

void	*stack_creation(t_stack **a, char **argv)
{
	long	n;
	int		i;

	i = 1;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			error_protocol(a);
		n = atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			error_protocol(a);
		if (error_duplicate(*a, (int)n))
			error_protocol(a);
		append_node(a, (int)n);
		i++;
	}
}
