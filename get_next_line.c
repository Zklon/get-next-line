/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubrito- <lubrito-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:41:26 by lubrito-          #+#    #+#             */
/*   Updated: 2024/05/11 19:46:35 by lubrito-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			len;

	line = NULL;
	len = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer[0])
		len = read(fd, buffer, BUFFER_SIZE);
	while (len > 0)
	{
		line = ft_strjoin(line, buffer);
		if (ft_strchr(line, '\n'))
			break ;
		len = read(fd, buffer, BUFFER_SIZE);
	}
	if (len < 0)
	{
		if (line)
			free (line);
		return (NULL);
	}
	return (line);
}
