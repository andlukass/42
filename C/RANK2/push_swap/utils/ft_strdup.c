/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 21:08:43 by user              #+#    #+#             */
/*   Updated: 2023/08/25 11:33:08 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char const *s1, int size)
{
	char	*duplicate;
	int		index;
	int		length;

	index = 0;
	length = 0;
	duplicate = malloc(sizeof(char) * (size + 1));
	if (duplicate == 0)
		return (0);
	while (index < size)
	{
		duplicate[index] = s1[index];
		index++;
	}
	duplicate[index] = '\0';
	return (duplicate);
}