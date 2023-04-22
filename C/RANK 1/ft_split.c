/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42lisboa.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:36:06 by llopes-d          #+#    #+#             */
/*   Updated: 2023/04/22 18:35:43 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

static int	count_words(char const *s, char c)
{
	int		index;
	int		word;

	index = 0;
	word = 0;
	while (s[index])
	{
		if ((s[index + 1] == c || s[index + 1] == '\0') && s[index] != c)
			word++;
		index++;
	}
	return (word);
}

static char	*strcpy2(char const *s1, char const *s2, int start, int final)
{
	int		index;
	char	*newstr;

	newstr = (char *)s1;
	index = 0;
	while (start <= final)
	{
		newstr[index] = s2[start];
		start++;
		index++;
	}
	newstr[index] = '\0';
	return (newstr);
}

static char	**allocate_words(char const *s, char c, char	**newstr)
{
	int		index;
	int		start;
	int		word;

	index = 0;
	word = 0;
	while (s[index] == c && s[index])
		index++;
	start = index;
	while (s[index])
	{
		if ((s[index + 1] == c || s[index + 1] == '\0') && s[index] != c)
		{
			newstr[word] = malloc((((index + 1) - start) + 1) * sizeof(char));
			if (newstr == NULL)
				return (NULL);
			newstr[word] = strcpy2(newstr[word], s, start, index++);
			word++;
			while (s[index] == c && s[index])
				index++;
			start = index;
		}
		else
			index++;
	}
	newstr[word] = NULL;
	return (newstr);
}

char	**ft_split(char const *s, char c)
{
	char	**newstr;

	newstr = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (newstr == NULL)
		return (NULL);
	newstr = allocate_words(s, c, newstr);
	return (newstr);
}

/*int main()
{
	int i;
	char **result;

	result = ft_split("^^^12a,^^^^3--h^^^^", '^');
	i = 0;
	while (result[i])
		printf("'%s'\n", result[i++]);
//

	// result = ft_splite("", 'a');

	// res = test_single_split(7, "^^^1^^2a,^^^^3^^^^--h^^^^", '^', expected) && res;
	
}
*/
