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

int	is_end_or_equal(char a, char b)
{
	int	result;

	result = 0;
	if ((a != '\0' || b != '\0') && (a == b))
	{
		result = 1;
	}
	return (result);
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	index;

	index = 0;
	while (is_end_or_equal(s1[index], s2[index]) && (index < n))
	{
		index++;
	}
	return (s1[index] - s2[index]);
}

/*int	main()
{
	char test1[50] = "acd'";
	char test2[50] = "add ";

	printf("%d\n", ft_strncmp(test1, test2, 0));


	//SE A PRIMEIRA FOIR MAIOR E POSITIVO
	//SE A SEGUNDA FOR MAIOR E NEGATIVO
}*/
