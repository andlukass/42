/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 21:45:19 by llopes-d          #+#    #+#             */
/*   Updated: 2023/06/18 15:19:20 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

int	ft_strlen(const char *s)
{
	int	index;

	index = 0;
	while ((s[index] != '\0'))
		index++;
	return (index);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*newstr;
	int		index;
	int		length;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	newstr = (char *) malloc(((ft_strlen(s1) + ft_strlen(s2)) + 1)
			* sizeof(char));
	if (newstr == NULL)
		return (NULL);
	index = 0;
	length = -1;
	while (s1[++length])
		newstr[length] = s1[length];
	while (s2[index])
		newstr[length++] = s2[index++];
	free(s1);
	newstr[length] = '\0';
	return (newstr);
}

void	*ft_bzero(char *s, size_t n)
{
	size_t	index;

	if (!s[0])
		return (NULL);
	index = 0;
	while (index < n)
		s[index++] = '\0';
	return (NULL);
}
