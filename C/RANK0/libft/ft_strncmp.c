/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:36:06 by llopes-d          #+#    #+#             */
/*   Updated: 2023/05/21 17:59:39 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((i < n - 1) && (s1[i] || s2[i]) && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*int	main()
{
	char test1[50] = "abcdef";
	char test2[50] = "abc\375xx";

	//printf("%d\n", ft_strncmp(test1, test2, 5));
	//printf("%d\n", strncmp(test1, test2, 5));



	//printf("CARACTER 1: %c\n CARACTER 2: %c\n", s1[i] ,s2[i]);
	//SE A PRIMEIRA FOIR MAIOR E POSITIVO
	//SE A SEGUNDA FOR MAIOR E NEGATIVO
	//compare char by char function
}*/
