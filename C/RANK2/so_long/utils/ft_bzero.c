#include "../so_long.h"

void	*ft_bzero(char *s, size_t n)
{
	size_t	index;

	if (!s[0])
		return (NULL);
	index = 0;
	while (index < n)
		s[index++] = '\0';
	return (NULL);
}