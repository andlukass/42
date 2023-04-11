/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42lisboa.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:36:06 by llopes-d          #+#    #+#             */
/*   Updated: 2023/04/06 17:36:10 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
// #include <stdio.h>
#include "libft.h"

void *ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
    size_t index;

    index = 0;
    while (index < n)
    {
        ((char *)dst)[index] = ((char *)src)[index];
        index++;
    }
    return (dst);
}

/*int main()
{
    char array[5];
    // ft_memcpy(array, "12345", sizeof(array));
    memcpy(array, "12345", sizeof(array));
    // for (int i = 0; i < 5; i++)
    //     printf("%d ", array[i]);
    printf("%s ", array);
}*/
