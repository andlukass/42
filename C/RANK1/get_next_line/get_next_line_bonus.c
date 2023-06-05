/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 21:45:12 by llopes-d          #+#    #+#             */
/*   Updated: 2023/06/05 20:31:46 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	rmfirstine(char *buffer)
{
	int	index;
	int	flag;
	int	start;

	index = 0;
	flag = 0;
	start = 0;
	while (buffer[index])
	{
		if (buffer[index] == '\n' && !flag++)
			index++;
		if (flag)
			buffer[start++] = buffer[index];
		index++;
	}
	while (buffer[start])
		buffer[start++] = '\0';
}

void	rmbreaks(char *line, char *buffer)
{
	int	index;
	int	flag;
	int	iflag;

	index = 0;
	flag = 0;
	iflag = 0;
	if (!ft_strchr(line, '\n'))
		return ;
	while (line[index])
	{
		if (line[index] == '\n' && !flag)
		{	
			flag++;
			iflag++;
			index++;
		}
		if (flag)
			line[index] = '\0';
		if (iflag)
			iflag = 0;
		else
			index++;
	}
	rmfirstine(buffer);
}

char	*get_next_line(int fd)
{	
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	int			controller;
	char		*line;

	controller = 1;
	if (BUFFER_SIZE <= 0 || (read(fd, 0, 0) < 0) || fd >= FOPEN_MAX)
	{
		if (fd <= FOPEN_MAX && fd > 0)
			ft_bzero(buffer[fd], BUFFER_SIZE);
		return (NULL);
	}
	line = ft_strjoin(NULL, buffer[fd]);
	while (!(ft_strchr(line, '\n')) && controller)
	{
		ft_bzero(buffer[fd], BUFFER_SIZE);
		controller = read(fd, buffer[fd], BUFFER_SIZE);
		line = ft_strjoin(line, buffer[fd]);
	}
	rmbreaks(line, buffer[fd]);
	if (!line || !line[0])
	{
		free(line);
		return (NULL);
	}
	return (line);
}
