/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42lisboa.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:36:06 by llopes-d          #+#    #+#             */
/*   Updated: 2023/04/06 17:36:10 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
// #include <stdio.h>
#include "libft.h"

void ft_bzero(void *s, size_t n)
{
	int index;

	index = 0;
	while (index < n)
	{
		((char *)s)[index] = 0;
		index++;
	}
}

/*int main()
{
	char array[5];
	ft_bzero(array, sizeof(array));
	//for (int i = 0; i < 5; i++)
	//	printf("%d ", array[i]);
	printf("%s ", array);
}*/
