/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:36:06 by llopes-d          #+#    #+#             */
/*   Updated: 2023/04/06 17:36:10 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

static int	check_char(char c, char const *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (str[index] == c)
			return (1);
		index++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*newstr;
	int		index;
	int		start;
	int		end;

	start = 0;
	end = 0;
	while (s1[start] && check_char(s1[start], set))
		start++;
	while (s1[end])
		end++;
	while (end > start && check_char(s1[end - 1], set))
		end--;
	newstr = (char *)malloc(sizeof(char) * (end - start + 1));
	if (newstr == NULL)
		return (NULL);
	index = 0;
	while (start < end)
		newstr[index++] = s1[start++];
	newstr[index] = '\0';
	return (newstr);
}

/*int main(void)
{
    char *s1 = "eeebe  hello world eeeeeeb";
    char *set = "eb";
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
}*/
