/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:36:06 by llopes-d          #+#    #+#             */
/*   Updated: 2023/04/06 17:36:10 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include "libft.h"

static size_t	compare(const char *haystack, const char *needle, size_t index)
{
	size_t	result;
	size_t	j;

	result = 0;
	j = 0;
	while (needle[j])
	{
		if (needle[j] == haystack[index])
			result = 1;
		else
			return (0);
		j++;
		index++;
	}
	return (result);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	haystack_index;
	size_t	find_index;

	haystack_index = 0;
	find_index = 0;
	if (needle[haystack_index] == '\0')
		return ((char *)haystack);
	while (haystack[haystack_index] && haystack_index < len)
	{
		while (needle[find_index])
		{
			if (haystack[haystack_index] == needle[find_index])
			{
				if (compare(haystack, needle, haystack_index))
					return ((char *)&haystack[haystack_index]);
			}
			find_index++;
		}
		find_index = 0;
		haystack_index++;
	}
	return (0);
}

/*int main()
{
	char test1[50] = "LETS TESS";
	char test2[50] = "TES";

	printf("mine:%s\n", ft_strnstr(test1, test2, 3));
	printf("official:%s\n", strnstr(test1, test2, 3));
}*/
