/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 10:36:40 by dicarval          #+#    #+#             */
/*   Updated: 2024/07/18 18:47:05 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strcmp(char* instr, char * comparing)
{
	int i;

	i = 0;
	while (instr && comparing)
	{
		if (instr[i] != comparing[i])
			return (0);
		i++;
	}
	return (1);
}
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
	if (*a == NULL || (*a)->next == NULL)
		error_instr(a, b);
	if (*b != NULL)
		return (1);
	while (*a)
	{
		if ((*a)->next == NULL)
			return (0);
		if (*a > (*a)->next)
			return (1);
		*a = (*a)->next;
	}
	return (0);
}


void	sort_instr(char *read_instr, t_stack **a, t_stack **b)
{
	if (ft_strcmp(read_instr, "pa\n"))
		pa(a, b, false);
	else if (ft_strcmp(read_instr, "pb\n"))
		pb(a, b, false);
	else if (ft_strcmp(read_instr, "sa\n"))
		sa(a, false);
	else if (ft_strcmp(read_instr, "sb\n"))
		sb(a, false);
	else if (ft_strcmp(read_instr, "ss\n"))
		ss(a, b, false);
	else if (ft_strcmp(read_instr, "ra\n"))
		ra(a, false);
	else if (ft_strcmp(read_instr, "rb\n"))
		rb(b, false);
	else if (ft_strcmp(read_instr, "rr\n"))
		rr(a, b, false);
	else if (ft_strcmp(read_instr, "rra\n"))
		rra(a, false);
	else if (ft_strcmp(read_instr, "rrb\n"))
		rrb(b, false);
	else if (ft_strcmp(read_instr, "rrr\n"))
		rrr(a, b, false);
	else
		error_instr(a, b);
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
	read_instr = get_next_line(fd);
	while (read_instr)
	{
		sort_instr(read_instr, &a, &b);
		read_instr = get_next_line(fd);
	}
	if (sort_check(&a, &b))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	return (0);
}

