/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:53:59 by llopes-d          #+#    #+#             */
/*   Updated: 2023/03/13 14:54:03 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((i < n - 1) && (s1[i] && s2[i]) && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

/*int	main()
{
	char test1[50] = "add";
	char test2[50] = "add ";

	printf("%d\n", ft_strncmp(test1, test2, 10));
	printf("%d\n", strncmp(test1, test2, 10));


	//SE A PRIMEIRA FOIR MAIOR E POSITIVO
	//SE A SEGUNDA FOR MAIOR E NEGATIVO
}*/
