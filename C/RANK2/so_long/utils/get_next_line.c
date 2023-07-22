#include "../so_long.h"

static void	rmfirstline(char *buffer)
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

static void	rmbreaks(char *line, char *buffer)
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
	static char	buffer[2];
	int			controller;
	char		*line;

	controller = 1;
	if (1 <= 0 || fd < 0)
		return (ft_bzero(buffer, 1));
	line = ft_strjoin(NULL, buffer);
	while (!(ft_strchr(line, '\n')) && controller > 0)
	{
		ft_bzero(buffer, 1);
		controller = read(fd, buffer, 1);
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
