/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42lisboa.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:36:06 by llopes-d          #+#    #+#             */
/*   Updated: 2023/04/06 17:36:10 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	index;

	index = 0;
	while (index < n)
	{
		if (((unsigned char *)s)[index] == (unsigned char)c)
			return ((void *)&s[index]);
		index++;
	}
	return (NULL);
}

/*int main()
{
	int array[5] = {2,8,1,5,5};
	int *recebe;
	//char array[] = "testaa ai vacilones";
	recebe = memchr(array, 90, sizeof(array));
	//ft_memchr(array, 2, sizeof(array));
	if (recebe != NULL)
		printf("nao e null");
	
	//printf("%s ", (char *)ft_memchr(array, 'z', size));

	//com inteiro so testa se encontrou, com de char conseguimos imprimos 
	//o restante da string a partir da primeira aparicao.
}*/