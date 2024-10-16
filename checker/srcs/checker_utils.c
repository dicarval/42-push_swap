/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:09:56 by dicarval          #+#    #+#             */
/*   Updated: 2024/10/15 17:35:16 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/checker.h"

int	ft_strcmp(char *instr, char *comparing)
{
	int	i;

	i = 0;
	while (instr[i] == comparing[i] && instr[i])
		i++;
	return (instr[i] - comparing[i]);
}

int	sort_instr(char *read_instr, t_stack **a, t_stack **b)
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
		return (1);
	return (0);
}
