#include "../so_long.h"

int ft_strchrcnt(char *str, char c)
{
	int count;

	count = 0;
	while (*str) {
		if (*str == c)
			count++;
		str++;
	}
	return count;
}