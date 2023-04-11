/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:36:06 by llopes-d          #+#    #+#             */
/*   Updated: 2023/04/06 17:36:10 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
// #include <stdio.h>

static int compare(const char *haystack, const char *needle, int index)
{
	int result;
	int j;

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

char *ft_strstr(const char *haystack, const char *needle)
{
	int haystack_index;
	int find_index;

	haystack_index = 0;
	find_index = 0;
	if (needle[haystack_index] == '\0')
		return ((char *)haystack);
	while (haystack[haystack_index] != '\0')
	{
		while (needle[find_index] != '\0')
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
	char test2[50] = "";

	printf("%s\n", ft_strstr(test1, test2));
}*/
