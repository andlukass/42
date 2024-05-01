/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 21:45:12 by llopes-d          #+#    #+#             */
/*   Updated: 2023/06/18 15:07:15 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	rmfirstline(char *buffer)
{
	int	index;
	int	start;

	index = 0;
	start = 0;
	while (buffer[index] && buffer[index] != '\n')
		index++;
	while (buffer[index] && buffer[++index])
		buffer[start++] = buffer[index];
	while (buffer[start])
		buffer[start++] = '\0';
}

void	rmbreaks(char *line, char *buffer)
{
	int	index;

	index = 0;
	while (line[index] && line[index] != '\n')
		index++;
	while (line[index] && line[++index])
		line[index] = '\0';
	rmfirstline(buffer);
}

char	*get_next_line(int fd)
{	
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	int			controller;
	char		*line;

	controller = 1;
	if (BUFFER_SIZE <= 0 || fd < 0 || fd >= FOPEN_MAX)
	{
		if (fd < FOPEN_MAX && fd >= 0)
			ft_bzero(buffer[fd], BUFFER_SIZE);
		return (NULL);
	}
	line = ft_strjoin(NULL, buffer[fd]);
	while (!(ft_strchr(line, '\n')) && controller > 0)
	{
		ft_bzero(buffer[fd], BUFFER_SIZE);
		controller = read(fd, buffer[fd], BUFFER_SIZE);
		line = ft_strjoin(line, buffer[fd]);
	}
	rmbreaks(line, buffer[fd]);
	if (!line || !line[0] || controller < 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
