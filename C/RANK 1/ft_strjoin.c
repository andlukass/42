/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42lisboa.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:36:06 by llopes-d          #+#    #+#             */
/*   Updated: 2023/04/06 17:36:10 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
// #include <stdio.h>
#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
    char *newstr;
    int index;
    int length1;
    int length2;

    while (s1[length1])
        length1++;
    while (s2[length2])
        length2++;
    newstr = (char*) malloc((length1 + length2) * sizeof(char));
    if (newstr == NULL)
        return (NULL);
    index = 0;
    length1 = 0;
    while (s1[length1])
    {
        printf("kkk");
        newstr[length1] = s1[length1];
        length1++;
    }
    while (s2[index])
    {
        newstr[length1] = s2[index];
        index++;
        length1++;
    }
    return (newstr);
}

/*int main()
{
   printf("\nRESULTADO: %s", ft_strjoin("teste ai seu vacilao", "kkkk"));
}*/