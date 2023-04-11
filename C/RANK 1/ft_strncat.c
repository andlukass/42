/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:36:06 by llopes-d          #+#    #+#             */
/*   Updated: 2023/04/06 17:36:10 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
// #include <stdio.h>
#include "libft.h"

char *ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	size_t index;
	size_t length;

	index = 0;
	length = 0;
	while (s1[length] != '\0')
		length++;
	while (s2[index] != '\0' && index < n)
	{
		s1[index + length] = s2[index];
		index++;
	}
	s1[index + length] = '\0';
	return (s1);
}

/*int	main()
{
	char test1[50] = "add'te\nst";
	char test2[50] = " add haha";

	printf("%s\n", ft_strncat(test1, test2, 4));


}*/
