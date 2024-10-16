/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 10:31:14 by dicarval          #+#    #+#             */
/*   Updated: 2024/10/15 17:32:46 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# define BUFFER_SIZE 4

# include "../../push_swap/header/push_swap.h"
# include "../gnl/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>

void	error_instr(t_stack **a, t_stack **b);

int		ft_strcmp(char *instr, char *comparing);
int		sort_instr(char *read_instr, t_stack **a, t_stack **b);

#endif
