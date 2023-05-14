#include "get_next_line.h"

int	ft_strchr(const char *s, int c)
{
	int	index;

	index = 0;
	while (s[index])
	{
		if ((char)c == s[index])
			return (index);
		index++;
	}
	if ((char)c == s[index])
		return (index);
	else
		return (0);
}

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

void	ft_bzero(void *s, size_t n)
{
	size_t	index;

	index = 0;
	while (index < n)
	{
		((unsigned char *)s)[index] = 0;
		index++;
	}
}

char	*ft_strjoin2(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;
	size_t	j;
	char	*result;

	if (!s1 || !s2)
		return (NULL);

	len_s1 = 0;
	while (s1[len_s1])
		len_s1++;

	len_s2 = 0;
	while (s2[len_s2])
		len_s2++;

	result = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!result)
		return (NULL);

	i = 0;
	while (i < len_s1)
	{
		result[i] = s1[i];
		i++;
	}

	j = 0;
	while (j < len_s2)
	{
		result[i] = s2[j];
		i++;
		j++;
	}

	result[i] = '\0';

	return (result);
}

char	*get_next_line(int fd)
{	
	static char	buffer[BUFFER_SIZE + 1];
	char *temp;
	char *line;

	line = NULL;
	temp = NULL;
	temp = ft_strjoin(temp, buffer + (ft_strchr(buffer, '\n') + 1));
	if (read(fd, 0, 0) < 0)
		return (NULL);
	while (read(fd, buffer, BUFFER_SIZE))
	{
		//junta o que foi lido com o que ja lido na ultima iteracao
		line = ft_strjoin(line, buffer);
		if (ft_strchr(line, '\n'))
			break;
	}
	line = ft_strjoin(line, buffer);
	printf("\n buffer: %s || \n", buffer);
	//printf("\n temp: %s || \n", temp);
	//JUNTAR TEMP E LINE
	if (temp)
	{
		char *temp_line = ft_strjoin(temp, line);
		free(line);
		line = temp_line;
	}
	// caso a ultima linha ja tenha ido anteriormente ou for vazio
	if (!line)
	{	
		free(line);
		return (NULL);
	}
	//printf("\n linha antes b0: %s || \n", line);
	//remove tudo que tenha depois de algum \n
	ft_bzero(&line[ft_strchr(line, '\n')+1], ft_strlen(line) - ft_strchr(line, '\n'));
	//free(temp);
	return line;
}
