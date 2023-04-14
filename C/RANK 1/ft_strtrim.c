
#include "libft.h"

#include <stdio.h>

static int
	ft_char_in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char
	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	start;
	size_t	end;

	start = 0;
	while (s1[start] && ft_char_in_set(s1[start], set))
		start++;
	end = 0;
    while (s1[end])
        end++;
	while (end > start && ft_char_in_set(s1[end - 1], set))
		end--;
	str = (char*)malloc(sizeof(*s1) * (end - start + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (start < end)
		str[i++] = s1[start++];
	str[i] = 0;
	return (str);
}

int main(void)
{
    char *s1 = "    hello world   ";
    char *set = " ";
    char *trimmed = ft_strtrim(s1, set);
    if (trimmed)
    {
        printf("Original string: \"%s\"\n", s1);
        printf("Trimmed string: \"%s\"\n", trimmed);
        free(trimmed);
    }
    else
    {
        printf("Failed to allocate memory for trimmed string.\n");
    }
    return 0;
}
