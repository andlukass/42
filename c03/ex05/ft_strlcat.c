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
#include <string.h>

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

size_t strlcat(char *dst, const char *src, size_t dstsize) {
    size_t srclen, dstlen, i;

    srclen = strlen(src);
    dstlen = strlen(dst);

    if (dstsize <= dstlen)
        return dstsize + srclen;

    for (i = 0; i < dstsize - dstlen - 1 && src[i] != '\0'; i++)
        dst[dstlen + i] = src[i];
    dst[dstlen + i] = '\0';

    return dstlen + srclen;
}


// unsigned int ft_strlcat(char *dest, char *src, unsigned int size)
// {
// 	unsigned int	index;
// 	unsigned int	length;

// 	index = 0;
// 	length = get_length(dest);
// 	while (src[index] != '\0' && index < size)
// 	{
// 		dest[index + length] = src[index];
// 		index++;
// 	}
// 	return (dest);
// }

int	main()
{
	char test1[] = "chupa porco imundo";
	char test2[6] = "12345";


	printf("%zu\n", strlcat(test1, test2, 11));
}