/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-dstudent.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 18:31:47 by jpimente          #+#    #+#             */
/*   Updated: 2023/03/22 19:27:33 by jpimente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		index++;
	}
	return (index);
}

char	*ft_strdup(char *src)
{
	char	*duplicate;
	int		index;

	index = 0;
	duplicate = malloc(sizeof(char) * ft_strlen(src));
	if (duplicate == 0)
	{
		return (0);
	}
	while (src[index])
	{
		duplicate[index] = src[index];
		index++;
	}
	duplicate[index] = '\0';
	return (duplicate);
}

int	main()
{	
    char test[] = "AAAAH";
	 printf("%s",ft_strdup(test));
}