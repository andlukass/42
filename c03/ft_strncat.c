/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:53:59 by llopes-d          #+#    #+#             */
/*   Updated: 2023/03/14 14:54:03 by llopes-d         ###   ########.fr       */
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

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	index;
	unsigned int	length;

	index = 0;
	length = get_length(dest);
	while (src[index] != '\0' && index < nb)
	{
		dest[index + length] = src[index];
		index++;
	}
	dest[index + length] = '\0';
	return (dest);
}

/*int	main()
{
	char test1[50] = "add'te\nst";
	char test2[50] = " add haha";

	printf("%s\n", ft_strncat(test1, test2, 4));


}*/
