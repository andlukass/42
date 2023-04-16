/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-dstudent.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:36:06 by llopes-d          #+#    #+#             */
/*   Updated: 2023/04/06 17:36:10 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include "libft.h"

char	*ft_strdup(char const *s1)
{
	char	*duplicate;
	int		index;
	int		length;

	index = 0;
	length = 0;
	while (s1[length])
		length++;
	duplicate = malloc(sizeof(char) * length);
	if (duplicate == 0)
		return (0);
	while (s1[index])
	{
		duplicate[index] = s1[index];
		index++;
	}
	duplicate[index] = '\0';
	return (duplicate);
}

/*int main()
{
	char test[] = "AAAAH";
	printf("%s", ft_strdup(test));
}*/