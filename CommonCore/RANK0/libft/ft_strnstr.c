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

#include <stdio.h>
#include "libft.h"

static size_t	compare(const char *big, const char *little, size_t index,
					size_t len)
{
	size_t	result;
	size_t	j;

	result = 0;
	j = 0;
	while (little[j])
	{
		if (little[j] == big[index])
			result = 1;
		else
			return (0);
		if (index > (len - 1))
			return (0);
		j++;
		index++;
	}
	return (result);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	big_index;
	size_t	little_index;

	big_index = 0;
	little_index = 0;
	if (little[big_index] == '\0')
		return ((char *)big);
	if (len == 0)
		return (0);
	while (big[big_index] && big_index < len)
	{
		while (little[little_index])
		{
			if (big[big_index] == little[little_index])
			{
				if (compare(big, little, big_index, len))
					return ((char *)&big[big_index]);
			}
			little_index++;
		}
		little_index = 0;
		big_index++;
	}
	return (0);
}
/*
int main()
{
	char test1[50] = "LETS TESS";
	char test2[50] = "TESS";

	printf("mine:%s\n", ft_strnstr("aaabcabcd", "a", 1));
	printf("official:%s\n", strnstr("aaabcabcd", "a", 1));
	//search a string inside another string
	// VER DEPOIS POR QUE O DE CIMA TEM  -1 E O DE BAIXO NAO
}*/
