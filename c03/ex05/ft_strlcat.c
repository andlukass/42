/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
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

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	index;
	unsigned int	dest_length;
	unsigned int	src_length;

	index = 0;
	dest_length = get_length(dest);
	src_length = get_length(src);
	if (size <= dest_length)
	{
		return (src_length + size);
	}
	while (src[index] != '\0' && (index < size - dest_length - 1))
	{
		dest[index + dest_length] = src[index];
		index++;
	}
	dest[index + dest_length] = '\0';
	return (src_length + dest_length);
}

/*int	main()
{
	char dest[] = "HEY TEST IT THERE";
	char src[5] = "12345";


	printf("%u\n", ft_strlcat(dest, src, 14));
	printf("%s\n", dest);
}*/