/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 10:23:51 by dicarval          #+#    #+#             */
/*   Updated: 2024/10/14 11:33:44 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlenn(char *c)
{
	int	i;

	i = 0;
	if (c)
	{
		while (c[i])
			i++;
	}
	return (i);
}

char	*ft_strjoinn(char *s1, char *s2)
{
	int		lens1;
	int		lens2;
	int		i;
	int		j;
	char	*str;

	lens1 = ft_strlenn(s1);
	lens2 = ft_strlenn(s2);
	str = (char *)malloc(lens1 + lens2 + 1);
	if (str == NULL)
		return (NULL);
	i = -1;
	j = -1;
	while (i++ < (lens1 -1))
		str[i] = s1[i];
	while (j++ < (lens2 - 1))
	{
		str[i] = s2[j];
		i++;
	}
	str[i] = '\0';
	if (s1)
		free (s1);
	return (str);
}

int	ft_newline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void	*ft_cleanread(char *line, char *buffer)
{
	size_t	i;
	int		flag;

	i = 0;
	flag = ft_newline(line);
	if (flag != -1)
	{
		line [flag + 1] = '\0';
		flag = ft_newline (buffer);
		flag++;
		while (buffer[flag])
			buffer[i++] = buffer[flag++];
	}
	while (i < BUFFER_SIZE)
		buffer[i++] = '\0';
	return (line);
}
