/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42lisboa.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:36:06 by llopes-d          #+#    #+#             */
/*   Updated: 2023/04/06 17:36:10 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 #include <stdio.h>
#include "libft.h"

void *ft_calloc(size_t nmemb, size_t size)
{
  void	*final;
  int index;

    index = 0;
  final = (void*)malloc(nmemb * size);
  if (final == NULL)
		return (NULL);
    	while (index < nmemb)
	{
		((unsigned char *)final)[index] = 0;
		index++;
	}
    return (final);
}

int main() {
    int *array;
    int size = 5;
    int i;

    // aloca um array de inteiros com 10 elementos e inicializa com zeros
    array = (int*) ft_calloc(size, sizeof(int));

    // verifica se a alocação foi bem sucedida
    if (array == NULL) {
        printf("Erro ao alocar memoria!");
        return 1;
    }

    // exibe os valores do array
    printf("Valores do array apos a inicializacao:\n");
    for (i = 0; i < size; i++) {
        printf("%d\n", array[i]);
    }

    // libera a memoria alocada
    free(array);

    return 0;
}
