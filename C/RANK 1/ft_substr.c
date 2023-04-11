/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42lisboa.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:36:06 by llopes-d          #+#    #+#             */
/*   Updated: 2023/04/06 17:36:10 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
// #include <stdio.h>
#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *newstr;
    int index;

    newstr = (char*) malloc(len * sizeof(char));
    if (newstr == NULL)
        return (NULL);
    index = 0;
    if (start > len)
        return (NULL);
    while ((start < len) && s[start])
    {
        newstr[index] = s[start];
        start++;
        index++;
    }
    newstr[index] = '\0';
    return (newstr);
}

/*int main()
{
   printf("\nRESULTADO: %s", ft_substr("teste ai seu vacilao", 5, 32));
}*/

