/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:36:06 by llopes-d          #+#    #+#             */
/*   Updated: 2023/05/21 21:46:08 by llopes-d         ###   ########.fr       */
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
	char *recebe;
	//char array[] = "testes, muitos deles";
	recebe = memchr("testes, muitos deles", 'a', sizeof(array));
	//ft_memchr(array, 2, sizeof(array));
	if (recebe != NULL)
		printf("%s\n",recebe);
	
	//printf("%s ", (char *)ft_memchr(array, 'z', size));

	//search until *size* for the first ocurrence of the 2nd parameter
	//but differently from strchr, accepts all array types
}*/
