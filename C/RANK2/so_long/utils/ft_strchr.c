#include "../so_long.h"

int	ft_strchr(const char *s, int c)
{
	int	index;

	index = 0;
	if (!s[0])
		return (0);
	while (s[index])
	{
		if ((char)c == s[index])
			return (1);
		index++;
	}
	if ((char)c == s[index])
		return (1);
	else
		return (0);
}