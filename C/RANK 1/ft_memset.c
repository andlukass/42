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
// #include <stdio.h>
#include "libft.h"

void *ft_memset(void *b, int c, size_t len)
{
	size_t index;

	index = 0;
	while (index < len)
	{
		((char *)b)[index] = ((char)c);
		index++;
	}
	return (b);
}

/*int main()
{
	int array[5];
	ft_memset(array, 'x', sizeof(array));
	// memset(array, 'x', sizeof(array));
	for (int i = 0; i < 5; i++)
		printf("%d ", array[i]);
	// printf("%s ", array);
}*/
