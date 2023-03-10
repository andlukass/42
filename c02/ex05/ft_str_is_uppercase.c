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
/*#include <stdio.h>*/

int	ft_str_is_uppercase(char *str)
{
	int	index;
	int	result;

	result = 1;
	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] >= 65 && str[index] <= 90)
		{
			result = 1;
		}
		else
		{
			return (0);
		}
		index++;
	}
	return (result);
}

/*int main()
{
	char teste[20] = "AAAAZZZ";
	printf("%d\n",ft_str_is_uppercase(teste));
}*/
