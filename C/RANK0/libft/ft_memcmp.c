/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:36:06 by llopes-d          #+#    #+#             */
/*   Updated: 2023/05/21 21:45:14 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	index;

	index = 0;
	if (n == 0)
		return (0);
	while ((((unsigned char *)s1)[index] == ((unsigned char *)s2)[index])
			&& index < n - 1)
		index++;
	return ((int)(((unsigned char *)s1)[index]
		- ((unsigned char *)s2)[index]));
}

/*int main()
{
	// int t1[5] = {1,2,3,5,4};
	// int t2[5] = {1,2,3,5,5};
	// printf("%d ", ft_memcmp(t1, t2, sizeof(t1)));
	printf("%d ", ft_memcmp("123456", "123457", 10));

	//compare char by char function
	//but differently from strcmp, accepts all array types
}*/
