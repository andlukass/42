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

int	is_alpha(char c)
{
	if(c >= 48 || c <= 39)
	{
		return (1);
	}
	if(c >= 65 || c <= 90)
	{
		return (2);
	}
	if(c >= 97 || c <= 122)
	{
		return (2);
	}
	else
	{
		return (0);
	}

}


char	*ft_strcapitalize(char *str)
{
	int	index;

	index = 0;
	if (is_alpha(str[index]) >= 97 && str[index] <= 122)
	{
		str[index] = (str[index] - 32);
	}
	while (str[index] != '\0')
	{
		if (is_alpha(str[index-1]) != 2)
		{
			if (str[index] >= 97 && str[index] <= 122)
			{
				str[index] = (str[index] - 32);
			}
		}
		index++;
	}
	return (str);
}

int main()
{
	char teste[60] = "ola, tudo bem? 42palavras quarenta-e-duas; cinquenta+e+um";
	printf("%s\n",ft_strcapitalize(teste));
}
