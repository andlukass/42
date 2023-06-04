#include "get_next_line.h"

int move_buffer(char *buffer)
{
	int index = 0;
	int start = 0;
	int size;
	while (buffer[index])
	{
		if (buffer[index] == '\n')
		{
			size = index;
			index++;
			break ;
		}
		index++;
	}
	while (buffer[index])
	{
		buffer[start++] = buffer[index++];
	}
	ft_bzero(buffer + start, ft_strlen(buffer));
	return (size);
}

int get_buffer_size(char *buffer)
{
	int	index;

	index = 0;
	while ((buffer[index] != '\0') && (buffer[index] != '\n'))
		index++;
	return (index);
}

char *getn(char *line, char *buffer)
{
	int size;
	int index = 0;

	size = get_buffer_size(buffer);
	//printf("start: %d\n", size);
	line = malloc((sizeof(char) * size) + 1);
	while (index < size)
	{	
		line[index] = buffer[index];
		index++;
	}
	line[index] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{	
	static char	buffer[BUFFER_SIZE + 1];
	char *line;
	char *temp;
	
	if (*buffer)
	{	
		temp = buffer;
	printf("\n temp: %s\n", temp);
	}
	while (1)
	{
		read(fd, buffer, BUFFER_SIZE);
		if (ft_strchr(buffer,'\n') || ft_strchr(buffer,'\0'))
		{	
			printf("\n brekou\n");
			break;
		}
	}
	printf("\n BUFFER: %s\n", buffer);
	line = getn(line, buffer);
	move_buffer(buffer);

	return (line);
}
