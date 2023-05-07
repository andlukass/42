#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	index;

	index = 0;
	while ((s[index] != '\0'))
		index++;
	return (index);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*newstr;
	int		index;
	int		length;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	newstr = (char *) malloc(((ft_strlen(s1) + ft_strlen(s2)) + 1)
			* sizeof(char));
	if (newstr == NULL)
		return (NULL);
	index = 0;
	length = -1;
	while (s1[++length])
		newstr[length] = s1[length];
	while (s2[index])
	{
		newstr[length] = s2[index];
		index++;
		length++;
	}
	newstr[length] = '\0';
	free(s1);
	return (newstr);
}

char	*get_file(int fd, char *file)
{
	int	bytes;
	char	*buff;

	bytes = 1;
	buff = malloc(sizeof(char) * BUFFER_SIZE);
	while (bytes > 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		buff[bytes] = '\0';
		file = ft_strjoin(file, buff);
	}
	free(buff);
	return (file);
}

char	*make_line(char *file)
{
	char *line;
	int index;

	index = 0;
	if (!file[index])
		return (NULL);
	while (file[index] && file[index] != '\n')
		index++;
	if (index == 0)
		return (NULL);
	line = malloc(sizeof(char) * (index + 2));
	if (!line)
		return (NULL);
	index = 0;
	while (file[index] && file[index] != '\n')
	{	
		line[index] = file[index];
		index++;
	}
	line[index] = '\n';
	index++;
	line[index] = '\0';
	return (line);
}

char	*rm_line(char *file)
{
	int index = 0;
	int start;
	int length = 0;
	char *new_file;

	while (file[index] && file[index]  != '\n')
		index++;
	if (file[index] == '\n')
		index++;
	start = index;
	while (file[index])
	{	
		index++;
		length++;
	}
	new_file = malloc(sizeof(char) * (length + 1));
	index = 0;
	while (file[start])
	{
		new_file[index] = file[start];
		index++;
		start++;
	}
	new_file[index] = '\0';
	return (new_file);
}

char	*get_next_line(int fd)
{	
	static char	file[BUFFER_SIZE + 1];
	char	*line;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 99)
		return (NULL);
	if (!file)
		file = get_file(fd, file);
	line = make_line(file);
	if (!line)
		return (NULL);
	file = rm_line(file);
	return (line);
}
