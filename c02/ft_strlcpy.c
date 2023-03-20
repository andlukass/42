/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42lisboa.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 20:32:51 by llopes-d          #+#    #+#             */
/*   Updated: 2023/03/07 20:33:07 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	get_length(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		index++;
	}
	return (index);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	index;
	unsigned int	length;

	length = get_length(src);
	index = 0;
	if (size != '\0')
	{
		while (src[index] != 0 && index < (size - 1))
		{
			dest[index] = src[index];
			index++;
		}
		dest[index] = '\0';
	}
	return (length);
}

/*int main()
{
	char test[] = "LETS TEST TOHGUETEER";
	char test2[25];
	printf("%d\n",ft_strlcpy(test2,test,25));
	printf("%s\n",test2);
}*/
