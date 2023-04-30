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

#include <stdio.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	index;
	size_t	size;
	char	*newstr;

	size = 0;
	while (s[size])
		size++;
	if (size < start)
	{
		newstr = malloc(sizeof(char));
		newstr[0] = '\0';
		return (newstr);
	}
	size = size - start;
	if (size < len)
		len = size;
	newstr = (char *)malloc((len + 1) * sizeof(char));
	if (newstr == 0)
		return (0);
	index = -1;
	while (++index < len)
		newstr[index] = s[start + index];
	newstr[index] = '\0';
	return (newstr);
}

/*int main()
{
   printf("\nRESULTADO: %s", ft_substr("teste ai seu vacilao", 5, 32));

1 - SE O TAMANHO DA STRING E MENOR QUE O NUMERO PASSADO COMO 
INICIO RETORNA UMA STRING ALOCADA VAZIA

2 - DEPOIS DE FAZER ESSA COMPARACAO PASSAMOS A CONTAR O 
TAMANHO APARTIR DO START

3 - CASO O TAMANHO DA STRING SEJA MENOR QUE O LEN, PASSAMOS A 
CONSIDERAR O TAMANHO DA STRING COMO LEN(EVITANDO CORE DUMP)

4 - ALOCAMOS MEMORIA COM NOSSO NOVO TAMANHO

5  - FAZEMOS UMA COPIA PADRAO

}*/
