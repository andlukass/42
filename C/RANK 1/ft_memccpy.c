/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42lisboa.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:36:06 by llopes-d          #+#    #+#             */
/*   Updated: 2023/04/06 17:36:10 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "libft.h"

void *ft_memccpy(void *restrict dst, const void *restrict src, int c, size_t n)
{
    size_t index;

    index = 0;
    while (index < n && (((char *)src)[index] != ((unsigned char)c)))
    {
        ((char *)dst)[index] = ((char *)src)[index];
        index++;
    }
    if (((char *)src)[index] == ((unsigned char)c))
        return (((void *)dst)[index]);
    return (NULL);
}

int main()
{
    char array[5];
    // ft_memccpy(array, "12345", sizeof(array));

    // for (int i = 0; i < 5; i++)
    //     printf("%d ", array[i]);
    printf("%s ", (char *)ft_memccpy(array, "12345", '2', sizeof(array)));
}
