/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42lisboa.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 20:32:51 by llopes-d          #+#    #+#             */
/*   Updated: 2023/03/07 20:33:07 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*#include <stdio.h>*/

int	ft_str_is_numeric(char *str)
{
	int	index;
	int	result;

	result = 1;
	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] >= 48 && str[index] <= 57)
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
	char teste[20] = "1dasd20";
	printf("%d\n",ft_str_is_numeric(teste));
}*/
