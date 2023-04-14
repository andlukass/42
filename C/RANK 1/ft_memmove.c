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
#include <stdio.h>
#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t n)
{
	size_t index;

	index = 0;
	n = n - 1;
	if (dest > src)
	{
		while (n >= 0)
		{
			((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
			 if (n == 0)
                break;
			n--;
		}
	}
	else
	{
		while (index < n)
		{
			((unsigned char *)dest)[index] = ((unsigned char *)src)[index];
			index++;
		}
	}
	return (dest);
}


int main()
{
	//int array[5] = {1,1,1,1,1};
	char array1[] = "0123456789";
   	char array2[] = "0123456789";
	char teste[] = "array2";
	memmove(array1, teste, 6);
	ft_memmove(array2, teste, 6);


	// for (int i = 0; i < 5; i++)
	// printf("%d ", array[i]);
	printf("moveft: %s\n", array2);
	printf("movenr: %s\n", array1);
}