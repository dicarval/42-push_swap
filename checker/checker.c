/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 10:36:40 by dicarval          #+#    #+#             */
/*   Updated: 2024/07/23 14:12:19 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strcmp(char* instr, char *comparing)
{
	int i;

	i = 0;
	while (instr[i] == comparing[i] && instr[i])
		i++;
	return (instr[i] - comparing[i]);
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
	t_stack *temp;

	temp = *a;
	if (*a == NULL || (*a)->next == NULL)
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


void	sort_instr(char *read_instr, t_stack **a, t_stack **b)
{
	if (ft_strcmp(read_instr, "pa\n") == 0)
		pa(a, b, true);
	else if (ft_strcmp(read_instr, "pb\n") == 0)
		pb(a, b, true);
	else if (ft_strcmp(read_instr, "sa\n") == 0)
		sa(a, true);
	else if (ft_strcmp(read_instr, "sb\n") == 0)
		sb(a, true);
	else if (ft_strcmp(read_instr, "ss\n") == 0)
		ss(a, b, true);
	else if (ft_strcmp(read_instr, "ra\n") == 0)
		ra(a, true);
	else if (ft_strcmp(read_instr, "rb\n") == 0)
		rb(b, true);
	else if (ft_strcmp(read_instr, "rr\n") == 0)
		rr(a, b, true);
	else if (ft_strcmp(read_instr, "rra\n") == 0)
		rra(a, true);
	else if (ft_strcmp(read_instr, "rrb\n") == 0)
		rrb(b, true);
	else if (ft_strcmp(read_instr, "rrr\n") == 0)
		rrr(a, b, true);
	else
		error_instr(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*read_instr;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	stack_creation(&a, argv);
	while ((read_instr = get_next_line(0)))
	{
		if (ft_strcmp(read_instr, "\n") == 0)
		{
			free(read_instr);
			break;
		}
		sort_instr(read_instr, &a, &b);
		free(read_instr);
	}
	if (sort_check(&a, &b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&a);
	return (0);
}

