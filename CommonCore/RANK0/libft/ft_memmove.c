/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:36:06 by llopes-d          #+#    #+#             */
/*   Updated: 2023/05/21 21:45:55 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	index;

	index = -1;
	if (!src && !dest)
		return (NULL);
	if (dest > src)
		while (n-- > 0)
			((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
	else
		while (++index < n)
			((unsigned char *)dest)[index] = ((unsigned char *)src)[index];
	return (dest);
}

/*int main()
{
	// int teste2;
	// int teste;

	// printf("%lu\n", (long int)&teste);
	// printf("%lu\n", (long int)&teste2);


	//int array[5] = {1,1,1,1,1};
	char array1[] = "0123456789";
   	char array2[] = "0123456789";
	char teste[] = "array2";
	// memmove(((void*)0), ((void*)0), 5);
	ft_memmove(array2, teste, 6);

	// // for (int i = 0; i < 5; i++)
	// // printf("%d ", array[i]);
	printf("moveft: %s\n", array2);
	// printf("movenr: %s\n", array1);
}*/
