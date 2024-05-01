/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 21:45:12 by llopes-d          #+#    #+#             */
/*   Updated: 2023/06/18 15:25:06 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	buffer[BUFFER_SIZE + 1];
	int			controller;
	char		*line;

	controller = 1;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (ft_bzero(buffer, BUFFER_SIZE));
	line = ft_strjoin(NULL, buffer);
	while (!(ft_strchr(line, '\n')) && controller > 0)
	{
		ft_bzero(buffer, BUFFER_SIZE);
		controller = read(fd, buffer, BUFFER_SIZE);
		line = ft_strjoin(line, buffer);
	}
	rmbreaks(line, buffer);
	if (!line[0] || controller < 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
