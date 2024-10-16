/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 10:23:48 by dicarval          #+#    #+#             */
/*   Updated: 2024/10/14 11:32:31 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer [BUFFER_SIZE + 1];
	char		*line;
	int			bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	while (ft_newline(line) == -1)
	{
		if (buffer[0] == '\0')
		{
			bytes = read(fd, buffer, BUFFER_SIZE);
			if (bytes <= 0)
			{
				if (bytes == 0)
					return (line);
				free(line);
				return (NULL);
			}
			buffer[bytes] = '\0';
		}
		line = ft_strjoinn(line, buffer);
		ft_cleanread(line, buffer);
	}
	return (line);
}
