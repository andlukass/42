/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 20:33:39 by llopes-d          #+#    #+#             */
/*   Updated: 2023/03/08 20:33:52 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
{
	int	i;

	i = 0;
	if (str[i] >= 97 && str[i] <= 122)
	{
		str[i] = (str[i] - 32);
	}
	while (str[i] != '\0')
	{
		if (str[i - 1] >= 32 && str[i - 1] <= 47)
		{
			if (str[i] >= 97 && str[i] <= 122)
			{
				str[i] = (str[i] - 32);
			}
		}
		i++;
	}
	return (str);
}

int main()
{
	char teste[60] = "ola, tudo beM? 42palavras quarenta-e-duas; cinquenta+e+um";
	printf("%s\n",ft_strlcpy(teste));
}
