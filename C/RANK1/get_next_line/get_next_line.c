/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 21:45:12 by llopes-d          #+#    #+#             */
/*   Updated: 2023/06/17 19:20:27 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	rmfirstline(char *buffer)
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
	rmfirstline(buffer);
}

char	*get_next_line(int fd)
{	
	static char	buffer[BUFFER_SIZE + 1];
	int			controller;
	char		*line;

	controller = 1;
	if (BUFFER_SIZE <= 0 || (read(fd, 0, 0) < 0))
		return (ft_bzero(buffer, BUFFER_SIZE));
	line = ft_strjoin(NULL, buffer);
	while (!(ft_strchr(line, '\n')) && controller)
	{
		ft_bzero(buffer, BUFFER_SIZE);
		controller = read(fd, buffer, BUFFER_SIZE);
		line = ft_strjoin(line, buffer);
	}
	rmbreaks(line, buffer);
	if (!line || !line[0])
	{
		free(line);
		return (NULL);
	}
	return (line);
}
