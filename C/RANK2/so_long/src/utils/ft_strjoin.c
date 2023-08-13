/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 21:07:11 by user              #+#    #+#             */
/*   Updated: 2023/07/27 13:39:07 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
