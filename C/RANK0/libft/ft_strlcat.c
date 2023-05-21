/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:36:06 by llopes-d          #+#    #+#             */
/*   Updated: 2023/05/21 13:34:53 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	index;
	size_t	dst_length;
	size_t	src_length;

	index = 0;
	dst_length = 0;
	src_length = 0;
	while (dst[dst_length])
		dst_length++;
	while (src[src_length])
		src_length++;
	if (dstsize <= dst_length)
		return (src_length + dstsize);
	while (src[index] && (index < ((dstsize - dst_length) - 1)))
	{
		dst[index + dst_length] = src[index];
		index++;
	}
	dst[index + dst_length] = '\0';
	return (src_length + dst_length);
}

/*int main()
{
	char dst[50] = "HEY TEST IT THERE";
	char src[] = "12345";

	printf("%zu\n", ft_strlcat(dst, src, 21));
//	printf("%d\n", strlcat(dst, src, 21));
	printf("%s\n", dst);
}*/
