/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:36:06 by llopes-d          #+#    #+#             */
/*   Updated: 2023/04/06 17:36:10 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
// #include <stdio.h>
#include "libft.h"

size_t ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t index;
	size_t dst_length;
	size_t src_length;

	index = 0;
	dst_length = 0;
	src_length = 0;
	while (dst[dst_length] != '\0')
		dst_length++;
	while (src[src_length] != '\0')
		src_length++;
	if (dstsize <= dst_length)
		return (src_length + dstsize);
	while (src[index] != '\0' && (index < dstsize - dst_length - 1))
	{
		dst[index + dst_length] = src[index];
		index++;
	}
	dst[index + dst_length] = '\0';
	return (src_length + dst_length);
}

/*int main()
{
	char dst[] = "HEY TEST IT THERE";
	char src[] = "12345";

	printf("%zu\n", ft_strlcat(dst, src, 7));
	printf("%s\n", dst);
	printf("%s\n", src);
}
*/