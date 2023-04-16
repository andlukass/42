/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42lisboa.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:36:06 by llopes-d          #+#    #+#             */
/*   Updated: 2023/04/06 17:36:10 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	index;

	index = 0;
	while (index < len)
		((unsigned char *)b)[index++] = (unsigned char)c;
	return (b);
}

/*int main()
{
	//int array[5] = {1,1,1,1,1};
	char array[5];

	ft_memset(array, 'Z', sizeof(array));
	//memset(array, 2, sizeof(array));
	for (int i = 0; i < 5; i++)
		printf("%d ", array[i]);
	
	//printf("%s ", array);

	//fill an array of any type with some number/char until the size(len)
}*/