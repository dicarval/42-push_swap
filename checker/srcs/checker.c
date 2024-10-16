/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 10:36:40 by dicarval          #+#    #+#             */
/*   Updated: 2024/10/15 17:34:01 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/checker.h"

void	error_instr(t_stack **a, t_stack **b)
{
	if (b)
		free_stack(b);
	if (a)
		free_stack(a);
	write (2, "Error\n", 6);
	exit(1);
}

int	sort_check(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	temp = *a;
	if (*a == NULL)
		error_instr(a, b);
	if (*b != NULL)
		return (1);
	while (temp)
	{
		if ((temp)->next == NULL)
			return (0);
		if ((temp)->nbr > (temp)->next->nbr)
			return (1);
		temp = (temp)->next;
	}
	return (0);
}

void	read_instr(t_stack **a, t_stack **b)
{
	char	*read_instr;

	read_instr = get_next_line(0);
	while (read_instr)
	{
		if (sort_instr(read_instr, a, b) == 1)
		{
			free(read_instr);
			error_instr(a, b);
		}
		free(read_instr);
		read_instr = get_next_line(0);
	}
	free(read_instr);
	if (sort_check(a, b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(a);
	return ;
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (1);
	stack_creation(&a, argv);
	read_instr(&a, &b);
	return (0);
}
