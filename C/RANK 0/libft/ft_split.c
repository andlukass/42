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

//#include <stdio.h>
#include "libft.h"

static char	**fill_array(char const *s, char c, char **newstr)
{
	size_t	index;
	size_t	start;
	size_t	word;

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
			ft_strlcpy(newstr[word++], s + start, ((index++ + 2) - start));
			while (s[index] == c && s[index])
				start = ++index;
		}
		else
			index++;
	}
	return (newstr);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		index;
	int		words;

	index = -1;
	words = 0;
	while (s[++index])
		if ((s[index + 1] == c || s[index + 1] == '\0') && s[index] != c)
			words++;
	array = malloc((words + 1) * sizeof(char *));
	if (array == NULL)
		return (NULL);
	array = fill_array(s, c, array);
	array[words] = NULL;
	return (array);
}

/*int main()
{
	int i;
	char **result;

	result = ft_split("^^^12a,^^^^3--h^^^^", '^');
	i = 0;
	while (result[i])
		printf("'%s'\n", result[i++]);
	//split a string based on the char passed as argument
}*/
