/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42lisboa.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 20:32:51 by llopes-d          #+#    #+#             */
/*   Updated: 2023/03/07 20:33:07 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*#include <stdio.h>*/

int	ft_str_is_alpha(char *str)
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
		else if (str[index] >= 97 && str[index] <= 122)
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
	char test[20] = "test hahah";
	printf("%d\n",ft_str_is_alpha(test));
}*/
