#include "../so_long.h"

int	ft_strlen(const char *s)
{
	int	index;

	index = 0;
	while ((s[index] != '\0'))
		index++;
	return (index);
}