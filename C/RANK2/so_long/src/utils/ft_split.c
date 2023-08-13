/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 21:07:00 by user              #+#    #+#             */
/*   Updated: 2023/07/27 13:38:55 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	index;
	size_t	length;

	index = 0;
	length = 0;
	while (src[length])
		length++;
	if (size <= 0)
		return (length);
	while (src[index] && index < (size - 1))
	{
		dst[index] = src[index];
		index++;
	}
	dst[index] = '\0';
	return (length);
}

static char	*free_full_array(char **array, int pos)
{
	if (array[pos] == NULL)
	{
		while (pos > 0)
			free(array[--pos]);
		free(array);
		return (NULL);
	}
	return ("true");
}

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
			newstr[word] = malloc(((++index - start) + 1) * sizeof(char));
			if (free_full_array(newstr, word) == NULL)
				return (NULL);
			ft_strlcpy(newstr[word++], s + start, (index - start) + 1);
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
	if (array == NULL)
		return (NULL);
	array[words] = NULL;
	return (array);
}
