/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:36:06 by llopes-d          #+#    #+#             */
/*   Updated: 2023/05/21 13:59:00 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*final;
	size_t	index;

	index = 0;
	final = malloc(nmemb * size);
	if (final == NULL)
		return (NULL);
	while (index < (nmemb * size))
		((unsigned char *)final)[index++] = 0;
	return (final);
}

/*int main() {
	char *array;
    int size = 5;
    int i;

    array = (char*) ft_calloc(size, sizeof(char));
    printf("%s\n", array);
    // for (i = 0; i < size; i++) {
    //     printf("%d\n", array[i]);
    // }

	//allocate memory and after fill with 0
}*/
