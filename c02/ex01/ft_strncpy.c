/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 20:56:19 by llopes-d          #+#    #+#             */
/*   Updated: 2023/03/07 20:56:21 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	int index;

	index = 0;
	while (index < n && src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
		//printf("%s\n", dest);
	}
	
	while(index < n)
	{
		dest[index] = '\0';
		index++;
	}
	
	return (dest);
}

int	main()
{
	char string[] = "abcdef";
	char receber[20];
	int n = 6;

	ft_strncpy(receber, string, n);

	printf("%s\n", receber);
}
