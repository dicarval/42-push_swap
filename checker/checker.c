/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 10:36:40 by dicarval          #+#    #+#             */
/*   Updated: 2024/07/17 15:21:57 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
	if (*a == NULL || (*a)->next == NULL || *b != NULL)
		error_instr(a, b);
	while (*a)
	{
		if ((*a)->next == NULL)
			return (0);
		if (*a > (*a)->next)
			return (1);
		*a = (*a)->next;
	}
}

void	sort_instr(char *read_instr, t_stack **a, t_stack **b)
{
	if (read_instr = "pa\n")
		pa(a, b, false);
	else if (read_instr = "pb\n")
		pb(a, b, false);
	else if (read_instr = "sa\n")
		sa(a, false);
	else if (read_instr = "sb\n")
		sb(a, false);
	else if (read_instr = "ss\n")
		ss(a, b, false);
	else if (read_instr = "ra\n")
		ra(a, false);
	else if (read_instr = "rb\n")
		rb(b, false);
	else if (read_instr = "rr\n")
		rr(a, b, false);
	else if (read_instr = "rra\n")
		rra(a, false);
	else if (read_instr = "rrb\n")
		rrb(b, false);
	else if (read_instr = "rrr\n")
		rrr(a, b, false);
	else
		error_instr(a, b);
	free(read_instr);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*read_instr;
	int		fd;

	if (argc <= 2)
		return (0);
	stack_creation(&a, argv);
	fd = 0;
	while ((read_instr = get_next_line(fd)))
	{
		sort_instr(read_instr, &a, &b);
	}
	if (sort_check(&a, &b))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	return (0);
}

