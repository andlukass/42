/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:36:06 by llopes-d          #+#    #+#             */
/*   Updated: 2023/04/06 17:36:10 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
// #include <stdio.h>

int ft_strcmp(const char *s1, const char *s2)
{
	int index;

	index = 0;
	while (s1[index] == s2[index] && (s1[index] != '\0' || s2[index] != '\0'))
		index++;
	return (s1[index] - s2[index]);
}

/*int	main()
{
	char test1[50] = "!adabb!d";
	char test2[50] = "!adabb!e";

	//printf("%d\n", strcmp(test1, test2));
	printf("%d\n", ft_strcmp(test1, test2));


	//SE A PRIMEIRA FOIR MAIOR E POSITIVO
	//SE A SEGUNDA FOR MAIOR E NEGATIVO
}*/
